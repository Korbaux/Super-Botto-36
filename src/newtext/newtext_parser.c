#include <ultra64.h>
#include "newtext.h"
#include "sounds.h"
#include "game/game_init.h"
#include "game/level_update.h"
#include "game/area.h"
#include "audio/external.h"
#include "s2dex_text_engine/s2d_print.h"
#include "s2dex_text_engine/s2d_ustdlib.h"
#include "dialog.h"

#define NT_PrintFunc s2d_print_deferred
u32 NT_StrLen(u8 *text) {
    char *p = text;
    while (*p != 0) {
        p ++;
    }
    return (u32)p - (u32)text;
}

static char NT_TextBuffer[2048];
static s32 NewText_TextCursor = -1;
static s32 NewText_TextSubCursor = -1;
static s32 NewText_TextLen = -1;
static u32 NT_SkipToEnd= 0;

static u8 *NewText_Cursor = 0;
static s32 NewText_FrameWait = -1;
static s32 numColorPrints = 0;

static int NewText_X = 20;
static int NewText_Y = 20;

static u32 NewText_TextSound = 0;
u32 NewText_CurAlign = ALIGN_LEFT;
u32 NewText_DrawingTB = FALSE;
u32 NewText_CurrentColor = 0x000000FF;

int NewText_BufferWarpNode = -1;

char myName[500];

static u32 isUnskippable = FALSE;

static u32 read_u32(u8 *d) {
    return *(u32*)d;
}

void NT_StartWarp() {
    sDelayedWarpTimer = 20;
    sSourceWarpNodeId = NewText_BufferWarpNode;
    sDelayedWarpOp = WARP_OP_WARP_OBJECT;
    play_transition(WARP_TRANSITION_FADE_INTO_STAR, 20, 0, 0, 0);
}

u16 NT_ReadController() {
    return gPlayer1Controller->buttonPressed;
}

s8 NT_ReadStick() {
    return gPlayer1Controller->stickY;
}

void NewText_CopyRest(u8 *text) {
    u32 len = NT_StrLen(text + (NewText_TextSubCursor - NewText_TextCursor));
    strcpy(NT_TextBuffer + NewText_TextSubCursor, text + (NewText_TextSubCursor - NewText_TextCursor));
    NewText_TextSubCursor += len;
}


void clearrow(u8 *text) {
    for (int i = 0; i < NT_StrLen(text); i++) {
        if (text[i] == CH_COLORSTACK_UD) text[i] = ' ';
    }
}

void str_repl_space_w_color(u8 *text, u32 pos) {
    text[(pos * 2)] = CH_COLORSTACK_UD;
    text[(pos * 2) + 2] = CH_COLORSTACK_UD;
}

void flipcase(u8 **texts) {
    static s32 isUpper = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < NT_StrLen(texts[i]); j++) {
            if ((texts[i][j] >= ('A')
              && texts[i][j] <= ('Z'))
                ||
                (texts[i][j] >= ('a')
              && texts[i][j] <= ('z'))
            ) {
                texts[i][j] += (isUpper * 32);
            }
        }
    }


    isUpper *= -1;
}

