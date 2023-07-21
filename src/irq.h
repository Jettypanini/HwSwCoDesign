
#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>
#include "print.h"

uint32_t *irq(uint32_t *regs, uint32_t irqs);

#endif