#define NEWTEXT_ASM
#include "newtext.h"
#include "sounds_asm.h"

scene Scene2

maketextbox 255 255 255 255

textsound SOUND_ACTION_TERRAIN_STEP

align left
textpos top
color 0 0 0 255

say "hello world"
endsay

endscene


