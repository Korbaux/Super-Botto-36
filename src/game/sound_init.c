#include <ultra64.h>
#include "area.h"
#include "audio/external.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "level_table.h"
#include "level_update.h"
#include "main.h"
#include "paintings.h"
#include "print.h"
#include "save_file.h"
#include "seq_ids.h"
#include "sm64.h"
#include "sound_init.h"
#include "rumble_init.h"
#include "puppyprint.h"
#include "profiling.h"

#define MUSIC_NONE 0xFFFF

static OSMesgQueue sSoundMesgQueue;
static OSMesg sSoundMesgBuf[1];
static struct VblankHandler sSoundVblankHandler;

// Only written to, never read.
static u8 sMusicVolume = 0;

static u8 sBgMusicDisabled = FALSE;
static u16 sCurrentMusic = MUSIC_NONE;
static u16 sCurrentShellMusic = MUSIC_NONE;
static u16 sCurrentCapMusic = MUSIC_NONE;
#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
static u8 sPlayingInfiniteStairs = FALSE;
#endif
static s16 sSoundMenuModeToSoundMode[] = { SOUND_MODE_STEREO, SOUND_MODE_MONO, SOUND_MODE_HEADSET };
// Only the 20th array element is used.
static u32 sMenuSoundsExtra[] = {
    SOUND_MOVING_TERRAIN_SLIDE + (0 << 16),
    SOUND_MOVING_TERRAIN_SLIDE + (1 << 16),
    SOUND_MOVING_TERRAIN_SLIDE + (2 << 16),
    SOUND_MOVING_TERRAIN_SLIDE + (3 << 16),
    SOUND_MOVING_TERRAIN_SLIDE + (4 << 16),
    SOUND_MOVING_TERRAIN_SLIDE + (5 << 16),
    SOUND_MOVING_TERRAIN_SLIDE + (6 << 16),
    SOUND_MOVING_LAVA_BURN,
    SOUND_MOVING_SLIDE_DOWN_TREE,
    SOUND_MOVING_SLIDE_DOWN_POLE,
    SOUND_MOVING_QUICKSAND_DEATH,
    SOUND_MOVING_TERRAIN_RIDING_SHELL,
    NO_SOUND,
    SOUND_ENV_BOAT_ROCKING1,
    SOUND_ENV_ELEVATOR3,
    SOUND_ENV_BOWLING_BALL_ROLL,
    SOUND_ENV_WATERFALL1,
    SOUND_ENV_WATERFALL2,
    SOUND_ENV_ELEVATOR1,
    SOUND_ENV_DRONING1,
    SOUND_ENV_DRONING2,
    SOUND_ENV_ELEVATOR2,
    SOUND_ENV_WIND1,
    SOUND_ENV_WATER,
    SOUND_AIR_BOWSER_SPIT_FIRE,
    SOUND_MOVING_AIM_CANNON,
    SOUND_AIR_LAKITU_FLY,
    SOUND_AIR_AMP_BUZZ,
    SOUND_AIR_CASTLE_OUTDOORS_AMBIENT,
    SOUND_OBJ2_BIRD_CHIRP1,
    SOUND_GENERAL2_BIRD_CHIRP2,
    SOUND_OBJ_BIRD_CHIRP3,
    SOUND_ENV_ELEVATOR2,
    SOUND_AIR_BLOW_WIND,
    SOUND_AIR_BLOW_FIRE,
    SOUND_ENV_ELEVATOR4,
};
static s8 sPaintingEjectSoundPlayed = FALSE;

void play_menu_sounds_extra(s32 a, void *b);

/**
 * Called from threads: thread5_game_loop
 */
void reset_volume(void) {
    sMusicVolume = 0;
}

/**
 * Called from threads: thread5_game_loop
 */
void lower_background_noise(s32 a) {
    switch (a) {
        case 1:
            set_audio_muted(TRUE);
            break;
        case 2:
            seq_player_lower_volume(SEQ_PLAYER_LEVEL, 60, 40);
            break;
    }
    sMusicVolume |= a;
}

/**
 * Called from threads: thread5_game_loop
 */
void raise_background_noise(s32 a) {
    switch (a) {
        case 1:
            set_audio_muted(FALSE);
            break;
        case 2:
            seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
            break;
    }
    sMusicVolume &= ~a;
}

