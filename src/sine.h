/*
 * sine.h
 */
#ifndef SINE_DRIVER_H
#define SINE_DRIVER_H

#define SINE_BASEADDRESS    0x80000000
#define SINE_REG0_ADDRESS   (SINE_BASEADDRESS + 0*4)
#define SINE_REG1_ADDRESS   (SINE_BASEADDRESS + 1*4)

#define SINE_CR             (*(volatile unsigned int *) SINE_REG0_ADDRESS)
#define SINE_VALUE          (*(volatile unsigned int *) SINE_REG1_ADDRESS)

#define SINE_CR_CE          0x00000400U
#define SINE_CR_CLEAR       0x00000000U


#define SINE_calc(angle)    (SINE_CR |= SINE_CR_CE | (angle))
#define SINE_stop()         (SINE_CR &= SINE_CR_CLEAR)
#define SINE_get_value()    (SINE_VALUE)

#endif