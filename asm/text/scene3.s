#define NEWTEXT_ASM
#include "newtext.h"
#include "sounds_asm.h"

scene NT_TestKeyboardScene

maketextbox 255 255 255 255

textsound SOUND_ACTION_TERRAIN_STEP

align left
textpos top
color 0 0 0 255

keyboard "Left or right door?", myName

compare myName, "left", ld, rd

ld:
warp 0
go myTextEnd

rd:
warp 1
go myTextEnd

myTextEnd:
endscene

