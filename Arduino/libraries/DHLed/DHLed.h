/*

Title : DHLed.h
Author : Devon Harris

Description : Object representing an RGB LED on an Arduino

Created : April 17 2016

*/

#ifndef _DHLed_h
#define _DHLed_h

#include "DHColor.h"

class DHLed {
public:
  DHLed(const int redPin, const int greenPin, const int bluePin);
  void setColor(DHColor color);

private:
  int _bluePin;
  int _greenPin;
  int _redPin;
};

#endif
