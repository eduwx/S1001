/*
    AZAMERICA S1001 VFD controller LIB.

    *| You are free to copy, modify and share this library, please keep the developer credits. |*
    
    -> Developed by Eduardo Ferro. AZAMERICA S1001 ->First Version
    -> Increase  by Marcelo Marques Gonçalves -> FreeSky Triplo X display
    -> du.ferro@hotmail.com / marcelomgoncalves@hotmail.com
*/

#include "pt6311.h"

#define VFD_INITIALIZE_MODE 0x30 //0x30 13 digits and 15 segments

#define VFD_DATA_SETTING 0x82    //Write to display  | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0x82 //Write to LED Port | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0x22 //Read Key data     | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0xC2 //Read SW data      | Auto increment address | Normal Mode

// #define VFD_DATA_SETTING 0x22 //Write to display  | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0xA2 //Write to LED Port | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0x62 //Read Key data     | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0xE2 //Read SW data      | Fixed address | Normal Mode

// Define the first position memory
#define VFD_MEMORY_ADDRESS 0x03

String txt =" * TESTANDO DISPLAY PT6311 \|-/ " ;

// dataPin|clockPin|strobePin|Vfd initialize mode|Data setting|
PT6311 vfd(7, 8, 9, VFD_INITIALIZE_MODE, VFD_DATA_SETTING, VFD_MEMORY_ADDRESS);

void setup()
{
    //Serial.begin(9600);
    vfd.clear();
    delay(250);
}


void loop()
{

   for (uint8_t i=0; i<=100; i++)
   {
    vfd.printPos((String)i,2,false);
    vfd.running(1);
    delay(150);  
   }
           
   // vfd.scrollDisplayRightToLeft(txt); 
   //vfd.scrollDisplayLeftToRight(txt);
   
   tes();
}

void tes()
{

    delay(300);
    vfd.clear();
    delay(300);
}