/**
 * Called from threads: thread5_game_loop
 */
void disable_background_sound(void) {
    if (sBgMusicDisabled == FALSE) {
        sBgMusicDisabled = TRUE;
        sound_banks_disable(SEQ_PLAYER_SFX, SOUND_BANKS_BACKGROUND);
    }
}

/*
 * HAS TO BE UPDATED EVERY TIME A NEW SEQUENCE IS ADDED
 */
const char* seqNames[SEQ_COUNT] = {
	// probably a really dumb solution to have a bunch of null strings for ones that shouldn't be displayed but whatever
	"d", // SEQ_SOUND_PLAYER,                 // 0x00
	"", // SEQ_EVENT_CUTSCENE_COLLECT_STAR,  // 0x01
	"", // SEQ_MENU_TITLE_SCREEN,            // 0x02
	"Main Menu (Hotel Mario)", // SEQ_LEVEL_GRASS, // 0x03
	"Save Hut (Kirby Super Star)", // SEQ_LEVEL_INSIDE_CASTLE, // 0x04
	"Trance Logic", // SEQ_LEVEL_WATER,      // 0x05
	"DX3A108.A", // SEQ_LEVEL_HOT,           // 0x06
	"", // SEQ_LEVEL_BOSS_KOOPA,             // 0x07
	"please dont wake me up", // SEQ_LEVEL_SNOW,                   // 0x08
	"Mr. Brightside", // SEQ_LEVEL_SLIDE,    // 0x09
	"Moonlight Sonata (1st Movement)", // SEQ_LEVEL_SPOOKY, // 0x0A
	"", // SEQ_EVENT_PIRANHA_PLANT,          // 0x0B
	"hypnopompicrat", // SEQ_LEVEL_UNDERGROUND, // 0x0C
	"", // SEQ_MENU_STAR_SELECT,             // 0x0D
	"PepsiMan", // SEQ_EVENT_POWERUP,        // 0x0E
	"Targets! (SSBM)", // SEQ_EVENT_METAL_CAP, // 0x0F
	"", // SEQ_EVENT_KOOPA_MESSAGE,          // 0x10
	"", // SEQ_LEVEL_KOOPA_ROAD,             // 0x11
	"", // SEQ_EVENT_HIGH_SCORE,             // 0x12
	"", // SEQ_EVENT_MERRY_GO_ROUND,         // 0x13
	"", // SEQ_EVENT_RACE,                   // 0x14
	"", // SEQ_EVENT_CUTSCENE_STAR_SPAWN,    // 0x15
	"Intruder Alert", // SEQ_EVENT_BOSS,     // 0x16
	"", // SEQ_EVENT_CUTSCENE_COLLECT_KEY,   // 0x17
	"", // SEQ_EVENT_ENDLESS_STAIRS,         // 0x18
	"", // SEQ_LEVEL_BOSS_KOOPA_FINAL,       // 0x19
	"Scatman's World, BHIYS", // SEQ_EVENT_CUTSCENE_CREDITS, // 0x1A
	"", // SEQ_EVENT_SOLVE_PUZZLE,           // 0x1B
	"", // SEQ_EVENT_TOAD_MESSAGE,           // 0x1C
	"", // SEQ_EVENT_PEACH_MESSAGE,          // 0x1D
	"", // SEQ_EVENT_CUTSCENE_INTRO,         // 0x1E
	"", // SEQ_EVENT_CUTSCENE_VICTORY,       // 0x1F
	"", // SEQ_EVENT_CUTSCENE_ENDING,        // 0x20
	"Two Trucks", // SEQ_MENU_FILE_SELECT,   // 0x21
	"", // SEQ_EVENT_CUTSCENE_LAKITU,        // 0x22 (not in JP)
    "thepresentisdreadfullyperpetual", // SEQ_LEVEL_DESERT, // 0x23
};

