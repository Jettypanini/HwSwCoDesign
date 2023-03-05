#include "print.h"
#include "average.h"

void main(void) {
    volatile unsigned int value1, value2, av;

    value1 = 32;
    value2 = 16;

    av = avg(value1, value2);

    print_str("avg(0x");
    print_hex(value1, 6);
    print_str(", ");
    print_hex(value2, 5);
    print_str(") = 0x");
    print_hex(av, 5);
    print_str(".");

    value1 = 3;
    value2 = 4;

    av = avg(value1, value2);

    print_str("avg(0x");
    print_hex(value1, 4);
    print_str(", ");
    print_hex(value2, 4);
    print_str(") = 0x");
    print_hex(av, 4);
    print_str(".");
}