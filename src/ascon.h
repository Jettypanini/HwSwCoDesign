//
// Created by jethr on 27/03/2023.
//
#include <stdint.h>

#ifndef ASCON_ASCON_H
#define ASCON_ASCON_H

#define U32BIG(x)                                           \
  (((0x000000FF & (x)) << 24) | ((0x0000FF00 & (x)) << 8) | \
   ((0x00FF0000 & (x)) >> 8) | ((0xFF000000 & (x)) >> 24))

uint32_t load(const uint32_t* inp, int len) {
    uint32_t x;
    for (int i=0; i<len; i++) {
        x |= inp[í];
    }
  return x;
}

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen);

void permutation(uint32_t * state, uint8_t round_number);

void pc(uint32_t * state, uint8_t round_number, uint8_t round);

void ps(uint32_t * state);

void pl(uint32_t * state);

#endif //ASCON_ASCON_H
