# README

## On ELF file

An ELF file is divided into **sections**. 

For an executable program, these are
* the text section for the code, 
* the data section for global variables, and 
* the rodata section that usually contains constant strings. 

The ELF file contains headers that describe how these sections should be stored in memory. 


## On Interrupts

The core has 4 additional 32-bit registers q0 .. q3 that are used for IRQ handling. When the IRQ handler is called, the register q0 contains the return address and q1 contains a bitmask of all IRQs to be handled. This means one call to the interrupt handler needs to service more than one IRQ when more than one bit is set in q1.

Registers q2 and q3 are uninitialized and can be used as temporary storage when saving/restoring register values in the IRQ handler.

All of the following instructions are encoded under the custom0 opcode. The f3 and rs2 fields are ignored in all this instructions.

See firmware/custom_ops.S for GNU assembler macros that implement mnemonics for this instructions.
See firmware/start.S for an example implementation of an interrupt handler assembler wrapper, and firmware/irq.c for the actual interrupt handler.