#pragma once

#ifdef NEWTEXT_ASM
    #ifdef _LANGUAGE_C
        #undef _LANGUAGE_C
        #define ASSEMBLER
    #endif
#endif


#define NewText_MAXKEYBOARDWIDTH 10





#define NT_NOP 0
#define NT_SAY 1
#define NT_WAIT 2
#define NT_ALIGN 3
#define NT_ENDSAY 4
#define NT_MENU 5
#define NT_GO 6
#define NT_RECALL 7
#define NT_KEYBOARD 8
#define NT_TURING 9
#define NT_SOUND 10
#define NT_TXTSOUND 11
#define NT_SAYFULL 12
#define NT_UNSKIPPABLE 13
#define NT_MAKETEXTBOX 14
#define NT_TEXTBOXPOS 15
#define NT_COLOR 16
#define NT_COMPARE 17
#define NT_WARP 18
#define NT_DONE 19

#define left 0
#define top 0
#define middle 1
#define bottom 2


#ifdef NEWTEXT_ASM

.macro scene name
.section .newtext
.balign 4
.global \name
\name:
.endm

.macro align nm
    .byte NT_ALIGN, 4, 0, \nm
.endm

.macro textpos p
    .byte NT_TEXTBOXPOS, 4, 0, \p
.endm

.macro maketextbox r, g, b, a
    .byte NT_MAKETEXTBOX, 8, 0, 0
    .byte \r, \g, \b, \a
.endm

.macro say str
    .byte NT_SAY, 8,0,0
    .word NT_str_\@
    .section .rodata
    .balign 4
    NT_str_\@:
        .asciiz "\str"
    .section .newtext
.endm

.macro menu title, ch1, lb1, ch2, lb2, ch3, lb3, ch4, lb4
    .section .rodata
    .balign 4
    NT_menutitle_\@:
        .asciiz "\title"
    .balign 4
    NT_menuchoice1_\@:
        .asciiz "\ch1"
    .balign 4
    NT_menuchoice2_\@:
        .asciiz "\ch2"
    .balign 4
    NT_menuchoice3_\@:
        .asciiz "\ch3"
    .balign 4
    NT_menuchoice4_\@:
        .asciiz "\ch4"
    .section .newtext

    .byte NT_MENU, 40, 0, 0
    .word NT_menutitle_\@
    .word NT_menuchoice1_\@, \lb1
    .word NT_menuchoice2_\@, \lb2
    .word NT_menuchoice3_\@, \lb3
    .word NT_menuchoice4_\@, \lb4
.endm

.macro wait frames
    .byte NT_WAIT, 4
    .half \frames
.endm

.macro color r, g, b, a
    .byte NT_COLOR, 8,0,0
    .byte \r, \g, \b, \a
.endm

.macro go lbl
    .byte NT_GO, 8, 0, 0
    .word \lbl
.endm

.macro keyboard titlestr variable
    .byte NT_KEYBOARD, 12, 0, 0
    .word NT_keytitle_\@
    .word \variable
    .section .rodata
    .balign 4
    NT_keytitle_\@:
        .asciiz "\titlestr"
    .section .newtext
.endm

.macro recall variable
    .byte NT_RECALL, 8, 0, 0
    .word \variable
.endm

.macro call function
    .byte NT_TURING, 8, 0, 0
    .word \function
.endm

.macro play id
    .byte NT_SOUND, 8, 0, 0
    .word \id
.endm

.macro textsound id
    .byte NT_TXTSOUND, 8, 0, 0
    .word \id
.endm

.macro endscene
    .byte NT_DONE, 4, 0,0
.endm

.macro endsay
    .byte NT_ENDSAY, 4, 0,0
.endm

.macro unskippable
    .byte NT_UNSKIPPABLE, 4, 0, 0
.endm

.macro compare var, comparestr, lblCorrect, lblWrong
    .byte NT_COMPARE, 20, 0, 0
    .word \var
    .word NT_str_\@
    .word \lblCorrect
    .word \lblWrong
    .section .rodata
    .balign 4
    NT_str_\@:
        .asciiz "\comparestr"
    .section .newtext
.endm

.macro warp node
    .byte NT_WARP, 4, 0, \node
.endm

#else


#endif
