/*
 * USART_PROG.c
 * Created on: Aug 1, 2026
 * Author: dell
 */
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "USART_REG.h"
#include "USART_CONFIG.h"
#include "USART_PRIVATE.h"
#include "USART_INT.h"

static void (*RX_INTERRUPT_CallBack)(void) = NULL;
static void (*TX_INTERRUPT_CallBack)(void) = NULL;
static void (*UDREmpty_INTERRUPT_CallBack)(void) = NULL;

void USART_voidInit(void) {

    // Set Baud Rate by splitting the values into two 8 bit variables
    USART_UBRRH_REG = (uint8_t) ( (USART_UBRR_VALUE >> 8) & 0x0F);
    USART_UBRRL_REG = (uint8_t) USART_UBRR_VALUE;

    // Double Speed Asynchronous Mode Selection
    #if USART_MODE == USART_MODE_ASYNC
        #if USART_DOUBLE_SPEED == USART_DOUBLE_SPEED_ENABLE
            SET_BIT(USART_UCSRA_REG, USART_U2X_BIT);
		#else
            CLR_BIT(USART_UCSRA_REG, USART_U2X_BIT);
		#endif
	#else
            // U2X must be cleared when operating in Synchronous mode
            CLR_BIT(USART_UCSRA_REG, USART_U2X_BIT);
	#endif




    uint8_t Local_u8UCSRC = 0;
    // Configure UCSRC Register (URSEL BIT MUST BE 1 to write to UCSRC (REGISTER SELECT) )
    SET_BIT(Local_u8UCSRC, USART_URSEL_BIT);

    // Mode Selection: SYNC or ASYNC MODES
    #if USART_MODE == USART_MODE_ASYNC
        CLR_BIT(Local_u8UCSRC, USART_UMSEL_BIT);
    #elif USART_MODE == USART_MODE_SYNC
        SET_BIT(Local_u8UCSRC, USART_UMSEL_BIT);
    #endif

    // Parity Selection
    #if USART_PARITY == USART_PARITY_DISABLE
        CLR_BIT(Local_u8UCSRC, USART_UPM1_BIT);
        CLR_BIT(Local_u8UCSRC, USART_UPM0_BIT);
    #elif USART_PARITY == USART_PARITY_EVEN
        SET_BIT(Local_u8UCSRC, USART_UPM1_BIT);
        CLR_BIT(Local_u8UCSRC, USART_UPM0_BIT);
    #elif USART_PARITY == USART_PARITY_ODD
        SET_BIT(Local_u8UCSRC, USART_UPM1_BIT);
        SET_BIT(Local_u8UCSRC, USART_UPM0_BIT);
    #endif

    // Stop Bit Selection
    #if USART_STOP_BITS == USART_STOP_1_BIT
        CLR_BIT(Local_u8UCSRC, USART_USBS_BIT);
    #elif USART_STOP_BITS == USART_STOP_2_BIT
        SET_BIT(Local_u8UCSRC, USART_USBS_BIT);
    #endif



    // Data Bits Selection, BIT Masking first, then getting the two first bits by AND
    uint8_t Local_u8DataSize = USART_DATA_BITS & 0b00000011;
    Local_u8UCSRC |= (Local_u8DataSize << 1);


    // Write the calculated bit value to UCSRC in one clock cycle
    USART_UCSRC_REG = Local_u8UCSRC;




    // the UCSZ2 bit in UCSRB REGISTER for 9 bit data size
    #if USART_DATA_BITS == USART_DATA_9_BIT
        SET_BIT(USART_UCSRB_REG, USART_UCSZ2_BIT);
    #else
        CLR_BIT(USART_UCSRB_REG, USART_UCSZ2_BIT);
    #endif



    // Enable RX Complete Interrupt
    #if USART_RX_INTERRUPT == USART_INTERRUPT_ENABLE
        SET_BIT(USART_UCSRB_REG, USART_RXCIE_BIT);
    #else
        CLR_BIT(USART_UCSRB_REG, USART_RXCIE_BIT);
    #endif

    // Enable TX Complete Interrupt
    #if USART_TX_INTERRUPT == USART_INTERRUPT_ENABLE
       SET_BIT(USART_UCSRB_REG, USART_TXCIE_BIT);
    #else
       CLR_BIT(USART_UCSRB_REG, USART_TXCIE_BIT);
    #endif


    // Enable TX AND RX
    SET_BIT(USART_UCSRB_REG, USART_TXEN_BIT);
    SET_BIT(USART_UCSRB_REG, USART_RXEN_BIT);
}


