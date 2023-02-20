
#include "hamming.h"

unsigned int get_hamming_weight(unsigned int x) {
    unsigned int y = 1;
    unsigned int weight = 0;
    for (int i = 1; i<32; i++) {
        weight = weight + (x ^ y);
        y = y + y;
    }
    return weight;
}

unsigned int get_hamming_distance(unsigned int x, unsigned int y) {
    unsigned int z = x ^ y;
    return get_hamming_weight(z);
}

unsigned int get_factorial(unsigned int x) {
    unsigned int fact = x;
    for (int i = 1; i<x; i++) {
        fact = fact * (x-i);
    }
    return fact;
}
