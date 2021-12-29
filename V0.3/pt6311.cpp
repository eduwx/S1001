#include "pt6311.h"
#include "charToBit.h"
#include <Arduino.h>

uint8_t VFD_DATA_PIN_;
uint8_t VFD_CLOCK_PIN_;
uint8_t VFD_STROBE_PIN_;
uint8_t VFD_INITIALIZE_MODE_;
uint8_t VFD_DATA_SETTING_;
uint8_t VFD_MEMORY_ADDRESS_;
// POSIÇÕES DISPLAY NORMAL| 0    1     2     3     4     5    6     7     8      9     10   11    12 
uint8_t addressDigit[] = {0x27, 0x87, 0x7B, 0xDB, 0x1B, 0xAB, 0x4B, 0xF3, 0x33, 0x93, 0x63, 0xC3, 0x03};
// POSIÇÕES DISPLAY INVERT|    0     1     2     3     4     5     6     7     8     9     10    11   12
uint8_t addressDigitInv[] = {0x03, 0xC3, 0x63, 0x93, 0x33, 0xF3, 0x4B, 0xAB, 0x1B, 0xDB, 0x7B, 0x87, 0x27};

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

  clear();
}

void PT6311::clear()
{
  process(0x02, false, true);
  process(0x03, false, false);
  process(0xE1, true, false);
  for (uint8_t i = 0; i < 8; i++)
  {
    process(0x00, false, false);
    process(0x00, false, false);
    process(0x00, false, false);
    process(0x00, false, false);
    process(0x00, false, false);
  }
}

void PT6311::setCursor(uint8_t position, boolean b_invert)
{
  // clear();
  process(0x22, false, true);
  if (!b_invert)
    process(addressDigit[position], false, false);
  else  
    process(addressDigitInv[position], false, false);
    
}

void PT6311::print(String DATA, boolean invert)
{
  uint8_t j;
  uint8_t strLength;
  strLength = DATA.length() + 1;
  //if (strLength > 12)
  //    strLength = 12;
  char str[strLength];
  DATA.toCharArray(str, strLength);

  for (uint8_t x = 0; x < strLength - 1; x++)
  {
    if (!invert)
    {
      if ((x + 1) == 12)
        setCursor(11, invert);
      else
        setCursor(x + 1, invert);

      j = ((charToBit.convertedChar(str[x]) >> 8) & 0xFF);
      if (charToBit.show() == true)
        process(j, false, false);
  
      j = ((charToBit.convertedChar(str[x]) >> 0) & 0xFF);
      if (charToBit.show() == true)
        process(j, false, false);
    } else
    {
      if ((x + 1) == 12)
        setCursor(11, invert);
      else
        setCursor(x + 1, invert);
      j = ((charToBit.convertedChar(str[(x)]) >> 8) & 0xFF);
      if (charToBit.show() == true)
        process(j, false, false);
  
      j = ((charToBit.convertedChar(str[(x)]) >> 0) & 0xFF);
      if (charToBit.show() == true)
        process(j, false, false);
      
    }
    process(0xF1, true, false);
  }
}

void PT6311::printPos(String DATA, uint8_t pos, boolean invert)
{
  uint8_t j;
  uint8_t strLength;
  strLength = DATA.length() + 1;
  if (strLength > 12)
        strLength = 12;
  char str[strLength];
  DATA.toCharArray(str, strLength);
  for (uint8_t x = 0; x < strLength - 1; x++)
  {
    setCursor(pos + x, invert);
    j = ((charToBit.convertedChar(str[x]) >> 8) & 0xFF);
    if (charToBit.show() == true)
      process(j, false, false);

    j = ((charToBit.convertedChar(str[x]) >> 0) & 0xFF);
    if (charToBit.show() == true)
      process(j, false, false);
    process(0xF1, true, false);
  }
}

void PT6311::scrollDisplayRightToLeft(String DATA)
{
  String str = DATA;
  while (true)
  {
    print(marquee_limit(str, 11), false);
    delay(250);
  };
}

void PT6311::scrollDisplayLeftToRight(String DATA)
{
  String str; //DATA;
  str="";
  for (int i=DATA.length()-1; i>0; i--)
  {
    str+=DATA[i];
  }
  
  while (true)
  {
    print(marquee_limit(str, 11), true);
    delay(250);
  };
}

String PT6311::marquee_limit(String& text, uint8_t limit) {
  String temp = text;
  text.remove(0, 1);
  text += temp[0];

  return text.substring(0, limit);
}

void PT6311::running(int pos)
{
   int c = 0;
  
   while (true)
   {
       if (c == 0)
         printPos("/", pos,false);
       else if (c==1)  
         printPos("-", pos,false);
       else if (c==2)  
         printPos("\\", pos,false);
       else if (c==3)  
         printPos("|", pos,false);
    
       c+=1;
       if (c>3) 
       { 
        c=0;
        break;
       }      
       delay(200);
   }
}

void PT6311::process(uint8_t data, bool a, bool c)
{
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
