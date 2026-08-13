/*
 * TWI_PRIVATE.h
 *
 *  Created on: Aug 3, 2026
 *      Author: dell
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

/* TWCR bit positions */
#define TWI_TWINT_BIT               7
#define TWI_TWEA_BIT                6
#define TWI_TWSTA_BIT               5
#define TWI_TWSTO_BIT               4
#define TWI_TWWC_BIT                3
#define TWI_TWEN_BIT                2
#define TWI_TWIE_BIT                0

/* TWSR bit positions */
#define TWI_TWPS0_BIT               0
#define TWI_TWPS1_BIT               1
#define TWI_PRESCALER_MASK			0b00000011
#define TWI_STATUS_MASK             0b11111000

/* TWAR bit positions */
#define TWI_TWGCE_BIT               0
#define TWI_TWA0_BIT                1

/* Status Codes */
#define TWI_STATUS_START            0x08    // A START condition has been transmitted
#define TWI_STATUS_REP_START        0x10    // A repeated START condition has been transmitted
#define TWI_STATUS_MT_SLA_ACK       0x18    // SLA+W has been transmitted; ACK has been received
#define TWI_STATUS_MT_SLA_NACK      0x20    // SLA+W has been transmitted; NOT ACK has been received
#define TWI_STATUS_MT_DATA_ACK      0x28    // Data byte has been transmitted; ACK has been received
#define TWI_STATUS_MT_DATA_NACK     0x30    // Data byte has been transmitted; NOT ACK has been received
#define TWI_STATUS_ARB_LOST         0x38    // Arbitration lost in SLA+W or data bytes



#define TWI_STATUS_MR_SLA_ACK       0x40    // SLA+R has been transmitted; ACK has been received
#define TWI_STATUS_MR_SLA_NACK      0x48    // SLA+R has been transmitted; NOT ACK has been received
#define TWI_STATUS_MR_DATA_ACK      0x50    // Data byte has been received; ACK has been returned
#define TWI_STATUS_MR_DATA_NACK     0x58    // Data byte has been received; NOT ACK has been returned



#define TWI_STATUS_SLA_REC_ACK			 0x60	//  Own SLA+W has been received; ACK has been returned
#define TWI_STATUS_SR_SLA_ARB_LOST_ACK   0x68
#define TWI_STATUS_SR_GC_ACK             0x70
#define TWI_STATUS_SR_GC_ARB_LOST_ACK    0x78
#define TWI_STATUS_SR_DATA_ACK           0x80
#define TWI_STATUS_SR_DATA_NACK          0x88




#define TWI_STATUS_ST_SLA_ACK       	 0xA8    // Own SLA+R has been received; ACK has been returned
#define TWI_STATUS_ST_ARB_LOST_SLA_ACK 	 0xB0
#define TWI_STATUS_ST_DATA_ACK      	 0xB8    // Data byte has been transmitted; ACK has been received
#define TWI_STATUS_ST_DATA_NACK     	 0xC0    // Data byte has been transmitted; NOT ACK has been received
#define TWI_STATUS_ST_LAST_DATA    		 0xC8    // Last data byte has been transmitted; ACK has been received



// PRESCALER SELECTION
#if TWI_PRESCALER == TWI_PRESCALER_1
    #define TWI_PRESCALE_VALUE  1UL
#elif TWI_PRESCALER == TWI_PRESCALER_4
    #define TWI_PRESCALE_VALUE  4UL
#elif TWI_PRESCALER == TWI_PRESCALER_16
    #define TWI_PRESCALE_VALUE  16UL
#elif TWI_PRESCALER == TWI_PRESCALER_64
    #define TWI_PRESCALE_VALUE  64UL
#endif


// Equation to calculate the value loaded into TWBR REGISTER BIT RATE
#define TWI_TWBR_VALUE   ((((TWI_F_CPU) / (TWI_SCL_FREQUENCY)) - 16UL) / (2UL * TWI_PRESCALE_VALUE))


#define TWI_FLAG_TIMEOUT				10000


#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
