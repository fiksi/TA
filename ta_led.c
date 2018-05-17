#include "ta_led.h"

void ta_led_LEDInit(void){
    DDR_LED |= (1 << LED_1);
    PORT_LED |= (1 << LED_1);
}

void ta_led_LEDTest(void){
    PORT_LED ^= (1 << LED_1);
    _delay_ms(TUNDA);
}