void USART_voidRXEnable(void){
	// Enable RX
	SET_BIT(USART_UCSRB_REG, USART_RXEN_BIT);
}
void USART_voidRXDisable(void){
	// Disable RX
	CLR_BIT(USART_UCSRB_REG, USART_RXEN_BIT);
}


void USART_voidTXEnable(void){
	// Enable TX
	SET_BIT(USART_UCSRB_REG, USART_TXEN_BIT);
}
void USART_voidTXDisable(void){
	// Disable TX
	CLR_BIT(USART_UCSRB_REG, USART_TXEN_BIT);
}




void USART_voidRXInterruptEnable(void) {
	// Enable RX Complete Interrupt
    SET_BIT(USART_UCSRB_REG, USART_RXCIE_BIT);
}

void USART_voidRXInterruptDisable(void) {
    // Disable RX Complete Interrupt
    CLR_BIT(USART_UCSRB_REG, USART_RXCIE_BIT);
}


void USART_voidTXInterruptEnable(void){
	// Enable TX Complete Interrupt
	SET_BIT(USART_UCSRB_REG, USART_TXCIE_BIT);
}
void USART_voidTXInterruptDisable(void){
	// Disable TX Complete Interrupt
    CLR_BIT(USART_UCSRB_REG, USART_TXCIE_BIT);
}


void USART_voidUDREmptyInterruptEnable(void){
	// Enable UDR Empty Interrupt
	SET_BIT(USART_UCSRB_REG, USART_UDRIE_BIT);
}
void USART_voidUDREmptyInterruptDisable(void){
	// Disable UDR Empty Interrupt
	CLR_BIT(USART_UCSRB_REG, USART_UDRIE_BIT);
}



uint8_t USART_u8ReceiveChar(void) {
    // Wait until the Receive Complete flag is set (RXC)
    while (GET_BIT(USART_UCSRA_REG, USART_RXC_BIT) == 0);

    // Read and return the data from UDR
    return USART_UDR_REG;
}

void USART_voidSendChar(uint8_t Copy_u8Data) {
    // Wait until the Data Register is empty (UDRE flag)
    while (GET_BIT(USART_UCSRA_REG, USART_UDRE_BIT) == 0);

    // Write the data to the UDR register to send it
    USART_UDR_REG = Copy_u8Data;
}






void USART_voidSendString(uint8_t *Copy_pu8String) {

    if (Copy_pu8String != NULL) {

        uint8_t Local_u8Index = 0;

        // Loop until the null terminator '\0' is found
        while (Copy_pu8String[Local_u8Index] != '\0') {

            USART_voidSendChar(Copy_pu8String[Local_u8Index]);
            Local_u8Index++;
        }
    }
}