int NewText_Keyboard(u8 *text, u8 *var) {
    // strcpy(var, "epic");
    static char kbuffer[50];
    static u32 kcur = 0;
    static char *FirstRow = "A B C D E F G H I J K L ";
    static char *SeconRow = "M N O P Q R S T U V W X ";
    static char *TertiRow = "Y Z 0 1 2 3 4 5 6 7 8 9 ";

    static char *instructions = "(shift: L)(backspace: B)(space: C-Right)(end: Start)";

    char *epic[3] = {FirstRow, SeconRow, TertiRow};

    static u32 sticklatchX = 0, sticklatchY = 0;

    static s32 curX = 0, curY = 0;

    // clearrow(epic[0]);
    // clearrow(epic[1]);
    // clearrow(epic[2]);
    // str_repl_space_w_color(epic[curX], curY);


    NT_PrintFunc(NewText_X - 20, NewText_Y, FirstRow);
    NT_PrintFunc(NewText_X - 20, NewText_Y + 0x10, SeconRow);
    NT_PrintFunc(NewText_X - 20, NewText_Y + 32, TertiRow);
    NT_PrintFunc(NewText_X - 20, NewText_Y + 50, instructions);

    u32 dispCurX = 0;

    if (curY == 0) {
        dispCurX = NewText_X - 22;
    } else {
        dispCurX = NewText_X - 25 + s2d_snwidth(epic[curX], curY * 2) + 3;
    }

    static char curbuffer[50] = COLOR "255 0 0 255";
    static char curbuffer2[50] = COLOR "0 0 0 255";
    sprintf(curbuffer + 12, "(%c)", epic[curX][curY * 2]);
    sprintf(curbuffer2 + 10, "(%c)", epic[curX][curY * 2]);
    extern u32 gGlobalTimer;
    if (gGlobalTimer % 15 < 7) {
        NT_PrintFunc(dispCurX, NewText_Y + (16 * curX), curbuffer);
    } else {
        NT_PrintFunc(dispCurX, NewText_Y + (16 * curX), curbuffer2);
    }

    NT_PrintFunc(NewText_X + 170, NewText_Y, text);
    NT_PrintFunc(NewText_X + 170, NewText_Y + 16, kbuffer);

    s8 stick = gPlayer1Controller->stickY;
    if ((stick >= -14) && (stick <= 14)) {
        sticklatchY = 0;
    }
    if (sticklatchY == 0) {
        if (stick < -14) {
            curX++;
            sticklatchY = 1;
        }
        if (stick > 14) {
            curX--;
            sticklatchY = 1;
        }
    }

    stick = gPlayer1Controller->stickX;
    if ((stick >= -14) && (stick <= 14)) {
        sticklatchX = 0;
    }
    if (sticklatchX == 0) {
        if (stick < -14) {
            curY--;
            sticklatchX = 1;
        }
        if (stick > 14) {
            curY++;
            sticklatchX = 1;
        }
    }

    if (curX < 0) curX = 0;
    if (curX > 2) curX = 2;
    if (curY < 0) curY = 0;
    if (curY > 11) curY = 11;

    // print_text_fmt_int(50, 50, "%d", sticklatch);

    if (NT_ReadController() & A_BUTTON) {
        if (kcur <= NewText_MAXKEYBOARDWIDTH) {
            kbuffer[kcur++] = epic[curX][curY * 2];
        } else {
            play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
        }
    }

    if (NT_ReadController() & B_BUTTON) {
        if (kcur != 0) {
            kbuffer[--kcur] = 0;
        }
    }

    if (NT_ReadController() & R_CBUTTONS) {
        kbuffer[kcur++] = ' ';
    }
    
    if (NT_ReadController() & L_TRIG) {
        flipcase(epic);
    }

    if (NT_ReadController() & START_BUTTON) {
        strcpy(var, kbuffer);
        kcur = 0;
        bzero(kbuffer, sizeof(kbuffer));
        return 1;
    }
    return 0;
}

