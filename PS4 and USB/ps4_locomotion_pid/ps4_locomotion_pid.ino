/******/
#include <PID_v1.h>

//dont use pin 10-13
//Locomotion
#define wheel1 2 //upper left
#define wheel2 3 //upper right
#define wheel3 4 //lower left
#define wheel4 5 //lower right
#define dir_1 0 //upper left direction
#define dir_2 1 //upper right direction
#define dir_3 2 //lower left direction
#define dir_4 3 //lower right direction
#define min_speed
#define max_speed
int motor_Speed;

//PID library
double kp = 0, ki = 0, kd = 0;//definition
double Input, Output, setpoint;
int sampletime=20  ; //sample time  in ms
PID myPID(&Input, &Output, &setpoint, kp, ki, kd, DIRECT);

unsigned char Re_buf[11], counter = 0;
unsigned char sign = 0;
//float yaw_angle;
//float prevyaw_angle = 0;
bool aligned = false;
bool stopped = false;
bool moving = false;
bool self_align_on = true;
//float suss;
//float fail;
//bool entered_aligned_zone = false;

int capPWMValue(int final_pwm_value)
{
  if(final_pwm_value <=0 )
    return 0;
  else
    return (final_pwm_value > 255)? 255 : final_pwm_value;
}
/*********/

#include <PS4BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
//USB Set UP
USB Usb;
USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);

// After that you can simply create the instance like so and then press the PS button on the device
//PS4BT PS4(&Btd);

bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;

int lx = 0;
int ly = 0;


void dpadmovement()
{
      if (PS4.getButtonPress(UP)) { //when Up button is pressed(leftside of the controller), the light of the controller will light up in red colour
        ForwardPIDcontrol(80);
        //Serial.println("Forward");
      }else if (PS4.getButtonPress(RIGHT)) { //when Right button is pressed, the light of the controller will light up in blue colour
        RightPIDcontrol(80);
        //Serial.println("Right");
      }else if (PS4.getButtonPress(DOWN)) { //when Down button is pressed, the light of the controller will light up in yellow colour
         BackwardPIDcontrol(80);
         //Serial.println("Backward");
      }else if (PS4.getButtonPress(LEFT)) { //when left button is pressed, the light of the controller will light up in green colour
        LeftPIDcontrol(80);
        //Serial.println("Left");
      }else if (PS4.getButtonPress(L1)){ //when the L1 button is pressed, it will serial print "L1"
        RotateLeft(80);
      }else if (PS4.getButtonPress(R1)){ //when the R1 button is pressed, it will serial print "R1"
        RotateRight(80);
      }else{
        MotorStopping();
      }
}

void joyStickMovement()
{
  if ( PS4.getAnalogHat(LeftHatY) <= 117) {
    ly = map( PS4.getAnalogHat(LeftHatY), 117, 0, 0, 230);
  }
  else if ( PS4.getAnalogHat(LeftHatY) >= 137){
    ly = map( PS4.getAnalogHat(LeftHatY), 137, 255, 0, -230);
  }
  else{
    ly = 0;
  }
  if ( PS4.getAnalogHat(LeftHatX) <= 117) {
    lx = map( PS4.getAnalogHat(LeftHatX), 117, 0, 0, -230);
  }
  else if ( PS4.getAnalogHat(LeftHatX) >= 137){
    lx = map( PS4.getAnalogHat(LeftHatX), 137, 255, 0, 230);
  }
  else{
    lx = 0;
  }
  if (ly > 0 && lx < 10 && lx > -10 )
  {
    ForwardPIDcontrol(ly);
  }

  else if (ly < 0 && lx < 10 && lx > -10 )
  {
    BackwardPIDcontrol(-ly);
  }

  else if (lx > 0 && ly < 10 && ly > -10 )
  {
    RightPIDcontrol(lx);
  }

  else if (lx < 0 && ly < 10 && ly > -10 )
  {
    LeftPIDcontrol(-lx);
  }

  else if (lx > 10 && ly > 10)
  {
    int pwm_out = lx > ly? lx:ly;
    ForwardRightPIDcontrol(pwm_out);
  }

  else if (lx < -10 && ly > 10)
  {
    int pwm_out = -lx > ly? -lx:ly;
    ForwardLeftPIDcontrol(pwm_out);
  }

  else if (lx < -10 && ly < -10)
  {
    int pwm_out = -lx > -ly? -lx:-ly;
    BackwardLeftPIDcontrol(pwm_out);
  }

  else if (lx > 10 && ly < -10)
  {
    int pwm_out = lx > -ly? lx:-ly;
    BackwardRightPIDcontrol(pwm_out);
  }

  else if (lx == 0 && ly == 0)
  {
    MotorStopping();
  }
}

