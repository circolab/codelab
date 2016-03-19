// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
} 
 
void loop() 
{ 
    buttonState = digitalRead(buttonPin);
    
 // val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 // val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
 // myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 

  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
      myservo.write(180); 
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
      myservo.write(0); 
  }
}