int NewText_RenderText(u8 *text) {
    if (NewText_TextCursor == -1) NewText_TextCursor = 0;
    if (NewText_TextSubCursor == -1) NewText_TextSubCursor = NewText_TextCursor;
    if (NewText_TextLen == -1) NewText_TextLen = NT_StrLen(text);
    // if (text[0] == 'C' && NewText_TextLen != 17) {
    //     *(vs8*)0=0;
    // }

    NT_TextBuffer[NewText_TextSubCursor] = text[NewText_TextSubCursor - NewText_TextCursor];
    if ((NT_ReadController() & A_BUTTON) && isUnskippable == FALSE) {
        NT_SkipToEnd = 1;
    }


    if (NT_SkipToEnd == 1) {
        NewText_CopyRest(text);
    } else {
        NT_TextBuffer[NewText_TextSubCursor + 1] = 0;
    }

    play_sound(NewText_TextSound, gGlobalSoundSource);

    // print_text_fmt_int(50, 50, "%d", NewText_TextLen);

    if (NewText_TextSubCursor - NewText_TextCursor >= NewText_TextLen) {
        NewText_TextCursor = NewText_TextSubCursor;
        NewText_TextSubCursor = -1;
        NewText_TextLen = -1;
        return 1;
    } else {
        NewText_TextSubCursor += 1;
        return 0;
    }
}

void NewText_SayFull(u8 *text) {
    if (NewText_TextCursor == -1) NewText_TextCursor = 0;
    if (NewText_TextSubCursor == -1) NewText_TextSubCursor = NewText_TextCursor;
    if (NewText_TextLen == -1) NewText_TextLen = NT_StrLen(text);

    strcpy(&NT_TextBuffer[NewText_TextSubCursor], text);
    NewText_TextSubCursor += NewText_TextLen;

    NewText_TextCursor = NewText_TextSubCursor;
    NewText_TextSubCursor = -1;
}

void NT_KeepText(void) {
    NT_PrintFunc(NewText_X, NewText_Y, NT_TextBuffer);
}



uObjBg sprite_bg = {
    0, 320<<2, 0<<2, 320<<2,  /* imageX, imageW, frameX, frameW */
    0, 80<<2, 0<<2, 80<<2,  /* imageY, imageH, frameY, frameH */
    (u64 *)&sprite_tex_0,                /* imagePtr                       */
    G_BGLT_LOADBLOCK,     /* imageLoad */                      
    G_IM_FMT_I,        /* imageFmt                       */
    G_IM_SIZ_4b,         /* imageSiz                       */
    0,                /* imagePal                       */
    0,             /* imageFlip                      */
    1 << 10,       /* scale W (s5.10) */
    1 << 10,       /* scale H (s5.10) */
    0,
};
Gfx sprite_init_dl[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0, 0, 0, 0x01),
    gsDPSetCombineLERP(
        TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0,
        TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0
    ),
    gsSPEndDisplayList(),
};
Gfx sprite_bg_dl[] = {
    gsDPPipeSync(),
    gsSPDisplayList(sprite_init_dl),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_XLU_SPRITE, G_RM_XLU_SPRITE2),
    gsSPObjRenderMode(G_OBJRM_XLU | G_OBJRM_BILERP),
    gsSPBgRect1Cyc(&sprite_bg),
    gsSPEndDisplayList(),
};// 320 80

static u8 tb_r, tb_g, tb_b, tb_a;
void NT_DrawTextBox(void) {
    sprite_bg.s.frameX = 0;
    sprite_bg.s.frameY = (NewText_Y - 20) << 2;
    gDPPipeSync(gDisplayListHead++);
    gDPSetEnvColor(gDisplayListHead++, tb_r, tb_g, tb_b, tb_a);
    gSPDisplayList(gDisplayListHead++, sprite_bg_dl);
}

extern u32 s2d_colorstack[100];
extern u32 s2d_colorstack_top;

