//Pajaro
// by @demiurgosoft

#include <Servo.h> 

//Since it is a continuous servo, values are speed, not position
Servo eye1,eye2;  // create servo object to control a servo 
Servo bird;

int eye_delay=400;
 
void setup() 
{ 
  eye1.attach(12);  // attaches the servo on pin 9 to the servo object 
  eye2.attach(10);
  bird.attach(1);
} 
 
void loop() 
{ 
  //90=stop, >90 counter-clockwise, <90 clockwise
  eyebrow_movement();
} 

//values depend on each servo
void eyebrow_movement(){
  eye1.write(100);
  eye2.write(106);
  delay(eye_delay); 
  eye1.write(85);
  eye2.write(80); 
  delay(eye_delay); 

}

