#include <CapacitiveSensor.h>
#include "pitches.h"

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(3,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(5,4);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(7,6);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int buzzerpin = 12;

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example


   Serial.begin(9600);
   
   tone(buzzerpin, NOTE_C4, 1000 / 4);
   delay(1.3 * 1000 / 4);
   noTone(12);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    delay(10);                             // arbitrary delay to limit data to serial port 
    
    if(total1>=500)
      {
        digitalWrite(13, LOW);
            tone(12, NOTE_C4, 1000 / 4);
      }
     if(total2>=500){
      digitalWrite(13, LOW);
           // myservo.write(180); 
            tone(12, NOTE_A3, 1000 / 4);
            //delay(1.3 * 1000 / 4);
            //noTone(8);
    }
     if(total3>=500){
      digitalWrite(13, HIGH);
           // myservo.write(90); 
            tone(12, NOTE_F3, 1000 / 4);
            //delay(1.3 * 1000 / 4);
            //noTone(8);
    }
    
}
