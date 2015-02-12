#include <Adafruit_NeoPixel.h>

#include <PinChangeInt.h>
#include <avr/power.h>

#define PIN            9 //the neopixel output pin

#define NUMPIXELS      13

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //  neopixel setup

int pause = 10;


void setup() {
    pixels.begin();

}

void loop() {
  colorcycle();
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

}



void colorcycle(){
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(pause); // Delay for a period of time (in milliseconds).

  }



  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,255,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(pause); // Delay for a period of time (in milliseconds).
  }
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,255)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(pause); // Delay for a period of time (in milliseconds).

  }
  
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,255,255)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(pause); // Delay for a period of time (in milliseconds).

  }
  
      for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(pause*3); // Delay for a period of time (in milliseconds).

  }
}
