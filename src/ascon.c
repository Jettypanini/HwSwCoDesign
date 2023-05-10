//
// Created by jethr on 27/03/2023.
// Indien programma te groot -> Check simulatie voor ready signaal. Pas stack aan in firmware en hardware. Pas ook adressen aan voor IP blocks.
//

#include "ascon.h"

const uint8_t round_constants[12] = {0xf0, 0xe1, 0xd2, 0xc3, 0xb4, 0xa5, 0x96, 0x87, 0x78, 0x69, 0x5a, 0x4b};
const uint8_t sbox[32] = {0x04, 0x0b, 0x1f, 0x14, 0x1a, 0x15, 0x09, 0x02, 0x1b, 0x05, 0x08, 0x12, 0x1d, 0x03, 0x06, 0x1c, 0x1e, 0x13, 0x07, 0x0e, 0x00, 0x0d, 0x11, 0x18, 0x10, 0x0c, 0x01, 0x19, 0x16, 0x0a, 0x0f, 0x17};

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen) {
    //Initialization
    uint32_t internal_state[10] = {0x00400c00, 0x00000100, 0, 0, 0, 0, 0, 0, 0, 0};

    permutation(internal_state, 12);

    // Absorb message


    for (int i = 0; i<(((mlen/2))); i++) {
        internal_state[0] = internal_state[0] ^ message[i*2];
        internal_state[1] = internal_state[1] ^ message[(i*2)+1];
        permutation(internal_state, 12);
    }

    //Squeeze hash
    for (int i = 0; i<4; i++) {
        digest[i*2] = internal_state[0];
        digest[(i*2)+1] = internal_state[1];
        permutation(internal_state, 12);
    }
}

void permutation(uint32_t * state, uint8_t number_of_rounds) {
    uint32_t temp_state[10];

    for (int i = 0; i<10; i++) {
        temp_state[i] = state[i];
    }

    for (int i=0; i<number_of_rounds; i++) {
        pc(temp_state, number_of_rounds, i);
        ps(temp_state);
        pl(temp_state);
    }

    for (int i = 0; i<10; i++) {
        state[i] = temp_state[i];
    }
}

// The function pc executes an xor with the round value from the round constants
void pc(uint32_t * state, uint8_t round_number, uint8_t round) {
    for (int i = 0; i < 10; i++) {
        state[i] = state[i];
    }
    state[5] = state[5] ^ round_constants[(12-round_number) + round];
}

// For all 64 values, combined as X0 | X1 | X2 | X3 | X4 | X5, this function changes the value following the S-box
// Temp1 goes through all 32 bits of the even indexes of the state[].
// Temp2 goes through all 32 bits of the uneven indexes of the state[].
void ps(uint32_t * state) {
    uint8_t temp1, temp2;

    for (int i = 0; i < 32; i++) {
        temp1 = (((state[0] & (0x1 << (31-i))) >> (31-i)) << 4) | (((state[2] & (0x1 << (31-i))) >> (31-i)) << 3) | (((state[4] & (0x1 << (31-i))) >> (31-i)) << 2) | (((state[6] & (0x1 << (31-i))) >> (31-i)) << 1) | ((state[8] & (0x1 << (31-i))) >> (31-i));
        temp1 = sbox[temp1];
        temp2 = (((state[1] & (0x1 << (31-i))) >> (31-i)) << 4) | (((state[3] & (0x1 << (31-i))) >> (31-i)) << 3) | (((state[5] & (0x1 << (31-i))) >> (31-i)) << 2) | (((state[7] & (0x1 << (31-i))) >> (31-i)) << 1) | ((state[9] & (0x1 << (31-i))) >> (31-i));
        temp2 = sbox[temp2];
        for (int j = 0; j<5; j++) {
            state[j*2] &= ~(1 << (31-i));
            state[j*2] |= ((temp1 >> (4-j)) & 1) << (31-i);
            state[(j*2)+1] &= ~(1 << (31-i));
            state[(j*2)+1] |= ((temp2 >> (4-j)) & 1) << (31-i);
        }
    }
}

// This function performs a few shift operations and XORs as given by the documentation
void pl(uint32_t * state) {
    uint32_t temp1[10];
    uint32_t temp2[10];

    //X0
    temp1[0] = (state[0] >> 19) ^ (state[1] << 13);
    temp1[1] = (state[1] >> 19) ^ (state[0] << 13);
    temp2[0] = (state[0] >> 28) ^ (state[1] << 4 );
    temp2[1] = (state[1] >> 28) ^ (state[0] << 4 );

    //X1
    temp1[2] = (state[2] << 3 ) ^ (state[3] >> 29);
    temp1[3] = (state[3] << 3 ) ^ (state[2] >> 29);
    temp2[2] = (state[2] << 25) ^ (state[3] >> 7 );
    temp2[3] = (state[3] << 25) ^ (state[2] >> 7 );

    //X2
    temp1[4] = (state[4] >> 1 ) ^ (state[5] << 31);
    temp1[5] = (state[5] >> 1 ) ^ (state[4] << 31);
    temp2[4] = (state[4] >> 6 ) ^ (state[5] << 26);
    temp2[5] = (state[5] >> 6 ) ^ (state[4] << 26);

    //X3
    temp1[6] = (state[6] >> 10) ^ (state[7] << 22);
    temp1[7] = (state[7] >> 10) ^ (state[6] << 22);
    temp2[6] = (state[6] >> 17) ^ (state[7] << 15);
    temp2[7] = (state[7] >> 17) ^ (state[6] << 15);

    //X4
    temp1[8] = (state[8] >> 7 ) ^ (state[9] << 25);
    temp1[9] = (state[9] >> 7 ) ^ (state[8] << 25);
    temp2[8] = (state[8] << 23) ^ (state[9] >> 9 );
    temp2[9] = (state[9] << 23) ^ (state[8] >> 9 );

    for(int i=0; i<10; i++) {
        state[i] = state[i] ^ temp1[i] ^ temp2[i];
    }
}