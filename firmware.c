#include "hamming.h"
#include "print.h"

void main(void)
{
	print_hex(6);
	print_hex(get_hamming_weight(6));
	print_hex(get_hamming_weight(47));
	print_hex(get_hamming_distance(6,9));
	print_hex(get_hamming_distance(35,98));
	print_hex(get_factorial(6));
	print_hex(get_factorial(11));

}