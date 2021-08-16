/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#include "../types.h"
#include "gpio.h"


#define PORTC_DISP_MASK (0x7F)

void readInp(GPIO_inp_type* inp);



void GPIO_init()
{
    LATA = 0;
    // default ANSELA  = 0b00010111;
    TRISA   = 0b00011111;
    WPUA    = 0b00011111;
    // default INLVLA  = 0b00000100;
    
    LATC = 0;
    ANSELC  = 0b00000011;
    TRISC   = 0b00110111;
    WPUC    = 0b00110111;
    // default INLVLC  = 0b00000100;
    
#if(PRJ_PROGIO_IN)
    ANSELAbits.ANSA4 = 0;
    TRISAbits.TRISA4 = 1;
    WPUAbits.WPUA4 = 1;
#endif
#if(PRJ_PROGIO_OUT)
    ANSELAbits.ANSA4 = 0;
    TRISAbits.TRISA4 = 0;
    WPUAbits.WPUA4 = 0;
#endif
    
    // to have a valid inpOld
    GPIO_inpDetect(NULL);
}

void GPIO_inpDetect(GPIO_input_t* inp)
{
    static GPIO_inp_type inpOld = 0;
    
    if(inp)
    {
        readInp(&(inp->state));
        
        inp->rising = ~inpOld & inp->state;
        inp->falling = inpOld & ~inp->state;

        inpOld = inp->state;
    }
    else readInp(&inpOld);
}


typedef uint8_t debounceCntr_t;
/*const debounceCntr_t*/ #define debounceCntr_min (0)
/*const debounceCntr_t*/ #define debounceCntr_max (0xFF)
/*const debounceCntr_t*/ #define debounceCntr_mid (debounceCntr_max >> 1)

void readInp(GPIO_inp_type* inp)
{
    static debounceCntr_t cntBtn = debounceCntr_mid;
    static GPIO_inp_type inpState = GPIO_INP_BUTTON;
    
    if(GPIO_BUTTON)
    {
        if(cntBtn < debounceCntr_max) ++cntBtn;
        else inpState |= GPIO_INP_BUTTON;
    }
    else
    {
        if(cntBtn > debounceCntr_min) --cntBtn;
        else inpState &= ~GPIO_INP_BUTTON;
    }

#if(PRJ_PROGIO_IN)
    if (GPIO_PROGIO) inpState |= GPIO_INP_PROGIO;
    else inpState &= ~GPIO_INP_PROGIO;
#endif
    
    if(inp) *inp = inpState;
}
