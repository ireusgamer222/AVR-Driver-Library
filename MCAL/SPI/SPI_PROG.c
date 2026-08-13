/*
 * SPI_PROG.c
 *
 *  Created on: Aug 2, 2026
 *      Author: dell
 */


// SPI_PROG.c
// Created on: Aug 2, 2026

#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "SPI_REG.h"
#include "SPI_CONFIG.h"
#include "SPI_PRIVATE.h"
#include "SPI_INT.h"

static volatile void (*SPI_INTERRUPT_CallBack)(void) = NULL;

void SPI_voidInit(void) {

    // Temp variables to hold adjustment to assign in one clock cycle
    uint8_t Local_u8SPCR = 0;
    uint8_t Local_u8SPSR = 0;


    // Configure Data Order LSB OR MSB FIRST
    #if SPI_DATA_ORDER == SPI_DATA_ORDER_LSB_FIRST
        SET_BIT(Local_u8SPCR, SPI_DORD_BIT);
    #else
        CLR_BIT(Local_u8SPCR, SPI_DORD_BIT);
    #endif



    // MCU Master or Slave Mode
    #if SPI_MODE == SPI_MASTER_MODE
        SET_BIT(Local_u8SPCR, SPI_MSTR_BIT);
    #else
        CLR_BIT(Local_u8SPCR, SPI_MSTR_BIT);
    #endif

    // Clock Polarity Code
    #if SPI_CPOL == SPI_CPOL_IDLE_HIGH
        SET_BIT(Local_u8SPCR, SPI_CPOL_BIT);
    #else
        CLR_BIT(Local_u8SPCR, SPI_CPOL_BIT);
    #endif


    // Clock Phase
    #if SPI_CPHA == SPI_CPHA_SETUP_LEADING
        SET_BIT(Local_u8SPCR, SPI_CPHA_BIT);
    #else
        CLR_BIT(Local_u8SPCR, SPI_CPHA_BIT);
    #endif

    // Clock Prescaler
    #if SPI_PRESCALER == SPI_PRESCALER_4
        CLR_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        CLR_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        CLR_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_16
        CLR_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        SET_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        CLR_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_64
        SET_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        CLR_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        CLR_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_128
        SET_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        SET_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        CLR_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_2_2X
        CLR_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        CLR_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        SET_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_8_2X
        CLR_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        SET_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        SET_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_32_2X
        SET_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        CLR_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        SET_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #elif SPI_PRESCALER == SPI_PRESCALER_64_2X
        SET_BIT(Local_u8SPCR, SPI_SPR1_BIT);
        SET_BIT(Local_u8SPCR, SPI_SPR0_BIT);
        SET_BIT(Local_u8SPSR, SPI_SPI2X_BIT);
    #endif


    // SPI Interrupt Int State
    #if SPI_INTERRUPT == SPI_INTERRUPT_ENABLE
        SET_BIT(Local_u8SPCR, SPI_SPIE_BIT);
    #else
        CLR_BIT(Local_u8SPCR, SPI_SPIE_BIT);
    #endif


    // Enable the SPI Peripheral
    SET_BIT(Local_u8SPCR, SPI_SPE_BIT);

    // Apply the temp variables to registers in one clock cycle
    SPI_SPSR_REG = Local_u8SPSR;
    SPI_SPCR_REG = Local_u8SPCR;
}

void SPI_voidEnable(void) {
    // Enable the SPI
    SET_BIT(SPI_SPCR_REG, SPI_SPE_BIT);
}

void SPI_voidDisable(void) {
    // Disable the SPI
    CLR_BIT(SPI_SPCR_REG, SPI_SPE_BIT);
}



uint8_t SPI_u8TransmitDataSync(uint8_t Copy_u8Data) {
    SPI_SPDR_REG = Copy_u8Data;
    while (GET_BIT(SPI_SPSR_REG, SPI_SPIF_BIT) == 0);
    return SPI_SPDR_REG;
}

uint8_t SPI_u8ReadDataReg(void) {
    return SPI_SPDR_REG;
}

void SPI_vidWriteDataReg(uint8_t Copy_u8Data) {
    SPI_SPDR_REG = Copy_u8Data;
}


void SPI_voidInterruptEnable(void) {
    // Enable the SPI Interrupt
    SET_BIT(SPI_SPCR_REG, SPI_SPIE_BIT);
}
void SPI_voidInterruptDisable(void) {
	// Disable the SPI Interrupt
    CLR_BIT(SPI_SPCR_REG, SPI_SPIE_BIT);
}


void SPI_voidSetCallBack(volatile void (*Copy_pVoidCallBack)(void)) {
    if (Copy_pVoidCallBack != NULL) {
        SPI_INTERRUPT_CallBack = Copy_pVoidCallBack;
    }
}



// ISR FUNCTION for SPI
void __vector_12(void) __attribute__((signal));
void __vector_12(void) {
    if (SPI_INTERRUPT_CallBack != NULL) {
        SPI_INTERRUPT_CallBack();
    }
}
