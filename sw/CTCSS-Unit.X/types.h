/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_TYPES_H
#define	IG_TYPES_H

#include <stdint.h>



#ifndef __DEFINED_size_t
typedef unsigned size_t;
#define __DEFINED_size_t
#endif
#ifndef SIZE_T_MIN
#define SIZE_T_MIN (0)
#endif
#ifndef SIZE_T_MAX
#define SIZE_T_MAX ((size_t)-1)
#endif



#define TASK_OK ((TASK_status_t)0)

#define TASK_TAPP ((TASK_status_t)0x80)
#define TASK_TCWLED ((TASK_status_t)0x40)

#define TASK_ERR ((TASK_status_t)0x01)
#define TASK_STATE ((TASK_status_t)0x02)


typedef uint8_t TASK_status_t;



#endif // IG_TYPES_H

