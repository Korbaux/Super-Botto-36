// orange_number.inc.c
u8 nTimer = 0;
aOrB = 0;
void bhv_orange_number_init(void) {
    o->oAnimState = o->oBehParams2ndByte;
    o->oVelY = 26.0f;
}

void bhv_orange_number_loop(void) {
#ifdef DIALOG_INDICATOR
    nTimer = (nTimer + 1) % 15;
    if (o->oAnimState <= ORANGE_NUMBER_9) {
#endif
        o->oPosY += o->oVelY;
        o->oVelY -= 2.0f;

        if (o->oVelY < -21.0f) {
            o->oVelY = 14.0f;
        }

        if (o->oTimer == 35) {
            struct Object *sparkleObj = spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
            sparkleObj->oPosY -= 30.0f;
            obj_mark_for_deletion(o);
        }
#ifdef DIALOG_INDICATOR
    } else
        if (aOrB) {
            o->oAnimState = ORANGE_NUMBER_A1;
        } else {
            o->oAnimState = ORANGE_NUMBER_B1;
        }
        if (o->oTimer >= 1 || gMarioState->action == ACT_READING_SIGN) {
        aOrB = (aOrB + (nTimer == 0)) % 2;
        obj_mark_for_deletion(o);
        }

#endif
}
