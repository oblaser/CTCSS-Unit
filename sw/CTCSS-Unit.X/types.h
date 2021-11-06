/*
\author         Oliver Blaser
\date           21.09.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_TYPES_H
#define	IG_TYPES_H

#include <stddef.h>
#include <stdint.h>



#define TASK_OK ((TASK_status_t)0)

#define TASK_TAPP ((TASK_status_t)0x80)
#define TASK_TCWLED ((TASK_status_t)0x40)

#define TASK_ERR ((TASK_status_t)0x01)
#define TASK_STATE ((TASK_status_t)0x02)


typedef uint8_t TASK_status_t;



#endif // IG_TYPES_H

