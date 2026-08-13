#ifndef MCAL_EXTI_INIT_H_
#define MCAL_EXTI_INIT_H_

#include "../../STD_TYPES.h"


#define EXTI_INT0           0
#define EXTI_INT1           1
#define EXTI_INT2           2


// External Interrupt Control Function Prototypes
void EXTI_voidInit(void);
void EXTI_voidEnable(uint8_t Copy_u8InterruptID);
void EXTI_voidDisable(uint8_t Copy_u8InterruptID);


// CallBack function
void EXTI_voidSetCallBack(uint8_t Copy_u8InterruptID, void (*Copy_pVoidCallBack)(void));


// Chagne mode
void EXTI_voidSetMODE(uint8_t Copy_u8InterruptID, uint8_t Copy_u8Mode);
#endif /* MCAL_EXTI_INIT_H_ */
