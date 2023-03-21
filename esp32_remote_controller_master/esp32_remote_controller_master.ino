#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int ledPin0 = 25;
const int buttonPin0 = 5;
char *pin = "0000"; //<- standard pin would be provided by default
bool connected = false;

void setup() {
  pinMode(ledPin0, OUTPUT);
  pinMode(buttonPin0, INPUT_PULLUP);
  Serial.begin(115200);
  SerialBT.begin("ESP32master", true); //Bluetooth device name
  SerialBT.setPin(pin);
  Serial.println("The device started in master mode, make sure remote BT device is on!");
  for (int trials = 1; trials <= 30; trials++) {
    connected = SerialBT.connect("ESP32slave");
    if(connected)
      break;
  }
  if (!connected) {
    Serial.println("Failed to connect. Make sure remote device is available and in range, then restart app.");
    while(1)
      sleep(1);
  }
}

void loop() {
  if (SerialBT.connected(0))
    digitalWrite(ledPin0, HIGH);
  else
    digitalWrite(ledPin0, LOW);
  
  if (digitalRead(buttonPin0) == HIGH)
    SerialBT.write((uint8_t)'2');
  else
    SerialBT.write((uint8_t)'1');
  
  delay(20);
}