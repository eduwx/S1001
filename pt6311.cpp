#include "pt6311.h"
#include "charToBit.h"
#include <Arduino.h>

uint8_t VFD_DATA_PIN_;
uint8_t VFD_CLOCK_PIN_;
uint8_t VFD_STROBE_PIN_;
uint8_t VFD_INITIALIZE_MODE_;
uint8_t VFD_DATA_SETTING_;
uint8_t VFD_MEMORY_ADDRESS_;

uint8_t addressDigit[] = {0x27, 0x87, 0x7B, 0XDB, 0X1B, 0XAB, 0X4B, 0XF3, 0X33, 0X93, 0X63, 0XC3, 0X03};

CharToBit charToBit;

PT6311::PT6311(uint8_t VFD_DATA_PIN, uint8_t VFD_CLOCK_PIN, uint8_t VFD_STROBE_PIN, uint8_t VFD_INITIALIZE_MODE, uint8_t VFD_DATA_SETTING, uint8_t VFD_MEMORY_ADDRESS)
{
    VFD_DATA_PIN_ = VFD_DATA_PIN;
    VFD_CLOCK_PIN_ = VFD_CLOCK_PIN;
    VFD_STROBE_PIN_ = VFD_STROBE_PIN;
    VFD_INITIALIZE_MODE_ = VFD_INITIALIZE_MODE;
    VFD_DATA_SETTING_ = VFD_DATA_SETTING;
    VFD_MEMORY_ADDRESS_ = VFD_MEMORY_ADDRESS;

    pinMode(VFD_DATA_PIN_, OUTPUT);
    pinMode(VFD_CLOCK_PIN_, OUTPUT);
    pinMode(VFD_STROBE_PIN_, OUTPUT);

    process(VFD_INITIALIZE_MODE_, false, true);
    process(VFD_DATA_SETTING_, false, true);
    process(VFD_MEMORY_ADDRESS_, false, false);

    // clear();
}

void PT6311::clear()
{
    // process(0x30, false, true);  //CMD 1
    process(0x02, false, true);  //CMD 2
    process(0x03, false, false); //CMD 3
    process(0xE1, true, false);
    for (uint8_t i = 0; i < 8; i++)
    {
        process(0x00, false, false);
        process(0x00, false, false);
        process(0x00, false, false);
        process(0x00, false, false);
        process(0x00, false, false);
    }
    // delay(500);
}

void PT6311::setCursor(uint8_t position)
{
    clear();
    process(0x22, false, true); //CMD 2
    process(addressDigit[position], false, false);
}

void PT6311::print(String DATA)
{
    uint8_t strLength;
    strLength = DATA.length();
    char str[strLength];
    DATA.toCharArray(str, strLength);

    uint8_t j;

    for (uint8_t x = 0; x < strLength; x++)
    {
        j = ((charToBit.convertedChar(str[x]) >> 8) & 0xFF);
        process(j, false, false);

        j = ((charToBit.convertedChar(str[x]) >> 0) & 0xFF);
        process(j, false, false);

        process(0xF1, true, false);
    }

    // process(0xFF, false, false);
    // process(0xFD, false, false);
    // process(0xF1, true, false); //CMD 4
}

void PT6311::process(uint8_t data, bool a, bool c)
{
    
    Serial.print(data, HEX);
    Serial.println();

    bool bitTmp;
    if (a)
        digitalWrite(VFD_STROBE_PIN_, true);
    delayMicroseconds(1);
    digitalWrite(VFD_STROBE_PIN_, false);
    delayMicroseconds(1);
    for (uint8_t b = 0; b < 8; b++)
    {
        digitalWrite(VFD_CLOCK_PIN_, false);
        delayMicroseconds(1);
        bitTmp = data & (0x80 >> b);
        digitalWrite(VFD_DATA_PIN_, bitTmp);
        delayMicroseconds(1);
        digitalWrite(VFD_CLOCK_PIN_, true);
        delayMicroseconds(1);
    }
    if (c)
        digitalWrite(VFD_STROBE_PIN_, true);
    delayMicroseconds(1);
}