const char* seqAuthors[SEQ_COUNT] = {
	// probably a really dumb solution to have a bunch of null strings for ones that shouldn't be displayed but whatever
	"the_pau", // SEQ_SOUND_PLAYER,                 // 0x00
	"", // SEQ_EVENT_CUTSCENE_COLLECT_STAR,  // 0x01
	"", // SEQ_MENU_TITLE_SCREEN,            // 0x02
	"Max Steiner", // SEQ_LEVEL_GRASS,       // 0x03
	"Exact Person Unknown", // SEQ_LEVEL_INSIDE_CASTLE, // 0x04
	"who cares", // SEQ_LEVEL_WATER,         // 0x05
	"the_pau", // SEQ_LEVEL_HOT,             // 0x06
	"", // SEQ_LEVEL_BOSS_KOOPA,             // 0x07
	"the_pau", // SEQ_LEVEL_SNOW,            // 0x08
	"The Killers", // SEQ_LEVEL_SLIDE,       // 0x09
	"Beethoven", // SEQ_LEVEL_SPOOKY,        // 0x0A
	"", // SEQ_EVENT_PIRANHA_PLANT,          // 0x0B
	"the_pau", // SEQ_LEVEL_UNDERGROUND,     // 0x0C
	"", // SEQ_MENU_STAR_SELECT,             // 0x0D
	"Pepsi", // SEQ_EVENT_POWERUP,           // 0x0E
	"Nintendo", // SEQ_EVENT_METAL_CAP,      // 0x0F
	"", // SEQ_EVENT_KOOPA_MESSAGE,          // 0x10
	"", // SEQ_LEVEL_KOOPA_ROAD,             // 0x11
	"", // SEQ_EVENT_HIGH_SCORE,             // 0x12
	"", // SEQ_EVENT_MERRY_GO_ROUND,         // 0x13
	"", // SEQ_EVENT_RACE,                   // 0x14
	"", // SEQ_EVENT_CUTSCENE_STAR_SPAWN,    // 0x15
	"Valve Studio Orchestra", // SEQ_EVENT_BOSS, // 0x16
	"", // SEQ_EVENT_CUTSCENE_COLLECT_KEY,   // 0x17
	"", // SEQ_EVENT_ENDLESS_STAIRS,         // 0x18
	"", // SEQ_LEVEL_BOSS_KOOPA_FINAL,       // 0x19
	"Scatman John, TMBG", // SEQ_EVENT_CUTSCENE_CREDITS, // 0x1A
	"", // SEQ_EVENT_SOLVE_PUZZLE,           // 0x1B
	"", // SEQ_EVENT_TOAD_MESSAGE,           // 0x1C
	"", // SEQ_EVENT_PEACH_MESSAGE,          // 0x1D
	"", // SEQ_EVENT_CUTSCENE_INTRO,         // 0x1E
	"", // SEQ_EVENT_CUTSCENE_VICTORY,       // 0x1F
	"", // SEQ_EVENT_CUTSCENE_ENDING,        // 0x20
	"Lemon Demon", // SEQ_MENU_FILE_SELECT,  // 0x21
	"", // SEQ_EVENT_CUTSCENE_LAKITU,        // 0x22 (not in JP)
    "the_pau", // SEQ_LEVEL_DESERT,          // 0x23

};
// will display if greater than 0, counts down
u8 songNameTimer = 0;

char* currentSongName = NULL;
char* currentSongAuthor = NULL;

char songDisplayString[256];

s16 songNameXPos = 0;
u16 songNameWidth = 0;

#define TIMER_DEFAULT 60

void activate_song_name_display(u8 seqId) {
	currentSongName = (char*)seqNames[seqId];
	currentSongAuthor = (char*)seqAuthors[seqId];

	sprintf(songDisplayString, "%s#by %s", currentSongName, currentSongAuthor);

	songNameTimer = TIMER_DEFAULT;
	songNameWidth = get_text_width(songDisplayString, FONT_OUTLINE);

	songNameXPos = -songNameWidth;

	return;
}

#define MAX_X_POS 8

#define SONG_DISPLAY_SPEED 4

