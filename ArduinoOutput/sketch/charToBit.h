#ifndef CHARTOBIT_h
#define CHARTOBIT_h
#include <Arduino.h>

class CharToBit
{
public:
    CharToBit();
    uint16_t convertedChar(char data);
    bool show();

private:
};
#endif