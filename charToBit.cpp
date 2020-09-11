#include "charToBit.h"
#include <Arduino.h>

uint16_t charTable[]{
    0x478C, //A
    0x942C, //D
    0xC384, //E
    0xC48C, //O
    0x4B8C, //R
    0xC488, //U
    0x0000, //SPACE
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
    else if (data == 'D')
        return charTable[1];
    else if (data == 'E')
        return charTable[2];
    else if (data == 'O')
        return charTable[3];
    else if (data == 'R')
        return charTable[4];
    else if (data == 'U')
        return charTable[5];
    else if (data == ' ')
        return charTable[6];
    else
        t = false;
}
