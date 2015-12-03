#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(95, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

int brigthness=20;
int grow_timer=1000;
int salt=66;


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip.begin();
  strip.setBrightness(brigthness);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 
  for(int i=salt; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
   for(int i=0; i<=8; i++) {
    strip.setPixelColor(i+salt, strip.Color(0, 250, 0));
    strip.show();
    delay(500);
  }
  
  for(int i=0;i<3;i++){
    strip.setPixelColor(9+i+salt,strip.Color(250,0,0)); //tronco
    //derecha
    strip.setPixelColor(15-i+salt,strip.Color(250,0,0));
    strip.setPixelColor(16+i+salt,strip.Color(250,0,0));
    //izquierda
    strip.setPixelColor(26+i+salt,strip.Color(250,0,0));
    strip.setPixelColor(25-i+salt,strip.Color(250,0,0));

    if(i==0 || i==1){
      int i2=i;
    strip.setPixelColor(20-i2+salt,strip.Color(250,0,0));
    strip.setPixelColor(21+i2+salt,strip.Color(250,0,0));
      
    }
    strip.show();
    delay(500);
  }
      strip.setPixelColor(12+salt,strip.Color(250,0,0)); //tronco
      strip.show();
      delay(500);

    
}
