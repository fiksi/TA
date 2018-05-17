#include <avr/io.h>
#include <util/delay.h>

#include "ta_mmc.h"

int main (void){


	DDRG = 0xFF;
	PORTG = 0xFF;

    ta_mmc_WriteTest();

	while(1){
		PORTG ^= (1 << 1);
		_delay_ms(500);
	}
}


