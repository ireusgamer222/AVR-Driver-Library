#ifndef HAL_LCD_CMD_H_
#define HAL_LCD_CMD_H_

// Function Set
#define LCD_FUNCTION_SET_8_BIT      0b00111000
#define LCD_FUNCTION_SET_4_BIT      0b00101000

// Display Control
#define LCD_DISPLAY_ON              0b00001100
#define LCD_DISPLAY_OFF             0b00001000

// Clear Display
#define LCD_CLEAR_DISPLAY           0b00000001

// Return Home
#define LCD_RETURN_HOME             0b00000010

// Entry Mode
#define LCD_ENTRY_MODE              0b00000110

// DDRAM
#define LCD_SET_DDRAM_ADDRESS       0b10000000
#define LCD_SECOND_LINE_ADDRESS     0b01000000


#endif /* HAL_LCD_CMD_H_ */
