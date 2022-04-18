#include <PS4BT.h>
#include <usbhub.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

//By default serial debugging is disabled. To turn it on simply change ENABLE_UHS_DEBUGGING to 1 in arduino library,USB_Host_Shield_2.0-master file, then settings.h like so:
//If the PS4 controller is connected for a very short time then disconnected, then press the PS4 start button(at the middle of the controller)to make the controller to reconnect.
USB Usb;
USBHub Hub1(&Usb); // Some dongles have a hub inside after serial debugging
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);

// After that you can simply create the instance like so and then press the PS button on the device if u have connected to it before this
//PS4BT PS4(&Btd);

bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;

void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
}
void loop() {
  Usb.Task();//perform usb main task

  if (PS4.connected()) {//PS4 is successfully connected
    // Start to print the analog value for the movement of left and right analog joysticks
    if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 || PS4.getAnalogHat(RightHatX) > 137 || PS4.getAnalogHat(RightHatX) < 117 || PS4.getAnalogHat(RightHatY) > 137 || PS4.getAnalogHat(RightHatY) < 117) {
      Serial.print(F("\r\nLeftHatX: "));
      Serial.print(PS4.getAnalogHat(LeftHatX));
      Serial.print(F("\tLeftHatY: "));
      Serial.print(PS4.getAnalogHat(LeftHatY));
      Serial.print(F("\tRightHatX: "));
      Serial.print(PS4.getAnalogHat(RightHatX));
      Serial.print(F("\tRightHatY: "));
      Serial.print(PS4.getAnalogHat(RightHatY));
    }

    if (PS4.getAnalogButton(L2) || PS4.getAnalogButton(R2)) { // These are the only analog buttons,L2 and R2 on the PS4 controller
      Serial.print(F("\r\nL2: "));
      Serial.print(PS4.getAnalogButton(L2));
      Serial.print(F("\tR2: "));
      Serial.print(PS4.getAnalogButton(R2));
    }
    if (PS4.getAnalogButton(L2) != oldL2Value || PS4.getAnalogButton(R2) != oldR2Value) // Only write value if it's different
      PS4.setRumbleOn(PS4.getAnalogButton(L2), PS4.getAnalogButton(R2));//The PS4 will vibrate according to the L2 and R2 value
    //save the new L2 and R2 value into oldL2Value and oldL2Value
    oldL2Value = PS4.getAnalogButton(L2);
    oldR2Value = PS4.getAnalogButton(R2);

    if (PS4.getButtonClick(PS)) {//Disconnect the PS4 when the PS Button is pressed
      Serial.print(F("\r\nPS"));
      PS4.disconnect();
    }
    else {
      if (PS4.getButtonClick(TRIANGLE)) {//When the triangle button is pressed,the PS4 controller will slightly vibrate
        Serial.print(F("\r\nTriangle"));
        PS4.setRumbleOn(RumbleLow);
      }
      if (PS4.getButtonClick(CIRCLE)) {//when circle button is pressed the PS4 controller will strongly vibrate
        Serial.print(F("\r\nCircle"));
        PS4.setRumbleOn(RumbleHigh);
      }
      if (PS4.getButtonClick(CROSS)) { // when cross button is pressed, it will serial print "cross" and in the same time it will set led to blink rapidly
        Serial.print(F("\r\nCross"));
        PS4.setLedFlash(10, 10); // Set it to blink rapidly
        /* flashOn  Time to flash bright (10 = 0.1 seconds).
          flashOff Time to flash dark (10 = 0.1 seconds).
        */
      }
      if (PS4.getButtonClick(SQUARE)) {//when square button is pressed, it will serial print "Square"
        Serial.print(F("\r\nSquare"));
        PS4.setLedFlash(0, 0); // Turn off blinking
      }

      if (PS4.getButtonClick(UP)) { //when Up button is pressed(leftside of the controller), the light of the controller will light up in red colour
        Serial.print(F("\r\nUp"));
        PS4.setLed(Red);
      } if (PS4.getButtonClick(RIGHT)) { //when Right button is pressed, the light of the controller will light up in blue colour
        Serial.print(F("\r\nRight"));
        PS4.setLed(Blue);
      } if (PS4.getButtonClick(DOWN)) { //when Down button is pressed, the light of the controller will light up in yellow colour
        Serial.print(F("\r\nDown"));
        PS4.setLed(Yellow);
      } if (PS4.getButtonClick(LEFT)) { //when left button is pressed, the light of the controller will light up in green colour
        Serial.print(F("\r\nLeft"));
        PS4.setLed(Green);
      }

      if (PS4.getButtonClick(L1)) //when the L1 button is pressed, it will serial print "L1"
        Serial.print(F("\r\nL1"));
      if (PS4.getButtonClick(L3)) //when the L3 button is pressed, it will serial print "L3"
        Serial.print(F("\r\nL3"));
      if (PS4.getButtonClick(R1)) //when the R1 button is pressed, it will serial print "R1"
        Serial.print(F("\r\nR1"));
      if (PS4.getButtonClick(R3)) //when the R3 button is pressed, it will serial print "R3"
        Serial.print(F("\r\nR3"));

      if (PS4.getButtonClick(SHARE)) //when the Share button is pressed, it will serial print "share"
        Serial.print(F("\r\nShare"));
      if (PS4.getButtonClick(OPTIONS)) {//when the Option button is pressed, it will serial print "share"
        Serial.print(F("\r\nOptions"));
        printAngle = !printAngle; //toggle the boolean status of printAngle
      }
      if (PS4.getButtonClick(TOUCHPAD)) {//when the  touchpad is pressed, it will serial print "Touchpad"
        Serial.print(F("\r\nTouchpad"));
        printTouch = !printTouch; //toggle the boolean status of printTouch
      }

      if (printAngle) { // Print angle calculated using the accelerometer only after the options button is pressed
        Serial.print(F("\r\nPitch: "));
        Serial.print(PS4.getAngle(Pitch));
        Serial.print(F("\tRoll: "));
        Serial.print(PS4.getAngle(Roll));
      }

      if (printTouch) { // Print the x, y coordinates of the touchpad
        if (PS4.isTouching(0) || PS4.isTouching(1)) // Print newline and carriage return if any of the fingers are touching the touchpad
          Serial.print(F("\r\n"));
        for (uint8_t i = 0; i < 2; i++) { // The touchpad track two fingers
          if (PS4.isTouching(i)) { // Print the position of the finger if it is touching the touchpad
            Serial.print(F("X")); Serial.print(i + 1); Serial.print(F(": "));
            Serial.print(PS4.getX(i));
            Serial.print(F("\tY")); Serial.print(i + 1); Serial.print(F(": "));
            Serial.print(PS4.getY(i));
            Serial.print(F("\t"));
          }
        }
      }
    }
  }
}
