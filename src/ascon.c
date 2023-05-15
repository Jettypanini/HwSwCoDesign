//
// Created by jethr on 27/03/2023.
// Indien programma te groot -> Check simulatie voor ready signaal. Pas stack aan in firmware en hardware. Pas ook adressen aan voor IP blocks.
//

#include "ascon.h"

const uint8_t round_constants[12] = {0xf0, 0xe1, 0xd2, 0xc3, 0xb4, 0xa5, 0x96, 0x87, 0x78, 0x69, 0x5a, 0x4b};
const uint8_t sbox[32] = {0x04, 0x0b, 0x1f, 0x14, 0x1a, 0x15, 0x09, 0x02, 0x1b, 0x05, 0x08, 0x12, 0x1d, 0x03, 0x06, 0x1c, 0x1e, 0x13, 0x07, 0x0e, 0x00, 0x0d, 0x11, 0x18, 0x10, 0x0c, 0x01, 0x19, 0x16, 0x0a, 0x0f, 0x17};

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen) {
    for (int i = 0; i<4; i++) {
        digest[i*2] = LOAD(message[i*2], 32);
        digest[(i*2)+1] = LOAD(message[(i*2)+1], 32);
    }
}

void permutation(uint32_t * state, uint8_t number_of_rounds) {
}

// The function pc executes an xor with the round value from the round constants
void pc(uint32_t * state, uint8_t round_number, uint8_t round) {
}

// For all 64 values, combined as X0 | X1 | X2 | X3 | X4 | X5, this function changes the value following the S-box
// Temp1 goes through all 32 bits of the even indexes of the state[].
// Temp2 goes through all 32 bits of the uneven indexes of the state[].
void ps(uint32_t * state) {
}

// This function performs a few shift operations and XORs as given by the documentation
void pl(uint32_t * state) {
}