/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_HARDWARE_16F1825_H
#define IG_HARDWARE_16F1825_H

#include <xc.h>
#include <pic16f1825.h>

void HW_init();

void HW_gieSet();
void HW_gieClr();

void HW_wdtEnable();
void HW_wdtDisable();
void HW_wdtClr();

#endif // IG_HARDWARE_16F1825_H
