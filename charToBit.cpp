#include "charToBit.h"
#include <Arduino.h>

uint16_t charTable[]{
    0x478C, //A
    0x4B8C, //R
};

bool t;

CharToBit::CharToBit()
{
}

bool CharToBit::show()
{
    return t;
}

uint16_t CharToBit::convertedChar(char data)
{
    t = true;
    if (data == 'A')
        return charTable[0];
    // else if (data == 'R')
    //     return charTable[1];
    else
        t = false;
}
