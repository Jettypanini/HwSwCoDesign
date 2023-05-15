//
// Created by jethr on 27/03/2023.
//
#include <stdint.h>

#ifndef ASCON_ASCON_H
#define ASCON_ASCON_H

#define U64TOWORD(x)                          \
  (((0x00000000000000FFULL & (x)) << 56) | \
   ((0x000000000000FF00ULL & (x)) << 40) | \
   ((0x0000000000FF0000ULL & (x)) << 24) | \
   ((0x00000000FF000000ULL & (x)) << 8) |  \
   ((0x000000FF00000000ULL & (x)) >> 8) |  \
   ((0x0000FF0000000000ULL & (x)) >> 24) | \
   ((0x00FF000000000000ULL & (x)) >> 40) | \
   ((0xFF00000000000000ULL & (x)) >> 56))

uint64_t MASK(int n) {
  /* undefined for n == 0 */
  return ~0ull >> (64 - 8 * n);
}

uint64_t LOAD(const uint8_t* bytes, int n) {
  uint64_t x = *(uint64_t*)bytes & MASK(n);
  return U64TOWORD(x);
}

uint64_t LOADBYTES(const uint8_t* bytes, int n) {
  uint64_t x = 0;
  x = LOAD(bytes, n);
  return U64TOWORD(x);
}

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen);

void permutation(uint32_t * state, uint8_t round_number);

void pc(uint32_t * state, uint8_t round_number, uint8_t round);

void ps(uint32_t * state);

void pl(uint32_t * state);

#endif //ASCON_ASCON_H
