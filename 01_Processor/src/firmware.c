#include "hamming.h"
#include "print.h"

#define OUTPORT 0x80000000

void main(void)
{
	print_dec(get_hamming_weight(6));

}