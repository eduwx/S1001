# 1 "/media/eduardo/BACKUP/NextCloud/Codigos Arduino/VFD PT6311/S1001/V0.2/_main.ino"
/*
    AZAMERICA S1001 VFD controller LIB.

    *| You are free to copy, modify and share this library, please keep the developer credits. |*
    
    -> Developed by Eduardo Ferro.
    -> du.ferro@hotmail.com
*/

# 11 "/media/eduardo/BACKUP/NextCloud/Codigos Arduino/VFD PT6311/S1001/V0.2/_main.ino" 2




// #define VFD_DATA_SETTING 0x82 //Write to LED Port | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0x22 //Read Key data     | Auto increment address | Normal Mode
// #define VFD_DATA_SETTING 0xC2 //Read SW data      | Auto increment address | Normal Mode

// #define VFD_DATA_SETTING 0X22 //Write to display  | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0xA2 //Write to LED Port | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0x62 //Read Key data     | Fixed address | Normal Mode
// #define VFD_DATA_SETTING 0xE2 //Read SW data      | Fixed address | Normal Mode

// Define the first position memory


// dataPin|clockPin|strobePin|Vfd initialize mode|Data setting|
PT6311 vfd(7, 8, 9, 0x30 /*13 digits and 15 segments*/, 0x02 /*Write to display     | Auto increment address | Normal Mode*/, 0x03);

void setup()
{
    // Serial.begin(115200);
    delay(250);
}

void loop()
{
    vfd.setCursor(1);
    vfd.print("EDUARDO FERRO");
    tes();
}

void tes()
{

    delay(1000);
    vfd.clear();
    delay(1000);
}
