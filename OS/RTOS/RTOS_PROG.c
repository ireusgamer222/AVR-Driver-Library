/*
 * RTOS_PROG.c
 *
 *  Created on: Aug 5, 2026
 *      Author: dell
 */

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

#include "../../MCAL/TIMERS/TIMER0_INT.h"
#include "../../MCAL/INTERRUPTS/GLBI_INT.h"

#include "RTOS_CONFIG.h"
#include "RTOS_PRIVATE.h"
#include "RTOS_INT.h"

static TCB RTOS_Tasks[RTOS_MAX_TASKS];


void RTOS_voidInit(void){



	 TIMER0_voidCTCSetCallBack(&RTOS_voidScheduler);

	 TIMER0_voidInit();
	 TIMER0_voidEnable();
	 GLBI_voidEnableGlobal();
}



u8 RTOS_u8CreateTask(void (*Copy_pTaskFunc)(void), u16 Copy_u16Periodicity, u8 Copy_u8Priority, u16 Copy_u16FirstDelay){
	u8 Local_u8ErrorState = E_NOT_OK;

	    if((Copy_u8Priority < RTOS_MAX_TASKS) && (Copy_pTaskFunc != NULL)){
	        RTOS_Tasks[Copy_u8Priority].TaskFunc = Copy_pTaskFunc;
	        RTOS_Tasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	        RTOS_Tasks[Copy_u8Priority].DelayTicks = Copy_u16FirstDelay;
	        RTOS_Tasks[Copy_u8Priority].Priority = Copy_u8Priority;

	        Local_u8ErrorState = E_OK;
	    }

	    return Local_u8ErrorState;
}




static void RTOS_voidScheduler(void){
    for(u8 i = 0; i < RTOS_MAX_TASKS;i++){
        if(RTOS_Tasks[i].TaskFunc != NULL){
            if(RTOS_Tasks[i].DelayTicks == 0){
                RTOS_Tasks[i].TaskFunc();
                RTOS_Tasks[i].DelayTicks = RTOS_Tasks[i].Periodicity - 1;
            }
            else{
                RTOS_Tasks[i].DelayTicks--;
            }
        }
    }

}
