#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/* Sense Control Options */
#define EXTI_LOW_LEVEL           0
#define EXTI_ON_CHANGE           1
#define EXTI_FALLING_EDGE        2
#define EXTI_RISING_EDGE         3

/* Initial Sense Control Configuration */
#define EXTI_INT0_SENSE          EXTI_FALLING_EDGE
#define EXTI_INT1_SENSE          EXTI_FALLING_EDGE
#define EXTI_INT2_SENSE          EXTI_FALLING_EDGE   /* INT2 only supports FALLING or RISING */

/* Enable/Disable Options */
#define EXTI_DISABLE             0
#define EXTI_ENABLE              1

/* Initial Enable States */
#define EXTI_INT0_INITIAL_STATE  EXTI_ENABLE
#define EXTI_INT1_INITIAL_STATE  EXTI_DISABLE
#define EXTI_INT2_INITIAL_STATE  EXTI_DISABLE

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
