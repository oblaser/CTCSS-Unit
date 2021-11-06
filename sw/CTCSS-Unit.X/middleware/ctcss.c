/*
\author         Oliver Blaser
\date           06.11.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#include "../driver/hardware_16F1825.h"
#include "ctcss.h"


void CTCSS_init()
{
    CTCSS_accumulator = 0;
    CTCSS_setTone(CTCSS_ID_OFF);
}

void CTCSS_setTone(ctcss_id_t toneId)
{
    switch(toneId)
    {
        case CTCSS_ID_77_0:
            CTCSS_increment = 323;
            break;
            
        default:
            CTCSS_increment = 0;
            break;
    }
}