void NT_RenderMenu(u8 *cursor) {
    static u32 sticklatch = 0;
    static s32 curpos = 0;

    char *title = read_u32(cursor + 4);
    char *ch1 = read_u32(cursor + 8);
    u8 *labels[4];
    labels[0] = read_u32(cursor + 12);
    char *ch2 = read_u32(cursor + 16);
    labels[1] = read_u32(cursor + 20);
    char *ch3 = read_u32(cursor + 24);
    labels[2] = read_u32(cursor + 28);
    char *ch4 = read_u32(cursor + 32);
    labels[3] = read_u32(cursor + 36);

    s2d_colorstack[98] = NewText_CurrentColor;

    int baseY = NewText_Y - 10;

    // cursor
    NT_PrintFunc(NewText_X - 4, baseY + (15 * (curpos + 1)), "|");

    // text print
    NT_PrintFunc(NewText_X, baseY, title);
    NT_PrintFunc(NewText_X + 8, baseY + 15, ch1);
    NT_PrintFunc(NewText_X + 8, baseY + 30, ch2);
    NT_PrintFunc(NewText_X + 8, baseY + 45, ch3);
    NT_PrintFunc(NewText_X + 8, baseY + 60, ch4);

    // cursor movement
    s8 stick = NT_ReadStick();
    if ((stick >= -14) && (stick <= 14)) {
        sticklatch = 0;
    }
    if (sticklatch == 0) {
        if (stick < -14) {
            curpos++;
            sticklatch = 1;
        }
        if (stick > 14) {
            curpos--;
            sticklatch = 1;
        }
    }

    // print_text_fmt_int(100, 100, "%d", curpos);
    // print_text_fmt_int(116, 100, "%d", sticklatch);
    // print_text_fmt_int(132, 100, "%d", stick);

    // // cursor clamp
    if (curpos < 0) curpos = 0;
    if (curpos > 3) curpos = 3;

    // // if cursor goto label
    if (NT_ReadController() & A_BUTTON) {
        NewText_Cursor = labels[curpos];
    }
}


static void str_tolower(u8 *dst, u8 *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            dst[i] = str[i] + 32;
        } else {
            dst[i] = str[i];
        }
    }
}
void NewText_Compare(u8 *cursor) {
    char *var = read_u32(cursor + 4);
    char *compare = read_u32(cursor + 8);
    char *labelCorrect = read_u32(cursor + 12);
    char *labelWrong = read_u32(cursor + 16);

    char buf1[50]; bzero(buf1, sizeof(buf1)); str_tolower(buf1, var);
    char buf2[50]; bzero(buf2, sizeof(buf2)); str_tolower(buf2, compare);

    if (strcmp(buf1, buf2) == 0) {
        NewText_Cursor = labelCorrect;
    } else {
        NewText_Cursor = labelWrong;
    }
}

