#include <avr/io.h>
#include <util/delay.h>

#define tunda 500

int main(void){
	DDRG = 0xff;
	PORTG = 0xff;
	
	while(1){
		PORTG ^= (1<<0);
		_delay_ms(tunda);
	}
	
}