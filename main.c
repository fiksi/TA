#include <avr/io.h>
#include <util/delay.h>

#include "ta_mmc.h"
#include "ta_led.h"

int main (void){

    ta_led_LEDInit();

    ta_mmc_WriteTest();

	while(1){
        ta_led_LEDTest();
	}
}


