/*
 * RTOS_INT.h
 *
 *  Created on: Aug 5, 2026
 *      Author: dell
 */

#ifndef OS_RTOS_RTOS_INT_H_
#define OS_RTOS_RTOS_INT_H_


void RTOS_voidInit(void);

u8 RTOS_u8CreateTask(void (*Copy_pTaskFunc)(void), u16 Copy_u16Periodicity, u8 Copy_u8Priority, u16 Copy_u16FirstDelay);




#endif /* OS_RTOS_RTOS_INT_H_ */
