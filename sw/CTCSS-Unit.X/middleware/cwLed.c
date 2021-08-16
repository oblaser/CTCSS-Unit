/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#include "../driver/gpio.h"
#include "cwLed.h"


typedef enum
{
    S_init = 0,
    S_idle,
    S__last
} state_t;


void CWLED_task(TASK_status_t* ts)
{
    static state_t state = S_init;
    
    switch(state)
    {
        case S_init:
            break;
            
        case S_idle:
            break;
            
        default:
            *ts |= (TASK_TCWLED | TASK_STATE);
            break;
    }
}

void CWLED_timeHandler()
{
}
