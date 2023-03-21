# esp32_remote_controller

This is the code for a basic remote controller with 2 esp32's. 

This project was coded with Arduino IDE 2.0.4 with esp32 version 1.0.6 installed.

The code for the slave esp32 is in "esp32_remote_controller_slave" and the code for the master esp32 is in "esp32_remote_controller_master".

This project works by receiving power from 5V micro-usb then once both esp32's are powered with the master being last the white LEDs indicate that both esp32's are connected with Bluetooth and once you click the push button connected to the master esp32 the green LED on the slave esp32 lights up even though they are not physically connected with wires.

Here is a demonstration video!
