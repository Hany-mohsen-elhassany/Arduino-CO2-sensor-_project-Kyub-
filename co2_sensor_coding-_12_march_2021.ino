/*
  Reading CO2, humidity and temperature from the SCD30 + led light
  it light blue if the co2 is blew 800 , from 800 to 1000 - accpted level indoors- it gets green above 1050 it turns red  
  By: hany 
  Date: february 24th, 2021

  this example prints the current CO2 level, relative humidity, and temperature in C.

  Hardware Connections:
  Attach RedBoard to computer using a USB cable.
  Connect SCD30 to RedBoard using Qwiic cable.
  Open Serial Monitor at 115200 baud.
*/

#include <Wire.h>

#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD30
SCD30 airSensor;


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 14 // define the degital pin here 

#define LEDS 24 // put the number of led here

#define OFFSET 0 // you can define your starting led from here 

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_RGB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// to define the co2 variable 
word co2 = 0;
uint32_t color = 0;

void setup()
{
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
  
  // strting with the co2 reading now 
  Serial.begin(115200);
  Serial.println("SCD30 Example");
  Wire.begin();

  if (airSensor.begin() == false)
  {
    Serial.println("Air sensor not detected. Please check wiring. Freezing...");
    while (1)
      ;
  }

}

void loop() {
  if (airSensor.dataAvailable()) {
    co2 = airSensor.getCO2();
    Serial.print("co2(ppm):");
    Serial.println(co2);
  


  
    //limit co2 to available range on watch face
    if (co2 > 1300) co2 = 1300;
    if (co2 < 300) co2 = 300;
    

   
    color = strip.Color(255, 0, 0); // red
    if (co2 < 700){
      color = strip.Color(0, 0, 255); // Blue
    } else if (co2 > 1000) {
      color = strip.Color(0, 255, 0); // green
    }
     //change your scale steps (50 is the step count , and 4 is constant amount to center the scale in the middle of 24 led light )
    lightScale(round(co2 / 50 - 4), color, 50);
 
    Serial.print(" temp(C):");
    Serial.print(airSensor.getTemperature(), 1);

    Serial.print(" humidity(%):");
    Serial.print(airSensor.getHumidity(), 1);

    Serial.println();
  } else Serial.println("Waiting for new data");

  delay(800);
}
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
void lightScale(uint8_t numberOfPixels, uint32_t color, uint8_t wait) {
  strip.clear();
  strip.show();
  strip.fill(color, OFFSET, numberOfPixels);
  if (OFFSET + numberOfPixels > LEDS) {
    strip.fill(color, 0, numberOfPixels + OFFSET - LEDS);
  }
  strip.show();
}
