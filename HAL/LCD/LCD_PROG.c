#include <util/delay.h>
#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h"
#include "LCD_INIT.h"
#include "LCD_CMD.h"
#include "LCD_CONFIG.h"


void LCD_voidInit(void){

    DIO_setPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
    DIO_setPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, DIO_PIN_OUTPUT);
    DIO_setPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);


	#if LCD_MODE == LCD_8_BIT_MODE
    	DIO_setPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	#elif LCD_MODE == LCD_4_BIT_MODE
    	DIO_setPinDirection(LCD_DATA_PORT, LCD_D4_PIN, DIO_PIN_OUTPUT);
    	DIO_setPinDirection(LCD_DATA_PORT, LCD_D5_PIN, DIO_PIN_OUTPUT);
    	DIO_setPinDirection(LCD_DATA_PORT, LCD_D6_PIN, DIO_PIN_OUTPUT);
    	DIO_setPinDirection(LCD_DATA_PORT, LCD_D7_PIN, DIO_PIN_OUTPUT);
	#endif

    DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
    DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
    DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
    _delay_ms(40);


	#if LCD_MODE == LCD_8_BIT_MODE
    	LCD_voidSendCommand(LCD_FUNCTION_SET_8_BIT);
    	_delay_ms(2);
	#elif LCD_MODE == LCD_4_BIT_MODE

    	LCD_voidwriteHalfPort(0b00000011);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
    	_delay_ms(5);


    	LCD_voidwriteHalfPort(0b00000011);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
    	_delay_us(150);


    	LCD_voidwriteHalfPort(0b00000011);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
    	_delay_us(150);


    	LCD_voidwriteHalfPort(0b00000010);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
    	_delay_us(150);


    	LCD_voidSendCommand(LCD_FUNCTION_SET_4_BIT);
	#endif


    LCD_voidSendCommand(LCD_DISPLAY_ON);
    _delay_ms(2);

    LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
    _delay_ms(2);

    LCD_voidSendCommand(LCD_ENTRY_MODE);
    _delay_ms(2);
}


void LCD_voidSendCommand(uint8_t Command){

    DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);
    DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);

	#if LCD_MODE == LCD_8_BIT_MODE
    	DIO_setPortValue(LCD_DATA_PORT, Command);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	#elif LCD_MODE == LCD_4_BIT_MODE
    	LCD_voidwriteHalfPort(Command >> 4);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

    	LCD_voidwriteHalfPort(Command & 0x0F);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	#endif


    if((Command == LCD_CLEAR_DISPLAY) || (Command == LCD_RETURN_HOME)){
        _delay_ms(2);
    }
    else{
        _delay_us(50);
    }
}


void LCD_voidClearScreen(void){
    LCD_voidSendCommand(LCD_CLEAR_DISPLAY);
    _delay_ms(2);
}


void LCD_voidGoToPosition(uint8_t Row, uint8_t Column){

    uint8_t Address = 0;

    if(Row == LCD_LINE_ONE){
        Address = Column;
    }
    else if(Row == LCD_LINE_SECOND){

        Address = LCD_SECOND_LINE_ADDRESS + Column;

    }
    LCD_voidSendCommand(LCD_SET_DDRAM_ADDRESS | Address);
}


void LCD_voidwriteHalfPort(uint8_t Copy_u8Value){
    DIO_setPinValue(LCD_DATA_PORT, LCD_D4_PIN, Copy_u8Value & 0b00000001);
    DIO_setPinValue(LCD_DATA_PORT, LCD_D5_PIN, (Copy_u8Value >> 1) & 0b00000001);
    DIO_setPinValue(LCD_DATA_PORT, LCD_D6_PIN, (Copy_u8Value >> 2) & 0b00000001);
    DIO_setPinValue(LCD_DATA_PORT, LCD_D7_PIN, (Copy_u8Value >> 3) & 0b00000001);
}


void LCD_voidSendNumber(uint32_t Number){
    if(Number >= 10){
        LCD_voidSendNumber(Number / 10);
    }
    LCD_voidSendChar((Number % 10) + '0');
}


void LCD_voidSendChar(uint8_t Char){

    DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
    DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);


	#if LCD_MODE == LCD_8_BIT_MODE
    	DIO_setPortValue(LCD_DATA_PORT, Char);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);

	#elif LCD_MODE == LCD_4_BIT_MODE

    	LCD_voidwriteHalfPort(Char >> 4);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);


    	LCD_voidwriteHalfPort(Char & 0x0F);

    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
    	_delay_us(1);
    	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
	#endif
    _delay_us(50);
}


void LCD_voidSendString(uint8_t* Copy_u8String, uint8_t Copy_u8Size){
    uint8_t i = 0;
    for(i = 0; i < Copy_u8Size; i++){
        LCD_voidSendChar(Copy_u8String[i]);
    }
}




void LCD_voidCreateCustomChar(uint8_t* Copy_u8Pattern, uint8_t Copy_u8Location) {
    uint8_t Local_u8Iterator = 0;
    if (Copy_u8Location < 8) {
        LCD_voidSendCommand(0x40 + (Copy_u8Location * 8));

        for (Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++) {
            LCD_voidSendChar(Copy_u8Pattern[Local_u8Iterator]);
        }
    }
}
