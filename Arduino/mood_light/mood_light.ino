#include <DHLed.h>

#include <DHColor.h>

#define redPin 9
#define greenPin 10
#define bluePin 11

#define delayOutput 10

void setup() {
//  DHLed led = DHLed(redPin, greenPin, bluePin);
//  led.setColor(DHColor(0,0,0));
}

void loop() {
  DHLed led = DHLed(redPin, greenPin, bluePin);

  for (int i = 0; i < 255; i++) {
    DHColor color = DHColor(255-i, 0, i);
    led.setColor(color);
    delay(delayOutput);    
  }

  for (int i = 0; i < 255; i++) {
    DHColor color = DHColor(0, i, 255-i);
    led.setColor(color);
    delay(delayOutput);    
  }

  for (int i = 0; i < 255; i++) {
    DHColor color = DHColor(i, 255-i, 0);
    led.setColor(color);
    delay(delayOutput);
  }
}
