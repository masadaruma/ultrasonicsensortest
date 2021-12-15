#include <HCSR04.h>
#include <EEPROM.h>

int val = 1000;
int val_out;
unsigned int valup, valdown;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    EEPROM.write(0, (val >> 8) & 0xFF); //上8バイト
    EEPROM.write(1, (val >> 0) & 0xFF); //下8バイト
    valup=EEPROM.read(0);
    valdown=EEPROM.read(1);
    val_out = (valup << 8&0xFF00) | (valdown << 0&0x00FF);
    Serial.print("valup : ");
    Serial.println(valup,BIN);
    Serial.print("valdown : ");
    Serial.println(valdown,BIN);
    Serial.print("val_out : ");
    Serial.println(val_out);
    while (1);
}
