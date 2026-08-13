/*
 * KEYPAD_PROG.c
 *
 *  Created on: Jul 21, 2026
 *      Author: dell
 */

#include "../../STD_TYPES.h"
#include "../../MCAL/DIO_INIT.h"
#include <util/delay.h>
#include "KEYPAD_INIT.h"

const uint8_t KEYPAD[4][4] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};
const uint8_t KeypadRows[4] = {KEYPAD_ROW0_PIN, KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN};
const uint8_t KeypadCols[4] = {KEYPAD_COL0_PIN, KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN};


void KEYPAD_voidInit(void){

    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_PIN_OUTPUT);
    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_PIN_OUTPUT);
    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_PIN_OUTPUT);
    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_PIN_OUTPUT);

    DIO_setPinValue(KEYPAD_PORT, KEYPAD_ROW0_PIN, DIO_PIN_HIGH);
    DIO_setPinValue(KEYPAD_PORT, KEYPAD_ROW1_PIN, DIO_PIN_HIGH);
    DIO_setPinValue(KEYPAD_PORT, KEYPAD_ROW2_PIN, DIO_PIN_HIGH);
    DIO_setPinValue(KEYPAD_PORT, KEYPAD_ROW3_PIN, DIO_PIN_HIGH);



    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_COL0_PIN, DIO_PIN_INPUT);
    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_COL1_PIN, DIO_PIN_INPUT);
    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_COL2_PIN, DIO_PIN_INPUT);
    DIO_setPinDirection(KEYPAD_PORT, KEYPAD_COL3_PIN, DIO_PIN_INPUT);

    DIO_PinactivePullUpResistance(KEYPAD_PORT, KEYPAD_COL0_PIN);
    DIO_PinactivePullUpResistance(KEYPAD_PORT, KEYPAD_COL1_PIN);
    DIO_PinactivePullUpResistance(KEYPAD_PORT, KEYPAD_COL2_PIN);
    DIO_PinactivePullUpResistance(KEYPAD_PORT, KEYPAD_COL3_PIN);
}



uint8_t KEYPAD_getPressedKey(void){

    uint8_t Local_PinValue = 0;
    uint8_t Local_PressedKey = KEYPAD_NOT_PRESSED;

    for (uint8_t Local_RowIndex = 0; Local_RowIndex < 4; Local_RowIndex++){

        DIO_setPinValue(KEYPAD_PORT, KeypadRows[Local_RowIndex], DIO_PIN_LOW);



        for (uint8_t Local_ColIndex = 0; Local_ColIndex < 4; Local_ColIndex++){

            DIO_getPinValue(KEYPAD_PORT, KeypadCols[Local_ColIndex], &Local_PinValue);
            if (Local_PinValue == DIO_PIN_LOW){

                _delay_ms(20);
                while (Local_PinValue == DIO_PIN_LOW){
                    DIO_getPinValue(KEYPAD_PORT, KeypadCols[Local_ColIndex], &Local_PinValue);
                }

                Local_PressedKey = KEYPAD[Local_RowIndex][Local_ColIndex];
                DIO_setPinValue(KEYPAD_PORT, KeypadRows[Local_RowIndex], DIO_PIN_HIGH);
                return Local_PressedKey;
            }
        }



        DIO_setPinValue(KEYPAD_PORT, KeypadRows[Local_RowIndex], DIO_PIN_HIGH);
    }

    return KEYPAD_NOT_PRESSED;
}
