#ifndef PT6311_h
#define PT6311_h
#include <Arduino.h>

class PT6311
{
public:
    PT6311(uint8_t VFD_DATA_PIN, uint8_t VFD_CLOCK_PIN, uint8_t VFD_STROBE_PIN, uint8_t VFD_INITIALIZE_MODE, uint8_t VFD_DATA_SETTING, uint8_t VFD_MEMORY_ADDRESS);
    void clear();
    void setCursor(uint8_t POSITION);
    void print(String DATA);
    void scrollDisplayRight(String DATA);
    void scrollDisplayLeft(String DATA);

private:
    void process(uint8_t data, bool a, bool b);
    uint8_t position;
};
#endif