void RotateLeft(int motor_speed)
{
  PORTA &= ~(1 << dir_1);
  PORTA |= (1 << dir_2);
  PORTA &= ~(1 << dir_3);
  PORTA |= (1 << dir_4);
  analogWrite(wheel1, motor_speed);
  analogWrite(wheel2, motor_speed);
  analogWrite(wheel3, motor_speed);
  analogWrite(wheel4, motor_speed);
}

void RotateRight(int motor_speed)
{
  PORTA |= (1 << dir_1);
  PORTA &= ~(1 << dir_2);
  PORTA |= (1 << dir_3);
  PORTA &= ~(1 << dir_4);
  analogWrite(wheel1, motor_speed);
  analogWrite(wheel2, motor_speed);
  analogWrite(wheel3, motor_speed);
  analogWrite(wheel4, motor_speed);
}

//PIDcontrol
void ForwardPIDcontrol(int pwm)
{
 /*****/
  /* If deviated to right,
   *  slow down left wheel
   *  Since PIDvalue is -, plus left wheel
   *  The reason why left wheel is not divided by 5 is it can be minus more.
   *  If deviated to left
   *  slow down right wheel
   *  Since PIDvalue is +, negative right wheel
   */

    PORTA |= (1 << dir_1);
    PORTA |= (1 << dir_2);
    PORTA |= (1 << dir_3);
    PORTA |= (1 << dir_4);
    aligned = false;

      if (Output < 0)//deviate to right
      {
        analogWrite(wheel1, capPWMValue(pwm));
        analogWrite(wheel2, capPWMValue(pwm - Output));
        analogWrite(wheel3, capPWMValue(pwm));
        analogWrite(wheel4, capPWMValue(pwm - Output));
      }
      else if (Output > 0)//deviate to left
      {
        analogWrite(wheel1, capPWMValue(pwm + Output));
        analogWrite(wheel2, capPWMValue(pwm));
        analogWrite(wheel3, capPWMValue(pwm + Output));
        analogWrite(wheel4, capPWMValue(pwm));
      }
      else //Move forward without turning sides
      {
      analogWrite(wheel1, pwm);
      analogWrite(wheel2, pwm);
      analogWrite(wheel3, pwm);
      analogWrite(wheel4, pwm);
    }
}

void BackwardPIDcontrol(int  pwm)
{
  PORTA &= ~(1 << dir_1);
  PORTA &= ~(1 << dir_2);
  PORTA &= ~(1 << dir_3);
  PORTA &= ~(1 << dir_4);
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, capPWMValue(pwm - Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, capPWMValue(pwm - Output));
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, capPWMValue(pwm + Output));
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm + Output));
    analogWrite(wheel4, capPWMValue(pwm));
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, pwm);
  }
}

void LeftPIDcontrol(int pwm)
{
  PORTA &= ~(1 << dir_1);
  PORTA |= (1 << dir_2);
  PORTA |= (1 << dir_3);
  PORTA &= ~(1 << dir_4);
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, capPWMValue(pwm - Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, capPWMValue(pwm - Output));
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, capPWMValue(pwm + Output));
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm + Output));
    analogWrite(wheel4, capPWMValue(pwm));
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, pwm);
  }
}

void RightPIDcontrol(int pwm)
{
  PORTA |= (1 << dir_1);
  PORTA &= ~(1 << dir_2);
  PORTA &= ~(1 << dir_3);
  PORTA |= (1 << dir_4);
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, capPWMValue(pwm - Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, capPWMValue(pwm - Output));
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, capPWMValue(pwm + Output));
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm + Output));
    analogWrite(wheel4, capPWMValue(pwm));
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, pwm);
  }
}

/*
void RotateLeftPIDcontrol(int pwm)
{
  /*digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);*/

  /*PORTA &= ~(1 << dir_1);
  PORTA &= ~(1 << dir_2);
  PORTA |= (1 << dir_3);
  PORTA |= (1 << dir_4);
  aligned = false;*/
/*
  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm - Output));
    analogWrite(wheel4, capPWMValue(pwm - Output));
  }

  else if (Output > 0)
  {
    analogWrite(wheel1, capPWMValue(pwm + Output));
    analogWrite(wheel2, capPWMValue(pwm + Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, capPWMValue(pwm));
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, pwm);
  }
}*/

/*
void RotateRightPIDcontrol(int pwm)
{
  /*digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);*/

  /*PORTA |= (1 << dir_1);
  PORTA |= (1 << dir_2);
  PORTA &= ~(1 << dir_3);
  PORTA &= ~(1 << dir_4);
  aligned = false;*/
