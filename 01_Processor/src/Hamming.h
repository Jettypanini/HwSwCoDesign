// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

#ifndef HAMMING_H
#define HAMMING_H

#include <stdint.h>
#include <stdbool.h>

unsigned int get_hamming_weight(unsigned int x);
unsigned int get_hamming_distance(unsigned int x, unsigned int y);
unsigned int get_factorial(unsigned int x);

#endif
