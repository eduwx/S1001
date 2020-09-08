/*

Controle do VFD AZAMERICA AZ1001s com CI PT6311 ou  μPD16311 ou CS163110
Desenvolvido por Eduardo F.S Ferro
Data 18/08/2020

*/


#include "pt6311.h"

#define VFD_INITIALIZE_MODE 0x30 //13 digits and 15 segments

#define VFD_DATA_SETTING 0x02 //Write to display     | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0x82 //Write to LED Port | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0x22 //Read Key data     | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0xC2 //Read SW data      | Auto increment address | Normal Mode

// #define VFD_DATA_SETTING 0X22 //Write to display  | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0xA2 //Write to LED Port | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0x62 //Read Key data     | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0xE2 //Read SW data      | Fixed address | Normal Mode

// Define the first position memory
#define VFD_MEMORY_ADDRESS 0x03

// dataPin|clockPin|strobePin|Vfd initialize mode|Data setting|
PT6311 vfd(7, 8, 9, VFD_INITIALIZE_MODE, VFD_DATA_SETTING, VFD_MEMORY_ADDRESS);

void setup()
{
    delay(250);
}

void loop()
{
    for (uint8_t a = 1; a < 12; a++)
    {
        vfd.setCursor(a);
        vfd.print('R');
        delay(100);
    }

    for (uint8_t a = 11; a > 0; a--)
    {
        vfd.setCursor(a);
        vfd.print('R');
        delay(100);
    }
}