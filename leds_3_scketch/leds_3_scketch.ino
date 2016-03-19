#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  //strip.setBrightness(30);    // Brightness:[0-255]

}

void loop() {

  // Set pixel color:
  // strip.setPixelColor(pixel_number, red, green, blue);     pixel_number:[0,1,2]   [red,green,blue]:[0-255]

  //strip.setPixelColor(1, 255, 0, 0);
  
  //strip.show(); 

  // uint32_t magenta = strip.Color(255, 0, 255);
  // strip.setPixelColor(n, magenta);



  uint32_t magenta = strip.Color(255, 0, 255);
  uint32_t orange = strip.Color(255, 255, 0);
  uint32_t nope = strip.Color(255, 255, 0);
  
  for(int i=0; i<3; i++){
  
     strip.setPixelColor(i, magenta);
     strip.setPixelColor(i-1, 0,0,0);
     delay(400);      
     strip.show();

  }
  
  strip.setPixelColor(2, 0,0,0);
  strip.show();

     
}
