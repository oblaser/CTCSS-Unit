/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_CWLED_H
#define IG_CWLED_H

#include "../types.h"

void CWLED_task(TASK_status_t* ts);

void CWLED_timeHandler();

void CWLED_write(const char* str, size_t count);

#endif // IG_CWLED_H
