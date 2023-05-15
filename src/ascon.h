//
// Created by jethr on 27/03/2023.
//
#include <stdint.h>

#ifndef ASCON_ASCON_H
#define ASCON_ASCON_H

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen);

void permutation(uint32_t * state, uint8_t round_number);

void pc(uint32_t * state, uint8_t round_number, uint8_t round);

void ps(uint32_t * state);

void pl(uint32_t * state);

#endif //ASCON_ASCON_H
