#define NEWTEXT_ASM
#include "newtext.h"
#include "sounds_asm.h"

scene NT_Testscene1

maketextbox 255 255 255 255

textsound SOUND_ACTION_TERRAIN_STEP

align left

textpos top
color 0 0 0 255
say "hello world"
wait 12
say "!!!"
endsay

textpos middle
color 0 255 0 255
play SOUND_MARIO_YAHOO
say "im stupid!"
endsay

keyboard "Enter a thing!", myName

align left
textpos bottom
maketextbox 255 0 0 255
color 0 0 0 255
menu "Select a choice!", \
     "games", pickA, \
     "tv", pickB, \
     "anime", pickC, \
     "being lazy", pickD

pickA:
    recall myName
    say "! you are wrong!"
    go myTextEnd

pickB:
    recall myName
    say "! you are wrong!"
    go myTextEnd

pickC:
    textpos top
    recall myName
    say "! you are correct!\n"
    say "Congratulations, "
    recall myName
    say "!"
    go myTextEnd

pickD:
    recall myName
    say "! please dont say you are lazy!"
    go myTextEnd


myTextEnd:
endsay // optimization built right in!

say "This message can be fully shown\n"
say "with the A button, or..."
endsay
say "nothing else because\n"
color 0 0 255 255
say "the B button\n"
color 0 0 0 255
say "is useless!\n"
endsay
unskippable
say "this message is required!"
endsay
play SOUND_ACTION_TERRAIN_STEP







endscene


