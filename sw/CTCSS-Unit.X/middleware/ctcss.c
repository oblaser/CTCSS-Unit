/*
\author         Oliver Blaser
\date           22.11.2021
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
// f_OUT = increment * f_isr / 2^n ; f_isr = 15'625Hz ; n = 16
// => increment = f_OUT * 2^16 / 15'625Hz
    
    switch(toneId)
    {
        case CTCSS_ID_77_0:
            CTCSS_increment = 323;
            break;
            
        case CTCSS_ID_254_1:
            CTCSS_increment = 1066;
            break;
            
        default:
            CTCSS_increment = 0;
            break;
    }
}
