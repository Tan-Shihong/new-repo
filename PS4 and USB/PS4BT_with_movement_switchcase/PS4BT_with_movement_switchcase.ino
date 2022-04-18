//dont use pin 10-13 

#include <PS4BT.h>
#include <usbhub.h>



// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
#define PS4DEBUG

//USB Set UP
USB Usb;
USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);


#define pwm_1 8 //upper left wheel
#define pwm_2 2 //lower left wheel
#define pwm_3 3 //upper right wheel
#define pwm_4 5 //lower right wheel
#define dir_1 7
#define dir_2 9
#define dir_3 4
#define dir_4 6
#define min_speed
#define max_speed
//int pwm;

// After that you can simply create the instance like so and then press the PS button on the device
//PS4BT PS4(&Btd);

bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;

int lx = 0;
int ly = 0;


void joyStickMovement()
{
  if ( PS4.getAnalogHat(LeftHatY) <= 112) {
    ly = map( PS4.getAnalogHat(LeftHatY), 112, 0, 0, 230);
  }
  else if ( PS4.getAnalogHat(LeftHatY) >= 132){
    ly = map( PS4.getAnalogHat(LeftHatY), 132, 255, 0, -230);
  }
  if ( PS4.getAnalogHat(LeftHatX) <= 112) {
    lx = map( PS4.getAnalogHat(LeftHatX), 112, 0, 0, -230);
  }
  else if ( PS4.getAnalogHat(LeftHatX) >= 132){
    lx = map( PS4.getAnalogHat(LeftHatX), 132, 255, 0, 230);
  }
  
//Movement
    uint8_t input_joystick = ((ly < 0) << 2 | ((ly > 0)) << 1 |(ly == 0 && lx != 0) << 0 );
//  Serial.println("case :");
//  Serial.println(input_joystick);
  switch (input_joystick) {
    case 1:
      lx > 0? Right(lx):Left(-lx);
      break;

    case 2:
      if(lx==0)
      {
        Forward(ly);
      }
      else if(lx>0)
      {
        int pwm_out = lx > ly? lx:ly;
        DiagonalRightForward(pwm_out);
      }
      else
      {
        int pwm_out = -lx > ly? -lx:ly;
        DiagonalLeftForward(pwm_out);
      }
      break;
  
    case 4:
      if(lx==0)
      {
        Backward(-ly);
      }
      else if(lx>0)
      {
        int pwm_out = -lx > -ly? -lx:-ly;
        DiagonalRightBackward(pwm_out);
      }
      else
      {
        int pwm_out = -lx > ly? -lx:ly;
        DiagonalLeftBackward(pwm_out);
      }
      break;
  
    default:
        Serial.println("Stop");
        break;
}
}

void Forward(int pwm)
{
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, pwm);
}

void Backward(int  pwm)
{
  digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, pwm);
}

void Left(int pwm)
{
  digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, LOW);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, pwm);
}

void Right(int pwm)
{
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, HIGH);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, pwm);
}

void RotateLeft(int pwm)
{
  digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, pwm);
}

void RotateRight(int pwm)
{
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, pwm);
}

void DiagonalLeftForward(int pwm)
{
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);

  analogWrite(pwm_1, 0);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, 0);
}

void DiagonalRightForward(int pwm)
{
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, 0);
  analogWrite(pwm_3, 0);
  analogWrite(pwm_4, pwm);
}

void DiagonalLeftBackward(int pwm)
{
  digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);

  analogWrite(pwm_1, pwm);
  analogWrite(pwm_2, 0);
  analogWrite(pwm_3, 0);
  analogWrite(pwm_4, pwm);
}

void DiagonalRightBackward(int pwm)
{
  digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);

  analogWrite(pwm_1, 0);
  analogWrite(pwm_2, pwm);
  analogWrite(pwm_3, pwm);
  analogWrite(pwm_4, 0);
}

void MotorStoping()
{
  analogWrite(pwm_1, 0);
  analogWrite(pwm_2, 0);
  analogWrite(pwm_3, 0);
  analogWrite(pwm_4, 0);
}

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

  pinMode(dir_1,OUTPUT);
  pinMode(dir_2,OUTPUT);
  pinMode(dir_3,OUTPUT);
  pinMode(dir_4,OUTPUT);
}



void loop() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 ){
      joyStickMovement();
      //Serial.print(PS4.getAnalogHat(RightHatX));
      //Serial.print(F("\tRightHatY: "));
      //Serial.print(PS4.getAnalogHat(RightHatY));
    }


  }                                                
}
