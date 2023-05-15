//
// Created by jethr on 27/03/2023.
//
#include <stdint.h>

#ifndef ASCON_ASCON_H
#define ASCON_ASCON_H

#define U32TOWORD(x)                                           \
  (((0x000000FF & (x)) << 24) | ((0x0000FF00 & (x)) << 8) | \
   ((0x00FF0000 & (x)) >> 8) | ((0xFF000000 & (x)) >> 24))

uint32_t mask(int n) {
  /* undefined for n == 0 */
  return ~0ull >> (32 - 8 * n);
}

uint32_t load(const uint8_t* bytes, int n) {
  uint64_t x = *(uint32_t*)bytes & mask(n);
  return U32TOWORD(x);
}

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen);

void permutation(uint32_t * state, uint8_t round_number);

void pc(uint32_t * state, uint8_t round_number, uint8_t round);

void ps(uint32_t * state);

void pl(uint32_t * state);

#endif //ASCON_ASCON_H