void draw_song_name(void) {
	if(currentSongName != NULL && currentSongName[0] != '\0' && songNameXPos >= -songNameWidth) {
		prepare_blank_box();
		render_blank_box(0, SCREEN_HEIGHT-36, songNameWidth+songNameXPos+4, SCREEN_HEIGHT-8, 0, 0, 0, 0xAA);
		finish_blank_box();

		/*print_small_text(songNameXPos, 16, currentSongName, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
		print_small_text(songNameXPos, 26, currentSongAuthor, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);*/
		print_small_text(songNameXPos, SCREEN_HEIGHT-34, songDisplayString, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
		if(songNameXPos >= MAX_X_POS){
			--songNameTimer;
		} else if(songNameTimer > 0){
			songNameXPos += SONG_DISPLAY_SPEED;
		}
		if(songNameTimer == 0){
			songNameXPos -= SONG_DISPLAY_SPEED;
		}
	}

	return;
}

/**
 * Called from threads: thread5_game_loop
 */
void enable_background_sound(void) {
    if (sBgMusicDisabled == TRUE) {
        sBgMusicDisabled = FALSE;
        sound_banks_enable(SEQ_PLAYER_SFX, SOUND_BANKS_BACKGROUND);
    }
}

/**
 * Sets the sound mode
 *
 * Called from threads: thread5_game_loop
 */
void set_sound_mode(u16 soundMode) {
    if (soundMode < 3) {
        audio_set_sound_mode(sSoundMenuModeToSoundMode[soundMode]);
    }
}

/**
 * Wrapper method by menu used to set the sound via flags.
 *
 * Called from threads: thread5_game_loop
 */
void play_menu_sounds(s16 soundMenuFlags) {
    if (soundMenuFlags & SOUND_MENU_FLAG_HANDAPPEAR) {
        play_sound(SOUND_MENU_HAND_APPEAR, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_HANDISAPPEAR) {
        play_sound(SOUND_MENU_HAND_DISAPPEAR, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_UNKNOWN1) {
        play_sound(SOUND_MENU_UNK0C_FLAG_UNKNOWN1, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_PINCHMARIOFACE) {
        play_sound(SOUND_MENU_PINCH_MARIO_FACE, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_PINCHMARIOFACE2) {
        play_sound(SOUND_MENU_PINCH_MARIO_FACE, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_LETGOMARIOFACE) {
        play_sound(SOUND_MENU_LET_GO_MARIO_FACE, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_CAMERAZOOMIN) {
        play_sound(SOUND_MENU_CAMERA_ZOOM_IN, gGlobalSoundSource);
    } else if (soundMenuFlags & SOUND_MENU_FLAG_CAMERAZOOMOUT) {
        play_sound(SOUND_MENU_CAMERA_ZOOM_OUT, gGlobalSoundSource);
    }

    if (soundMenuFlags & SOUND_MENU_FLAG_EXTRA) {
        play_menu_sounds_extra(20, NULL);
    }
#if ENABLE_RUMBLE
    if (soundMenuFlags & SOUND_MENU_FLAG_LETGOMARIOFACE) {
        queue_rumble_data(10, 60);
    }
#endif
}

/**
 * Plays the painting eject sound effect if it has not already been played
 *
 * Called from threads: thread5_game_loop
 */
void play_painting_eject_sound(void) {
    if (gRipplingPainting != NULL && gRipplingPainting->state == PAINTING_ENTERED) {
        // ripple when Mario enters painting
        if (!sPaintingEjectSoundPlayed) {
            play_sound(SOUND_GENERAL_PAINTING_EJECT,
                       gMarioStates[0].marioObj->header.gfx.cameraToObject);
        }
        sPaintingEjectSoundPlayed = TRUE;
    } else {
        sPaintingEjectSoundPlayed = FALSE;
    }
}

/**
 * Called from threads: thread5_game_loop
 */
void play_infinite_stairs_music(void) {
#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
    u8 shouldPlay = FALSE;

    /* Infinite stairs? */
    if (gCurrLevelNum == LEVEL_CASTLE && gCurrAreaIndex == 2 && gMarioState->numStars < 70) {
        if (gMarioState->floor != NULL && gMarioState->floor->room == 6) {
            if (gMarioState->pos[2] < 2540.0f) {
                shouldPlay = TRUE;
            }
        }
    }

    if (sPlayingInfiniteStairs ^ shouldPlay) {
        sPlayingInfiniteStairs = shouldPlay;
        if (shouldPlay) {
            play_secondary_music(SEQ_EVENT_ENDLESS_STAIRS, 0, 255, 1000);
        } else {
            func_80321080(500);
        }
    }
#endif
}

/**
 * Called from threads: thread5_game_loop
 */
void set_background_music(u16 a, u16 seqArgs, s16 fadeTimer) {
    activate_song_name_display(seqArgs & 0xff);
    if (gResetTimer == 0 && seqArgs != sCurrentMusic) {
        if (gCurrCreditsEntry != NULL) {
            sound_reset(7);
        } else {
            sound_reset(a);
        }

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
        if (!gNeverEnteredCastle || seqArgs != SEQ_LEVEL_INSIDE_CASTLE)
#endif
        {
            play_music(SEQ_PLAYER_LEVEL, seqArgs, fadeTimer);
            sCurrentMusic = seqArgs;
        }
    }
}

/**
 * Called from threads: thread3_main, thread5_game_loop
 */
void fadeout_music(s16 fadeOutTime) {
    func_803210D4(fadeOutTime);
    sCurrentMusic = MUSIC_NONE;
    sCurrentShellMusic = MUSIC_NONE;
    sCurrentCapMusic = MUSIC_NONE;
}

/**
 * Called from threads: thread5_game_loop
 */
void fadeout_level_music(s16 fadeTimer) {
    seq_player_fade_out(SEQ_PLAYER_LEVEL, fadeTimer);
    sCurrentMusic = MUSIC_NONE;
    sCurrentShellMusic = MUSIC_NONE;
    sCurrentCapMusic = MUSIC_NONE;
}

/**
 * Called from threads: thread5_game_loop
 */
void play_cutscene_music(u16 seqArgs) {
    play_music(SEQ_PLAYER_LEVEL, seqArgs, 0);
    sCurrentMusic = seqArgs;
}

/**
 * Called from threads: thread5_game_loop
 */
void play_shell_music(void) {
    play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP | SEQ_VARIATION), 0);
    sCurrentShellMusic = SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP | SEQ_VARIATION);
}

/**
 * Called from threads: thread5_game_loop
 */
void stop_shell_music(void) {
    if (sCurrentShellMusic != MUSIC_NONE) {
        stop_background_music(sCurrentShellMusic);
        sCurrentShellMusic = MUSIC_NONE;
    }
}

/**
 * Called from threads: thread5_game_loop
 */
void play_cap_music(u16 seqArgs) {
    play_music(SEQ_PLAYER_LEVEL, seqArgs, 0);
    if (sCurrentCapMusic != MUSIC_NONE && sCurrentCapMusic != seqArgs) {
        stop_background_music(sCurrentCapMusic);
    }
    sCurrentCapMusic = seqArgs;
}

/**
 * Called from threads: thread5_game_loop
 */
void fadeout_cap_music(void) {
    if (sCurrentCapMusic != MUSIC_NONE) {
        fadeout_background_music(sCurrentCapMusic, 600);
    }
}

/**
 * Called from threads: thread5_game_loop
 */
void stop_cap_music(void) {
    if (sCurrentCapMusic != MUSIC_NONE) {
        stop_background_music(sCurrentCapMusic);
        sCurrentCapMusic = MUSIC_NONE;
    }
}

/**
 * Called from threads: thread5_game_loop
 */
void play_menu_sounds_extra(s32 a, void *b) {
    play_sound(sMenuSoundsExtra[a], b);
}

/**
 * Called from threads: thread5_game_loop
 */
void audio_game_loop_tick(void) {
    audio_signal_game_loop_tick();
}

/**
 * Sound processing thread. Runs at 60 FPS.
 */
void thread4_sound(UNUSED void *arg) {
    audio_init();
    sound_init();

    osCreateMesgQueue(&sSoundMesgQueue, sSoundMesgBuf, ARRAY_COUNT(sSoundMesgBuf));
    set_vblank_handler(1, &sSoundVblankHandler, &sSoundMesgQueue, (OSMesg) 512);

    while (TRUE) {
        OSMesg msg;

        osRecvMesg(&sSoundMesgQueue, &msg, OS_MESG_BLOCK);
        profiler_audio_started();
        if (gResetTimer < 25) {
            struct SPTask *spTask;
            spTask = create_next_audio_frame_task();
            if (spTask != NULL) {
                dispatch_audio_sptask(spTask);
            }
        }
        profiler_audio_completed();
    }
}
