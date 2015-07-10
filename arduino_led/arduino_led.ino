
/*fuse settings for atmega32u4

BODLEVEL = 2V6
HWBE = [ ]
OCDEN = [ ]
JTAGEN = [ ]
SPIEN = [X]
WDTON = [ ]
EESAVE = [ ]
BOOTSZ = 2048W_3800
BOOTRST = [X]
CKDIV8 = [ ]
CKOUT = [ ]
SUT_CKSEL = EXTXOSC_8MHZ_XX_16KCK_65MS

EXTENDED = 0xCB (valid)
HIGH = 0xD8 (valid)
LOW = 0xFF (valid)*/








//https://github.com/j9k/apricot_leds/

//https://github.com/GreyGnome/PinChangeInt

#include <Adafruit_NeoPixel.h>

#include <PinChangeInt.h>
#include <avr/power.h>

#define PIN            9 //the neopixel output pin
#define BUTTONPIN      10
#define NUMPIXELS      13
#define HDDPIN         11
volatile uint16_t hddInterruptCount=0;
volatile uint16_t buttonInterruptCount=0;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //  neopixel setup


//debounce variables
volatile unsigned long debouncing_time = 15; //Debouncing Time in Milliseconds
volatile unsigned long last_micros;



int pause = 1;
int buttonPin = 10;
int hddPin = 11;
int buttonCount = 1;
int red = 80;
int green = 80;
int blue = 80;



void setup() {
    pixels.begin();
    clear_Led();

pinMode(BUTTONPIN, INPUT_PULLUP); //may need to change back to normal input for production
attachPinChangeInterrupt(BUTTONPIN, button_ISR, FALLING);

pinMode(hddPin, INPUT_PULLUP);
attachPinChangeInterrupt(HDDPIN, hdd_ISR, FALLING);

}

void loop() {
  
  buttonCount = buttonInterruptCount % 2;
  
  
  switch (buttonCount) {
  case 1:
      colorcycle();
    break;
  case 2:
    clear_Led();
    break;
  default: 
    delay(50);
}
}

void button_ISR(){        // this function needs to be short and exit naturally
    if((long)(micros() - last_micros) >= debouncing_time * 1000) {
      buttonInterruptCount++;
      pause = pause++ % 100;    
      last_micros = micros();
    }
}
  
void hdd_ISR(){        // this function needs to be short and exit naturally
    
    hddInterruptCount++;
    //if((long)(micros() - last_micros) >= debouncing_time * 1000) {
     // hddInterruptCount++;
     // pause = pause++ % 100;
     // last_micros = micros();
    }


void clear_Led() {

      for(int i=0;i<NUMPIXELS;i++){
          pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      pixels.show();
}


void colorcycle(){
  pause = buttonInterruptCount;
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(red,0,0)); 
    pixels.show(); 
    delay(pause); // Delay for a period of time (in milliseconds).

  }

  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,green,0)); 
    pixels.show(); 
    delay(pause); 
  }
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,blue)); 
    pixels.show();
    delay(pause); 
  }
  
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(red,green,blue)); 
      pixels.show(); 
      delay(pause); 
  }
  
    for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(0,0,0)); 
      pixels.show(); 
      delay(pause*3); 
  }
}
