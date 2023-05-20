/*
 * ascon.h
 */
#ifndef ASCON_DRIVER_H
#define ASCON_DRIVER_H

#include <stdint.h>

#define ASCON_BASEADDRESS    0x81100000
#define ASCON_REG0_ADDRESS   (ASCON_BASEADDRESS + 0*4)
#define ASCON_REG1_ADDRESS   (ASCON_BASEADDRESS + 1*4)
#define ASCON_REG2_ADDRESS   (ASCON_BASEADDRESS + 2*4)

#define ASCON_CR0            (*(volatile unsigned int *) ASCON_REG0_ADDRESS)
#define ASCON_CR1            (*(volatile unsigned int *) ASCON_REG1_ADDRESS)
#define ASCON_DIGEST         (*(volatile unsigned int *) ASCON_REG2_ADDRESS)

#define ASCON_START          0x00000001U

#define ASCON_init(length)          (ASCON_CR0 |=  ((length) << 1) | ASCON_START)
#define ASCON_deinit()          (ASCON_CR0 &= 0x000)
#define ASCON_message(message)      (ASCON_CR1 = (message))
#define ASCON_get_digest()          (ASCON_DIGEST)

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen);

#endif