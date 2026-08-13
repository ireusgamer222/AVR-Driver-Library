#ifndef HAL_LCD_CONFIG_H_
#define HAL_LCD_CONFIG_H_

// LCD mode
#define LCD_8_BIT_MODE              1
#define LCD_4_BIT_MODE              2

#define LCD_MODE                    LCD_8_BIT_MODE


// LCD control pins
#define LCD_CTRL_PORT               DIO_PORTB

#define LCD_RS_PORT                 DIO_PORTB
#define LCD_RS_PIN                  DIO_PIN7

#define LCD_RW_PORT                 DIO_PORTB
#define LCD_RW_PIN                  DIO_PIN6

#define LCD_EN_PORT                 DIO_PORTB
#define LCD_EN_PIN                  DIO_PIN5


// LCD data port
#define LCD_DATA_PORT               DIO_PORTA


// LCD data pins
#define LCD_D0_PIN                  DIO_PIN0
#define LCD_D1_PIN                  DIO_PIN1
#define LCD_D2_PIN                  DIO_PIN2
#define LCD_D3_PIN                  DIO_PIN3

#define LCD_D4_PIN                  DIO_PIN4
#define LCD_D5_PIN                  DIO_PIN5
#define LCD_D6_PIN                  DIO_PIN6
#define LCD_D7_PIN                  DIO_PIN7


// LCD dimensions
#define LCD_NUMBER_OF_COLUMNS       16
#define LCD_NUMBER_OF_ROWS          2

#endif /* HAL_LCD_CONFIG_H_ */