u32 subStackPtr = 0;
int NewText_Parse(u8 *scene) {
    if (NewText_Cursor == 0) {
        NewText_Cursor = scene;
    }


    u8 nt_cmd = NewText_Cursor[0];
    u8 nt_cmdlen = NewText_Cursor[1];

    u32 isKeyboard = 0;
    u32 ismenu = 0;

    if (nt_cmd == NT_DONE) {
        bzero(NT_TextBuffer, sizeof(NT_TextBuffer));
        NewText_Cursor = 0;
        NewText_DrawingTB = FALSE;
        extern u32 subStackPtr;
        subStackPtr = 0;
        s2d_colorstack_top = 0;
        NT_SkipToEnd = 0;

        if (NewText_BufferWarpNode != -1) {
            NT_StartWarp();
            NewText_BufferWarpNode = -1;
        }

        return 0;
    }

    u32 proceed = 0;

    switch (nt_cmd) {
        case NT_SAY:
        case NT_RECALL:
            // this is gonna be epic
            if (NewText_RenderText(*(u32 *)(NewText_Cursor + 4))) proceed = 1;
            
            break;
        case NT_ALIGN:
            NewText_CurAlign = NewText_Cursor[3];
            proceed = 1;
            if (NewText_Cursor[3] == ALIGN_CENTER) {
                NewText_X = 320 / 2;
            } else {
                NewText_X = 40;
            }
            break;
        case NT_ENDSAY:
            NewText_TextCursor = -1;
            NewText_TextLen = -1;
            numColorPrints = 0;
            isUnskippable = FALSE;
            subStackPtr = 0;
            s2d_colorstack_top = 0;
            NT_SkipToEnd = 0;
            if (NT_ReadController() & (A_BUTTON | B_BUTTON)) {
                proceed = 1;
            }
            break;
        case NT_WAIT:
            if (NewText_FrameWait == -1) {
                NewText_FrameWait = *(u16*)(NewText_Cursor + 2);
            } else {
                if (--NewText_FrameWait == 0) {
                    proceed = 1;
                    NewText_FrameWait = -1;
                }
            }
            break;
        case NT_MAKETEXTBOX:
            // TODO: do we want a way to skip this?
            NewText_DrawingTB = TRUE;
            tb_r = NewText_Cursor[4];
            tb_g = NewText_Cursor[5];
            tb_b = NewText_Cursor[6];
            tb_a = NewText_Cursor[7];
            proceed = 1;
            break;
        case NT_MENU:
            ismenu = 1;
            // if (NT_TextBuffer[0] != CH_COLOR) {
            //     NewText_TextCursor = -1;
            //     NewText_TextLen = -1;
            //     NT_TextBuffer[0] = 0;
            // }
            // does not have a proceed condition because its a branch
            NT_RenderMenu(NewText_Cursor);
            break;
        case NT_GO:
            NewText_Cursor = *(u32*)(NewText_Cursor + 4);
            break;
        case NT_TURING: {
            u32 fp = *(u32*)(NewText_Cursor + 4);
            if (((int (*)())fp)());
            proceed = 1;
            break;
        }
        case NT_SOUND:
            play_sound(*(u32 *)(NewText_Cursor + 4), gGlobalSoundSource);
            proceed = 1;
            break;
        case NT_TXTSOUND:
            NewText_TextSound = *(u32 *)(NewText_Cursor + 4);
            proceed = 1;
            break;
        case NT_KEYBOARD:
            if (NewText_Keyboard(*(u32 *)(NewText_Cursor + 4), *(u32 *)(NewText_Cursor + 8)) == 1) {
                proceed = 1;
                isKeyboard = 0;
            } else {
                isKeyboard = 1;
            }
            break;
        case NT_SAYFULL:
            NewText_SayFull(*(u32 *)(NewText_Cursor + 4));
            proceed = 1;
            break;
        case NT_UNSKIPPABLE:
            isUnskippable = TRUE;
            proceed = 1;
            break;
        case NT_TEXTBOXPOS:
            switch (NewText_Cursor[3]) {
                case top: NewText_Y = 20; break;
                case middle: NewText_Y = 100; break;
                case bottom: NewText_Y = 170; break;
            }
            proceed = 1;
            break;
        case NT_COLOR:
            NewText_CurrentColor = (
                  (NewText_Cursor[4] << 24)
                | (NewText_Cursor[5] << 16)
                | (NewText_Cursor[6] << 8)
                | (NewText_Cursor[7])
                );
            s2d_colorstack[s2d_colorstack_top++] = NewText_CurrentColor;
            if (NewText_TextCursor == -1) {
                NT_TextBuffer[0] = CH_COLORSTACK;
                NewText_TextCursor = 1;
            } else {
                NT_TextBuffer[NewText_TextCursor++] = CH_COLORSTACK;
            }
            proceed = 1;
            break;
        case NT_COMPARE:
            NewText_Compare(NewText_Cursor);
            break;
        case NT_WARP:
            NewText_BufferWarpNode = NewText_Cursor[3];
            proceed = 1;
            break;
    }

    if (proceed) {
        NewText_Cursor += nt_cmdlen;
    }

    if (isKeyboard == 0 && ismenu == 0) {
        NT_KeepText();
    }


    // debug print the color stack
    // char epic[100][30];
    // for (int i = 0; i < s2d_colorstack_top; i++) {
    //     sprintf(epic[i], "%X", s2d_colorstack[i]);
    //     NT_PrintFunc(20, 20 + (16 * i), epic[i]);
    // }

    return 1;
}

