#ifndef TA_LED_H
#define TA_LED_H

#include <avr/io.h>
#include <util/delay.h>

#define TUNDA 500

#define DDR_LED DDRG
#define PORT_LED PORTG

#define LED_1 1

void ta_led_LEDInit(void);
void ta_led_LEDTest(void);

#endif // TA_LED_H
