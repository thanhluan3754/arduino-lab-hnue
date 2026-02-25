#include <Arduino.h>
#include "BluetoothSerial.h"
#include "drive.h"

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("LUAN SPKT 01");

  driveInit();
}

void loop()
{
  if (SerialBT.available())
  {
    char cmd = SerialBT.read();

    if (cmd == '\n' || cmd == '\r')
      return;

    switch (cmd)
    {
    case 'f':
      forward();
      break;
    case 'b':
      backward();
      break;
    case 'l':
      left();
      break;
    case 'r':
      right();
      break;
    case 's':
      stopMotor();
      break;
    }
  }
}