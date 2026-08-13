/*
 * sevenSegment.c
 *
 *  Created on: Jul 20, 2026
 *      Author: dell
 */


#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h"
#include "sevenSegment.h"


uint8_t NUMBERS[10] = {
    0x3F, /* 0 */
    0x06, /* 1 */
    0x5B, /* 2 */
    0x4F, /* 3 */
    0x66, /* 4 */
    0x6D, /* 5 */
    0x7D, /* 6 */
    0x07, /* 7 */
    0x7F, /* 8 */
    0x6F  /* 9 */
};

void SSD_voidInit(void){

    DIO_setPortDirection(SSD_PORT, DIO_PORT_OUTPUT);
    DIO_setPortValue(SSD_PORT, 0x00);
}

void SSD_displayDigit(uint8_t INPUT){

    if (INPUT <= 9){
        DIO_setPortValue(SSD_PORT, NUMBERS[INPUT]);
    }
}