void USART_voidSendNumber(sint32_t Copy_s32Number) {

    uint8_t Local_au8Digits[10];
    sint8_t Local_s8Idx = -1;
    uint8_t Local_u8IsNegative = 0;

    // Handle negative numbers
    if (Copy_s32Number < 0) {
        Local_u8IsNegative = 1;
        Copy_s32Number = -Copy_s32Number;
    }

    // If the number is exactly 0, just send '0'
    if (Copy_s32Number == 0) {
        USART_voidSendChar('0');
        return;
    }

    // Extract digits and store them in reverse order
    while (Copy_s32Number > 0) {
        Local_s8Idx++;
        Local_au8Digits[Local_s8Idx] = (Copy_s32Number % 10) + '0';
        Copy_s32Number /= 10;
    }

    // Send the negative sign if needed
    if (Local_u8IsNegative) {
        USART_voidSendChar('-');
    }

    // Send the digits in the correct order
    while (Local_s8Idx >= 0) {
        USART_voidSendChar(Local_au8Digits[Local_s8Idx]);
        Local_s8Idx--;
    }
}








void USART_voidReceiveString(uint8_t *Copy_pu8String, uint8_t Copy_u8MaxLen) {

    if (Copy_pu8String != NULL) {

        uint8_t Local_u8Idx = 0;
        uint8_t Local_u8Data = USART_u8ReceiveChar();

        while ((Local_u8Data != '\r') && (Local_u8Data != '\n') && (Local_u8Idx < (Copy_u8MaxLen - 1))) {
            Copy_pu8String[Local_u8Idx] = Local_u8Data;
            Local_u8Idx++;
            Local_u8Data = USART_u8ReceiveChar();
        }

        Copy_pu8String[Local_u8Idx] = '\0';
    }
}

sint32_t USART_s32ReceiveNumber(void) {

    uint8_t Local_u8Data;
    uint32_t Local_u32Result = 0;
    uint8_t Local_u8IsNegative = 0;

    Local_u8Data = USART_u8ReceiveChar();

    // Check for negative sign
    if (Local_u8Data == '-') {
        Local_u8IsNegative = 1;
        Local_u8Data = USART_u8ReceiveChar();
    }

    // Convert ASCII string to integer
    while ((Local_u8Data >= '0') && (Local_u8Data <= '9')) {
        Local_u32Result = (Local_u32Result * 10) + (Local_u8Data - '0');
        Local_u8Data = USART_u8ReceiveChar();
    }

    // Apply negative sign if needed and return
    if (Local_u8IsNegative) {
        return (sint32_t)(-Local_u32Result);
    }
    else {
        return (sint32_t)Local_u32Result;
    }
}











//  RX CALLBACK FUNCTION
void USART_voidRXCallBack(void (*Copy_pVoidCallBack)(void)) {
	if (Copy_pVoidCallBack != NULL) {
		RX_INTERRUPT_CallBack = Copy_pVoidCallBack;
	}
}

// UDR Empty CALLBACK FUNCTION
void USART_voidUDREmptyCallBack(void (*Copy_pVoidCallBack)(void)){
	if (Copy_pVoidCallBack != NULL) {
		UDREmpty_INTERRUPT_CallBack = Copy_pVoidCallBack;
	}
}

//  TX CALLBACK FUNCTION
void USART_voidTXCallBack(void (*Copy_pVoidCallBack)(void)) {
	if (Copy_pVoidCallBack != NULL) {
		TX_INTERRUPT_CallBack = Copy_pVoidCallBack;
	}
}


uint8_t USART_u8ReadERROR(void){
	return (USART_UCSRA_REG >> 2) & 0b00000111;
}



// ISR FUNCTIONS
// RX ISR FUNCTION
void __vector_13(void) __attribute__((signal));
void __vector_13(void) {
    if (RX_INTERRUPT_CallBack != NULL) {
    	RX_INTERRUPT_CallBack();
    }
}

// UDR Empty ISR FUNCTION
void __vector_14(void) __attribute__((signal));
void __vector_14(void) {
    if (UDREmpty_INTERRUPT_CallBack != NULL) {
    	UDREmpty_INTERRUPT_CallBack();
    }
}

// TX ISR FUNCTION
void __vector_15(void) __attribute__((signal));
void __vector_15(void) {
    if (TX_INTERRUPT_CallBack != NULL) {
    	TX_INTERRUPT_CallBack();
    }
}