/*
  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm - Output));
    analogWrite(wheel4, capPWMValue(pwm - Output));
  }

  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, capPWMValue(pwm + Output));
    analogWrite(wheel2, capPWMValue(pwm + Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, capPWMValue(pwm));
  }

  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, pwm);
  }
}
*/

void ForwardLeftPIDcontrol(int pwm)
{
  /*digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);*/
  PORTA |= (1 << dir_1);
  PORTA |= (1 << dir_2);
  PORTA |= (1 << dir_3);
  PORTA |= (1 << dir_4);
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, 0);
    analogWrite(wheel2, capPWMValue(pwm - Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, 0);
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, 0);
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm + Output));
    analogWrite(wheel4, 0);
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, 0);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, 0);
  }
}

void ForwardRightPIDcontrol(int pwm)
{
  /*digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);*/
  PORTA |= (1 << dir_1);
  PORTA |= (1 << dir_2);
  PORTA |= (1 << dir_3);
  PORTA |= (1 << dir_4);
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, 0);
    analogWrite(wheel3, 0);
    analogWrite(wheel4, capPWMValue(pwm - Output));
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, capPWMValue(pwm + Output));
    analogWrite(wheel2, 0);
    analogWrite(wheel3, 0);
    analogWrite(wheel4, capPWMValue(pwm));
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, 0);
    analogWrite(wheel3, 0);
    analogWrite(wheel4, pwm);
  }
}

void BackwardLeftPIDcontrol(int pwm)
{
  /*digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);*/
  PORTA &= ~(1 << dir_1);
  PORTA &= ~(1 << dir_2)
  PORTA &= ~(1 << dir_3);
  PORTA &= ~(1 << dir_4)
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, capPWMValue(pwm - Output));
    analogWrite(wheel2, 0);
    analogWrite(wheel3, 0);
    analogWrite(wheel4, capPWMValue(pwm));
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, capPWMValue(pwm));
    analogWrite(wheel2, 0);
    analogWrite(wheel3, 0);
    analogWrite(wheel4, capPWMValue(pwm + Output));
  }

  else
  {
    analogWrite(wheel1, pwm);
    analogWrite(wheel2, 0);
    analogWrite(wheel3, 0);
    analogWrite(wheel4, pwm);
  }
}

void BackwardRightPIDcontrol(int pwm)
{
  /*digitalWrite(dir_1, LOW);
  digitalWrite(dir_2, LOW);
  digitalWrite(dir_3, LOW);
  digitalWrite(dir_4, LOW);*/
  PORTA &= ~(1 << dir_1);
  PORTA &= ~(1 << dir_2)
  PORTA &= ~(1 << dir_3);
  PORTA &= ~(1 << dir_4)
  aligned = false;

  if (Output < 0)//deviate to right
  {
    analogWrite(wheel1, 0);
    analogWrite(wheel2, capPWMValue(pwm));
    analogWrite(wheel3, capPWMValue(pwm - Output));
    analogWrite(wheel4, 0);
  }
  else if (Output > 0)//deviate to left
  {
    analogWrite(wheel1, 0);
    analogWrite(wheel2, capPWMValue(pwm + Output));
    analogWrite(wheel3, capPWMValue(pwm));
    analogWrite(wheel4, 0);
  }

//Move forward 0 degree.
  else
  {
    analogWrite(wheel1, 0);
    analogWrite(wheel2, pwm);
    analogWrite(wheel3, pwm);
    analogWrite(wheel4, 0);
  }
}

void MotorStopping()
{
  analogWrite(wheel1, 0);
  analogWrite(wheel2, 0);
  analogWrite(wheel3, 0);
  analogWrite(wheel4, 0);
}

void setup()
{
  //IMU
  //0xFF 0xAA 0x52 is command for initializing angle in z Direction =0
  Serial1.begin(115200);
  Serial1.write(0xFF);
  Serial1.write(0xAA);
  Serial1.write(0x52);
  Serial1.write(0xFF); //horizontal
  Serial1.write(0xAA);
  Serial1.write(0x65);
  Serial.begin(115200);

#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1)
  {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));

  pinMode(dir_1,OUTPUT);
  pinMode(dir_2,OUTPUT);
  pinMode(dir_3,OUTPUT);
  pinMode(dir_4,OUTPUT);
  pinMode(wheel1,OUTPUT);
  pinMode(wheel2,OUTPUT);
  pinMode(wheel3,OUTPUT);
  pinMode(wheel4,OUTPUT);
  //PID parameters
  setpoint = 0;
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(sampletime);

  MotorStopping();
}

void loop() {
  Usb.Task();

  if (PS4.connected()) {
    if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 ){
      joyStickMovement();
    }
    else
      dpadmovement();
  }
}
