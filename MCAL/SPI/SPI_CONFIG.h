/*
 * SPI_CONFIG.h
 *
 *  Created on: Aug 2, 2026
 *      Author: dell
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

// Data Order Options
#define SPI_DATA_ORDER_LSB_FIRST        1
#define SPI_DATA_ORDER_MSB_FIRST        2

// Data Order Options Selection
#define SPI_DATA_ORDER                  SPI_DATA_ORDER_MSB_FIRST


// Master OR Slave Select Options
#define SPI_MASTER_MODE                 1
#define SPI_SLAVE_MODE                  2

// Master OR Slave Select Options Selection
#define SPI_MODE                        SPI_SLAVE_MODE



// Clock Polarity Options
#define SPI_CPOL_IDLE_LOW               1
#define SPI_CPOL_IDLE_HIGH              2

// Clock Polarity Options Selection
#define SPI_CPOL                        SPI_CPOL_IDLE_LOW


// Clock Phase Options
#define SPI_CPHA_SAMPLE_LEADING         1
#define SPI_CPHA_SETUP_LEADING          2

// Clock Phase Options Selection
#define SPI_CPHA                        SPI_CPHA_SAMPLE_LEADING



// Clock Rate Prescaler Options
#define SPI_PRESCALER_4                 1
#define SPI_PRESCALER_16                2
#define SPI_PRESCALER_64                3
#define SPI_PRESCALER_128               4
#define SPI_PRESCALER_2_2X              5
#define SPI_PRESCALER_8_2X              6
#define SPI_PRESCALER_32_2X             7
#define SPI_PRESCALER_64_2X             8

// Clock Rate Prescaler Options Selection
#define SPI_PRESCALER                   SPI_PRESCALER_16


// SPI Interrupt Options
#define SPI_INTERRUPT_DISABLE           1
#define SPI_INTERRUPT_ENABLE            2
#define SPI_INTERRUPT                   SPI_INTERRUPT_ENABLE

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
