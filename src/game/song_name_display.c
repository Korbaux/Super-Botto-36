#include <PR/ultratypes.h>

#include <ultra64.h>
#include <string.h>

#include "sm64.h"

#include "game_init.h"
#include "puppyprint.h"

#include "seq_ids.h"

#include "song_name_display.h" 



// will display if greater than 0, counts down
u8 songNameTimer = 0;


/*
 * HAS TO BE UPDATED EVERY TIME A NEW SEQUENCE IS ADDED
 */
const char* seqNames[SEQ_COUNT] = {
	// probably a really dumb solution to have a bunch of null strings for ones that shouldn't be displayed but whatever
	"", // SEQ_SOUND_PLAYER,                 // 0x00
	"", // SEQ_EVENT_CUTSCENE_COLLECT_STAR,  // 0x01
	"", // SEQ_MENU_TITLE_SCREEN,            // 0x02
	"Main Menu (Hotel Mario)", // SEQ_LEVEL_GRASS, // 0x03
	"", // SEQ_LEVEL_INSIDE_CASTLE,          // 0x04
	"", // SEQ_LEVEL_WATER,                  // 0x05
	"", // SEQ_LEVEL_HOT,                    // 0x06
	"", // SEQ_LEVEL_BOSS_KOOPA,             // 0x07
	"", // SEQ_LEVEL_SNOW,                   // 0x08
	"", // SEQ_LEVEL_SLIDE,                  // 0x09
	"", // SEQ_LEVEL_SPOOKY,                 // 0x0A
	"", // SEQ_EVENT_PIRANHA_PLANT,          // 0x0B
	"Billie Jean", // SEQ_LEVEL_UNDERGROUND, // 0x0C
	"", // SEQ_MENU_STAR_SELECT,             // 0x0D
	"PepsiMan", // SEQ_EVENT_POWERUP,        // 0x0E
	"", // SEQ_EVENT_METAL_CAP,              // 0x0F
	"", // SEQ_EVENT_KOOPA_MESSAGE,          // 0x10
	"", // SEQ_LEVEL_KOOPA_ROAD,             // 0x11
	"", // SEQ_EVENT_HIGH_SCORE,             // 0x12
	"", // SEQ_EVENT_MERRY_GO_ROUND,         // 0x13
	"", // SEQ_EVENT_RACE,                   // 0x14
	"", // SEQ_EVENT_CUTSCENE_STAR_SPAWN,    // 0x15
	"", // SEQ_EVENT_BOSS,                   // 0x16
	"", // SEQ_EVENT_CUTSCENE_COLLECT_KEY,   // 0x17
	"", // SEQ_EVENT_ENDLESS_STAIRS,         // 0x18
	"", // SEQ_LEVEL_BOSS_KOOPA_FINAL,       // 0x19
	"", // SEQ_EVENT_CUTSCENE_CREDITS,       // 0x1A
	"", // SEQ_EVENT_SOLVE_PUZZLE,           // 0x1B
	"", // SEQ_EVENT_TOAD_MESSAGE,           // 0x1C
	"", // SEQ_EVENT_PEACH_MESSAGE,          // 0x1D
	"", // SEQ_EVENT_CUTSCENE_INTRO,         // 0x1E
	"", // SEQ_EVENT_CUTSCENE_VICTORY,       // 0x1F
	"", // SEQ_EVENT_CUTSCENE_ENDING,        // 0x20
	"", // SEQ_MENU_FILE_SELECT,             // 0x21
	"", // SEQ_EVENT_CUTSCENE_LAKITU,        // 0x22 (not in JP)
};

const char* seqAuthors[SEQ_COUNT] = {
	// probably a really dumb solution to have a bunch of null strings for ones that shouldn't be displayed but whatever
	"", // SEQ_SOUND_PLAYER,                 // 0x00
	"", // SEQ_EVENT_CUTSCENE_COLLECT_STAR,  // 0x01
	"", // SEQ_MENU_TITLE_SCREEN,            // 0x02
	"Max Steiner", // SEQ_LEVEL_GRASS,       // 0x03
	"", // SEQ_LEVEL_INSIDE_CASTLE,          // 0x04
	"", // SEQ_LEVEL_WATER,                  // 0x05
	"", // SEQ_LEVEL_HOT,                    // 0x06
	"", // SEQ_LEVEL_BOSS_KOOPA,             // 0x07
	"", // SEQ_LEVEL_SNOW,                   // 0x08
	"", // SEQ_LEVEL_SLIDE,                  // 0x09
	"", // SEQ_LEVEL_SPOOKY,                 // 0x0A
	"", // SEQ_EVENT_PIRANHA_PLANT,          // 0x0B
	"Michael Jackson", // SEQ_LEVEL_UNDERGROUND, // 0x0C
	"", // SEQ_MENU_STAR_SELECT,             // 0x0D
	"Pepsi", // SEQ_EVENT_POWERUP,           // 0x0E
	"", // SEQ_EVENT_METAL_CAP,              // 0x0F
	"", // SEQ_EVENT_KOOPA_MESSAGE,          // 0x10
	"", // SEQ_LEVEL_KOOPA_ROAD,             // 0x11
	"", // SEQ_EVENT_HIGH_SCORE,             // 0x12
	"", // SEQ_EVENT_MERRY_GO_ROUND,         // 0x13
	"", // SEQ_EVENT_RACE,                   // 0x14
	"", // SEQ_EVENT_CUTSCENE_STAR_SPAWN,    // 0x15
	"", // SEQ_EVENT_BOSS,                   // 0x16
	"", // SEQ_EVENT_CUTSCENE_COLLECT_KEY,   // 0x17
	"", // SEQ_EVENT_ENDLESS_STAIRS,         // 0x18
	"", // SEQ_LEVEL_BOSS_KOOPA_FINAL,       // 0x19
	"", // SEQ_EVENT_CUTSCENE_CREDITS,       // 0x1A
	"", // SEQ_EVENT_SOLVE_PUZZLE,           // 0x1B
	"", // SEQ_EVENT_TOAD_MESSAGE,           // 0x1C
	"", // SEQ_EVENT_PEACH_MESSAGE,          // 0x1D
	"", // SEQ_EVENT_CUTSCENE_INTRO,         // 0x1E
	"", // SEQ_EVENT_CUTSCENE_VICTORY,       // 0x1F
	"", // SEQ_EVENT_CUTSCENE_ENDING,        // 0x20
	"", // SEQ_MENU_FILE_SELECT,             // 0x21
	"", // SEQ_EVENT_CUTSCENE_LAKITU,        // 0x22 (not in JP)
};

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
	draw_song_name();
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
