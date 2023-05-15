#include "ascon.h"

void ascon_hash(uint32_t * digest, uint32_t * message, uint8_t mlen) {

    ASCON_init(mlen);

    for (uint8_t i = 0; i < mlen; i++) {
        ASCON_message(message[i]);
    }

    for (uint8_t i = 0; i < mlen; i++) {

        while (1) {
            digest[i*2] = ASCON_get_digest();
            if (digest[i*2] != 0) {
                break;
            }
        }

        while (1) {
            digest[(i*2)+1] = ASCON_get_digest();
            if (digest[(i*2)+1] != 0) {
                break;
            }
        }
    }

}