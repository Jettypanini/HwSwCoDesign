#include <stdint.h>
#include "print.h"
#include "irq.h"

uint32_t *irq(uint32_t *regs, uint32_t irqs);

char message = '*';

void main(void) {
    while(1){
        print_chr(message);
    }
}
