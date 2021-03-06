/*
\author         Oliver Blaser
\date           15.08.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#ifndef IG_PROJECT_H
#define	IG_PROJECT_H


#define PRJ_VERSION_MAJ (1)
#define PRJ_VERSION_MIN (0)


#define PRJ_DEBUG (1)
#define PRJ_DEBUG_UART (0)
#define PRJ_HWTEST (1)


#define PRJ_PROGIO_MODE_OFF (0)
#define PRJ_PROGIO_MODE_IN (1)
#define PRJ_PROGIO_MODE_OUT (2)
#define PRJ_PROGIO_MODE_CLKOUT (3)

#define PRJ_PROGIO_MODE PRJ_PROGIO_MODE_OUT

#define PRJ_PROGIO_IN (PRJ_PROGIO_MODE == PRJ_PROGIO_MODE_IN)
#define PRJ_PROGIO_OUT (PRJ_PROGIO_MODE == PRJ_PROGIO_MODE_OUT)
#define PRJ_PROGIO_CLKOUT (PRJ_PROGIO_MODE == PRJ_PROGIO_MODE_CLKOUT)


// config check
#if(!PRJ_DEBUG && (PRJ_DEBUG_UART || (PRJ_PROGIO_MODE != PRJ_PROGIO_MODE_OFF) || PRJ_HWTEST))
#error invalid config
#endif

#endif // IG_PROJECT_H
