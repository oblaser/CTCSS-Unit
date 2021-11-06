/*
\author         Oliver Blaser
\date           06.11.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#include "../project.h"
#include "hardware_16F1825.h"

#include <xc.h>
#include <pic16f1825.h>

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = SWDTEN    // Watchdog Timer Enable (WDT controlled by the SWDTEN bit in the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = NSLEEP   // Brown-out Reset Enable (Brown-out Reset enabled while running and disabled in Sleep)
#if (PRJ_PROGIO_CLKOUT)
#pragma config CLKOUTEN = ON    // Clock Out Enable (CLKOUT function is enabled on the CLKOUT pin)
#else
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#endif
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), high trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)


void HW_init()
{
    //--------------------------------
    // 5.0 Oscillator Module
    //--------------------------------
    
    OSCCON = 0b01111010; // internal 16MHz
    
    //--------------------------------
    // 6.0 Reference Clock
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 8.0 Interrupts
    //--------------------------------
    
    INTCON  = 0b01100000; // peripheral timer0
    PIE1    = 0b00000000;
    PIE2    = 0b00000000;
    PIE3    = 0b00000010; // timer4
    
    //--------------------------------
    // 10.0 Watchdog Timer
    //--------------------------------
    
    WDTCON = 0b00001010; // 32ms timeout
    
    //--------------------------------
    // 11.0 EEPROM
    //--------------------------------
    
    // no changes needed
    
    //--------------------------------
    // 12.0 I/O PORTs
    //--------------------------------
    
    // gpio.h -> GPIO_init()
    
    //--------------------------------
    // 13.0 Interrupt-On-Change
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 14.0 Fixed Voltage Reference
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 16.0 ADC
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 17.0 DAC
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 18.0 SR Latch
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 19.0 Comparator
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 20.0 Timer0
    //--------------------------------
    
    OPTION_REG = 0b01010111; // WPU enabled / CS=Fosc/4 PS=1:256
    
    //--------------------------------
    // 21.0 Timer1
    //--------------------------------
    
    T1CON = 0b00000000; // off
    
    //--------------------------------
    // 22.0 Timer2/4/6
    //--------------------------------
    
    T4CON = 0b00000100; // pre and post scaler 1:1 / timer on
    PR4 = 0xFF; // PWM freq = 15.625 kHz
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 23.0 Data Signal Modulator
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 24.0 Capture/Compare/PWM
    //--------------------------------
    
    CCP2CON = 0b00001100; // PWM single output
    CCPTMRS = 0b00000100; // CCP2 is based of timer 4
    CCPR2L = 0;
    
    // disabled by default, no further changes needed
    
    //--------------------------------
    // 25.0 MSSP1/2
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 26.0 EUSART
    //--------------------------------
    
    // disabled by default, no changes needed
    
    //--------------------------------
    // 27.0 CPS
    //--------------------------------
    
    // disabled by default, no changes needed
}

void HW_gieSet()
{
    GIE = 1;
}

void HW_gieClr()
{
    GIE = 0;
}

void HW_wdtEnable()
{
    SWDTEN = 1;
}

void HW_wdtDisable()
{
    SWDTEN = 0;
}

void HW_wdtClr()
{
    asm("CLRWDT");
}
