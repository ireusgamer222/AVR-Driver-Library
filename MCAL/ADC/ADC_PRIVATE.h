#ifndef MCAL_ADC_PRIVATE_H_
#define MCAL_ADC_PRIVATE_H_

/* ADMUX Register Bits */
#define REFS1_BIT       7
#define REFS0_BIT       6
#define ADLAR_BIT       5

/* ADCSRA Register Bits */
#define ADEN_BIT        7
#define ADSC_BIT        6
#define ADATE_BIT       5
#define ADIF_BIT        4
#define ADIE_BIT        3
#define ADPS2_BIT       2
#define ADPS1_BIT       1
#define ADPS0_BIT       0

/* SFIOR Register Bits */
#define ADTS2_BIT       7
#define ADTS1_BIT       6
#define ADTS0_BIT       5

/* Masks */
#define MUX_MASK        0b00011111
#define PRESCALER_MASK  0b00000111
#define REFS_MASK       0b00000011
#define ADTS_MASK       0b00000111  // Mask for ADTS2:0 bits

#endif /* MCAL_ADC_PRIVATE_H_ */
