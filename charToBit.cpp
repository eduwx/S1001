#include "charToBit.h"
#include <Arduino.h>

uint16_t charTable[]{
    0x478C, //A
    0x4B8C, //R
};

CharToBit::CharToBit()
{
}

uint16_t CharToBit::convertedChar(char data)
{
    if (data == 'A')
        return charTable[0];
    // else if (data == 'R')
    //     return charTable[1];
    else
        return 0;
}
