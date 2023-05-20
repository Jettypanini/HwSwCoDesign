#include "print.h"
#include "ascon.h"

// The cross compiler gives an error when you try to execute the code with call-by-reference, because memcpy does not exist.
// By writing the function, it can be used.
// This software implementation ends at 20.04 ms

void main(void) {

    uint8_t len1 = 6;
    // digest for next message is: DBE69CB9DC29EB968ECF98EDC448A4D39B2207AEC83928CA5395B06B5EC9BBD1
    uint32_t message1[6] = {0x00010203, 0x04050607, 0x08090A0B, 0x0C0D0E0F, 0x10111213, 0x80000000};

    uint8_t len2 = 4;
    // digest for next message is: 368946D5790A805945ACE20DF59352FC3575D524384F702D32175AFAC9534F1F
    uint32_t message2[4] = {0x00010203, 0x04050607, 0x08090A0B, 0x0C800000};

    uint32_t digest[8];

    ascon_hash(digest, message1, len1);

    print_str("digest 1: 0x");
    for(int i=0; i<8; i++) {
        print_hex(digest[i], 8);
    }
    print_str(".");

    ascon_hash(digest, message2, len2);

    print_str("digest 2: 0x");
    for(int i=0; i<8; i++) {
        print_hex(digest[i], 8);
    }
    print_str(".");
}
