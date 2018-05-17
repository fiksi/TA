#include "ta_mmc.h"

FATFS FatFs;
FIL Fil;
UINT bw;

void ta_mmc_WriteTest(void){

    f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */

    if (f_open(&Fil, "newfile.txt", FA_WRITE | FA_CREATE_ALWAYS) == FR_OK) {	/* Create a file */

        f_write(&Fil, "It works!\r\n", 11, &bw);	/* Write data to the file */

        f_close(&Fil);								/* Close the file */
    }
}
