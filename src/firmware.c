#include "print.h"
#include "sine.h"

void main(void) {

	unsigned int sine_value;
	volatile unsigned char temp;

	print_str("Sine value for 45 deg: ");
	SINE_calc(45);
	for(temp=0;temp<1;temp++);
	sine_value = SINE_get_value();
	print_hex(sine_value, 8);

	print_str("Sine value for 210 deg: ");
	SINE_calc(210);
	for(temp=0;temp<1;temp++);
	sine_value = SINE_get_value();
	print_hex(sine_value, 8);

	print_str("Sine value for 0 deg: ");
	SINE_calc(0);
	for(temp=0;temp<1;temp++);
	sine_value = SINE_get_value();
	print_hex(sine_value, 8);
}
