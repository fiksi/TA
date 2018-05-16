/*----------------------------------------------------------------------*/
/* Foolproof FatFs sample project for AVR              (C)ChaN, 2014    */
/*----------------------------------------------------------------------*/

#include <avr/io.h>	/* Device specific declarations */
#include <util/delay.h>

#include "sdmmc/ff.h"		/* Declarations of FatFs API */

/* SDMMC Hardware Abstraction Layer => sdmmc.c */
FATFS FatFs;		/* FatFs work area needed for each volume */
FIL Fil;			/* File object needed for each open file */

int main (void)
{
	UINT bw;
	
	DDRG = 0xFF;
	PORTG = 0xFF;

	f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */

	if (f_open(&Fil, "newfile.txt", FA_WRITE | FA_CREATE_ALWAYS) == FR_OK) {	/* Create a file */

		f_write(&Fil, "It works!\r\n", 11, &bw);	/* Write data to the file */

		f_close(&Fil);								/* Close the file */
	}

	while(1){
		PORTG ^= (1 << 1);
		_delay_ms(500);
	}
}


