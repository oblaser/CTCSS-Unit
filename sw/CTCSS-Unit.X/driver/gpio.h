/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_GPIO_H
#define IG_GPIO_H

#include "../types.h"
#include "../project.h"
#include "hardware_16F1825.h"

#define GPIO_BUTTON PORTCbits.RC2
#define GPIO_BUTTON_PORT PORTC
#define GPIO_BUTTON_PIN (1 << 2)

#define GPIO_LED LATAbits.LATA5
#define GPIO_LED_PORT LATA
#define GPIO_LED_PIN (1 << 5)

#if (PRJ_PROGIO_IN || PRJ_PROGIO_OUT)
#if PRJ_PROGIO_IN
#define GPIO_PROGIO PORTAbits.RA4
#define GPIO_PROGIO_PORT PORTA
#else
#define GPIO_PROGIO LATAbits.LATA4
#define GPIO_PROGIO_PORT LATA
#endif
#define GPIO_PROGIO_PIN (1 << 4)
#endif

#if(PRJ_PROGIO_IN)
#define GPIO_INP_PROGIO ((GPIO_inp_type)0x01)
#endif
#define GPIO_INP_BUTTON ((GPIO_inp_type)0x02)

typedef uint8_t GPIO_inp_type;
typedef struct
{
    GPIO_inp_type state;   // current state
    GPIO_inp_type rising;  // rising edge
    GPIO_inp_type falling; // falling edge
} GPIO_input_t;

void GPIO_init();

void GPIO_inpDetect(GPIO_input_t* inp);

#endif // IG_GPIO_H
