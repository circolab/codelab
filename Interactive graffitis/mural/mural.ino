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
int salt=66;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

//strip.setBrightness(50);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
}

void loop() {
  uint16_t total=66;
  uint16_t inicio=1;
  uint16_t fin=44;
 for(int i=0;i<10;i++) Lluvia2(total);
  florecilla();
  for(int i=0;i<10;i++) Lluvia2(total);
  for(int i=salt; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  }
  
  /*
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
  */

void Lluvia(uint16_t inicio, uint16_t fin){
  long randtime;
  for(uint16_t i=inicio; i<=fin; i++) {
     strip.setPixelColor(i, strip.Color(127, 127, 127));
     strip.show();
     delay(50);
     if(i>=1){
       strip.setPixelColor(i-1, 0);
     }
     else{
       strip.setPixelColor(fin, 0);
     }
     strip.show();
     delay(50);
    }
    strip.setPixelColor(fin, 0);
    strip.show();
    randtime = random(300,600);
    delay(randtime);
  
  }

void Lluvia2(uint16_t longitud){
  int randomizer = random(0,longitud-10);

  for(uint16_t i=randomizer; i<=randomizer+10; i++) {
    if(i>=30 && i<=37){
    //break;
    }
    else{
    strip.setPixelColor(i, strip.Color(127, 127, 127));
     strip.show();
     delay(20);
     
     if(i>=1){
       strip.setPixelColor(i-1, 0);
     }
     else{
       strip.setPixelColor(randomizer+10, 0);
     }
    
/*
     if(i>=28 && i<38){
      strip.setPixelColor(34, strip.Color(127, 127, 127));
      strip.setPixelColor(33, strip.Color(127, 127, 127));
      strip.setPixelColor(32, strip.Color(127, 127, 127));
      strip.setPixelColor(31, strip.Color(127, 127, 127));
      strip.setPixelColor(31, 0);
      strip.setPixelColor(32, 0);
      strip.setPixelColor(33, 0);
      strip.setPixelColor(34, 0);   
     }
     */
     strip.show();
     delay(20);
    }
    }
    strip.setPixelColor(randomizer+10, 0);
    strip.show();
    for(uint16_t i=randomizer; i<=randomizer+10; i++) {
      strip.setPixelColor(i, 0);
      strip.show();
    }

}


      
     void florecilla(){
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
  

