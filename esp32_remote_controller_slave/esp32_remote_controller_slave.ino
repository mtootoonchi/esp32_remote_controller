#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int ledPin0 = 25;
const int ledPin1 = 13;

void setup() {
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32slave"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.connected(0))
    digitalWrite(ledPin0, HIGH);
  else
    digitalWrite(ledPin0, LOW);

  char incomingChar = '0';
  if (SerialBT.available())
    incomingChar = SerialBT.read();    

  if (incomingChar == '1')
    digitalWrite(ledPin1, HIGH);
  else if (incomingChar == '2')
    digitalWrite(ledPin1, LOW);

  delay(20);
}