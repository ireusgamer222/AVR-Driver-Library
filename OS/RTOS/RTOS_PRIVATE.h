/*
 * RTOS_PRIVATE.h
 *
 *  Created on: Aug 5, 2026
 *      Author: dell
 */

#ifndef OS_RTOS_RTOS_PRIVATE_H_
#define OS_RTOS_RTOS_PRIVATE_H_


/* TCB */
typedef struct {
    void (*TaskFunc)(void);
    u16 Periodicity;
    u16 DelayTicks;
    u8 Priority;
} TCB;
static void RTOS_voidScheduler(void);

#endif /* OS_RTOS_RTOS_PRIVATE_H_ */
