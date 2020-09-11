/*
    AZAMERICA S1001 VFD controller LIB.

    *| You are free to copy, modify and share this library, please keep the developer credits. |*
    
    -> Developed by Eduardo Ferro.
    -> du.ferro@hotmail.com
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

uint8_t l = 198;

char hex[17] = "0123456789ABCDEF";

void ShowHex(byte convertByte)
{
    String av;
    av.concat(String("0x") + av);
    av.concat(hex[(convertByte >> 4) & 0x0F]);
    av.concat(hex[convertByte & 0x0F]);

    Serial.println(av);
}

void setup()
{
    Serial.begin(115200);
    delay(250);
}

void loop()
{
    vfd.setCursor(1);
    vfd.print("EE");
    delay(200);

    vfd.setCursor(2);
    vfd.print("DD");
    delay(200);

    vfd.setCursor(3);
    vfd.print("UU");
    delay(200);

    vfd.setCursor(4);
    vfd.print("AA");
    delay(200);

    vfd.setCursor(5);
    vfd.print("RR");
    delay(200);

    vfd.setCursor(6);
    vfd.print("DD");
    delay(200);

    vfd.setCursor(7);
    vfd.print("OO");
    delay(200);


    delay(20000);
}
