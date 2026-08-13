#include "GLBI_INT.h"
#include "GLBI_REG.h"
#include "GLBI_PRIVATE.h" /* Included private definitions */
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

// GLOBAL INTERRUPT FUNCTIONS
void GLBI_voidEnableGlobal(void) {
    SET_BIT(GLBI_SREG, I_BIT);
}

void GLBI_voidDisableGlobal(void) {
    CLR_BIT(GLBI_SREG, I_BIT);
}
