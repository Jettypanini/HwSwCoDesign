
#include <stdint.h>

#ifndef WORD_H
#define WORD_H

void *memcpy(void *dest, const void *src, uint8_t n)
{
    for (uint8_t i = 0; i < n; i++)
    {
        ((char*)dest)[i] = ((char*)src)[i];
    }
}

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
  memcpy(&x, bytes, n);
  return U64TOWORD(x);
}
