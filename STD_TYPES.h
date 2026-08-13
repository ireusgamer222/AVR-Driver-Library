/*
 * STD_TYPES.h
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Unsigned Integers */
typedef unsigned char         uint8_t;
typedef unsigned short int    u16;
typedef unsigned long int     uint32_t;
typedef unsigned long long    uint64_t;

/* Hungarian-notation aliases: every function signature across this
 * library uses Copy_u8, Local_u16, Global_u32 style prefixes, so
 * these keep the type family consistent with that convention.
 * (Also fixes ADC_REG.h's SFIOR_REG, which referenced u8 directly.) */
typedef uint8_t                u8;
typedef uint32_t               u32;
typedef uint64_t               u64;

/* Signed Integers */
typedef signed char           sint8_t;
typedef signed short int      sint16_t;
typedef signed long int       sint32_t;
typedef signed long long      sint64_t;

/* Real/Floating Point Numbers */
typedef float                 float32_t;
typedef double                float64_t;

/* Boolean Values */
typedef unsigned char         boolean;

#ifndef TRUE
#define TRUE                  ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE                 ((boolean) 0)
#endif

/* Standard Null Pointer Definition */
#ifndef NULL
#define NULL                  ((void *) 0)
#endif

#ifndef NULL_PTR
#define NULL_PTR              ((void *) 0)
#endif

/* Common Return Types (AUTOSAR compliant) */
typedef uint8_t Std_ReturnType;

#define E_OK                  ((Std_ReturnType) 0)
#define E_NOT_OK              ((Std_ReturnType) 1)

#endif /* STD_TYPES_H_ */
