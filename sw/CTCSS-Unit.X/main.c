/*
\author         Oliver Blaser
\date           06.11.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#include "application/appMain.h"
#include "driver/hardware_16F1825.h"
#include "driver/gpio.h"
#include "middleware/cwLed.h"
#include "middleware/util.h"
#include "middleware/ctcss.h"



void errorHandler(const TASK_status_t* ts);
void TMR0_isr();

int main()
{   
    HW_init();
    HW_wdtEnable();
    GPIO_init();
    CTCSS_init();
    
    HW_gieSet();
    
#if PRJ_PROGIO_OUT
    GPIO_PROGIO = 0;
    for(int i = 0; i < 10; ++i) HW_wdtClr();
    GPIO_PROGIO = 1;
    for(int i = 0; i < 10; ++i) HW_wdtClr();
    GPIO_PROGIO = 0;
#endif
    
#if PRJ_HWTEST
    
    CTCSS_setTone(CTCSS_ID_77_0);
    
    while(1)
    {
        HW_wdtClr();
        
        GPIO_input_t inp;
        GPIO_inpDetect(&inp);
        
        if(inp.falling & GPIO_INP_BUTTON)
        {
            GPIO_LED_PORT ^= GPIO_LED_PIN;
            
            if(GPIO_LED_PORT & GPIO_LED_PIN) CTCSS_setTone(CTCSS_ID_254_1);
            else CTCSS_setTone(CTCSS_ID_77_0);
        }
    }
#endif
    
#if (PRJ_DEBUG_UART)
    UART_print_blocking("\n-===# started #===-\n");
#endif
    
    static TASK_status_t ts = TASK_OK;
    
    while(1)
    {
        HW_wdtClr();
        
        errorHandler(&ts);
        
        ts = TASK_OK;
        
        APP_task(&ts);
        CWLED_task(&ts);
    }
    
    return 0;
}

void __interrupt() global_isr()
{
    // ~10ms (9.984ms)
    if(T0IE && T0IF)
    {
        TMR0 = 100;
        T0IF = 0;
        
        APP_timeHandler();
        CWLED_timeHandler();
    }
    
    if(TMR4IE && TMR4IF)
    {
        TMR4IF = 0;
        
        CCPR2L = CTCSS_lut[CTCSS_accumulator >> 8];
        CTCSS_accumulator += CTCSS_increment;
    }
}



void errorHandler(const TASK_status_t* ts)
{
    if(*ts)
    {
        //COM_sendTaskError(ts);
        
#if PRJ_DEBUG_UART
        UART_print_wait("task error: ");
        UART_print_wait(UTIL_itoap(*ts));
        UART_print_wait("\n");
#endif
        
        while(1)
        {
            HW_wdtClr();
            
            
        }
    }
}
