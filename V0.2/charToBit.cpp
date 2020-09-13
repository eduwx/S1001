#include "charToBit.h"
#include <Arduino.h>

uint16_t charTable[]{
    0x478C, //A
    0x962C, //B
    0xC084, //C
    0x942C, //D
    0xC384, //E
    0x4384, //F
    0xC684, //G
    0x4788, //H
    0x9024, //I
    0xC408, //J
    0x4990, //K
    0xC080, //L
    0x54D8, //M
    0x4CC8, //N
    0xC48C, //O
    0x438C, //P
    0xCC8C, //Q
    0x4B8C, //R
    0x8784, //S
    0x1024, //T
    0xC488, //U
    0x6090, //V
    0x6CA8, //W
    0x2850, //X
    0x1050, //Y
    0xA314, //Z
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
    else if (data == 'B')
        return charTable[1];
    else if (data == 'C')
        return charTable[2];
    else if (data == 'D')
        return charTable[3];
    else if (data == 'E')
        return charTable[4];
    else if (data == 'F')
        return charTable[5];
    else if (data == 'G')
        return charTable[6];
    else if (data == 'H')
        return charTable[7];
    else if (data == 'I')
        return charTable[8];
    else if (data == 'J')
        return charTable[9];
    else if (data == 'K')
        return charTable[10];
    else if (data == 'L')
        return charTable[11];
    else if (data == 'M')
        return charTable[12];
    else if (data == 'N')
        return charTable[13];
    else if (data == 'O')
        return charTable[14];
    else if (data == 'P')
        return charTable[15];
    else if (data == 'Q')
        return charTable[16];
    else if (data == 'R')
        return charTable[17];
    else if (data == 'S')
        return charTable[18];
    else if (data == 'T')
        return charTable[19];
    else if (data == 'U')
        return charTable[20];
    else if (data == 'V')
        return charTable[21];
    else if (data == 'W')
        return charTable[22];
    else if (data == 'X')
        return charTable[23];
    else if (data == 'Y')
        return charTable[24];
    else if (data == 'Z')
        return charTable[25];
    else if (data == ' ')
        return charTable[26];
    else
        t = false;
}
