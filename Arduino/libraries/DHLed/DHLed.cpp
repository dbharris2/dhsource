/*

Title : DHLed.cpp
Author : Devon Harris

Created : April 17 2016

*/

#include "DHLed.h"

#include "Arduino.h"

DHLed::DHLed(const int redPin, const int greenPin, const int bluePin) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  _bluePin = bluePin;
  _greenPin = greenPin;
  _redPin = redPin;
}

void DHLed::setColor(DHColor color) {
  analogWrite(_redPin, color.getRed());
  analogWrite(_greenPin, color.getGreen());
  analogWrite(_bluePin, color.getBlue());
}
