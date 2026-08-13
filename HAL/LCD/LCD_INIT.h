#ifndef HAL_LCD_INIT_H_
#define HAL_LCD_INIT_H_

#include "../../STD_TYPES.h"



// LCD rows
#define LCD_LINE_ONE                1
#define LCD_LINE_SECOND             2


// LCD shift directions
#define LCD_SHIFT_LEFT              0
#define LCD_SHIFT_RIGHT             1


// LCD initialization
void LCD_voidInit(void);

// LCD commands
void LCD_voidSendCommand(uint8_t Copy_u8Command);
void LCD_voidClearScreen(void);
void LCD_voidGoToPosition(uint8_t Copy_u8Row,uint8_t Copy_u8Column);


// LCD data
void LCD_voidSendChar(uint8_t Copy_u8Char);
void LCD_voidSendString(uint8_t* Copy_u8String, uint8_t Copy_u8Size);
void LCD_voidSendNumber(uint32_t Copy_u32Number);




#endif /* HAL_LCD_INIT_H_ */
