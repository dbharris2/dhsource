/*

Title : DHColor.cpp
Author : Devon Harris

Created : April 17 2016

*/

#include "DHColor.h"

DHColor::DHColor(const int red, const int green, const int blue) {
  _blue = blue;
  _green = green;
  _red = red;
}

int DHColor::getBlue() {
  return _blue;
}

int DHColor::getGreen() {
  return _green;
}

int DHColor::getRed() {
  return _red;
}
