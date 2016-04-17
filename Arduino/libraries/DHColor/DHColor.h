/*

Title : DHColor.h
Author : Devon Harris

Description : Simple object representing an RGB Color

Created : April 17 2016

*/

#ifndef _DHColor_h
#define _DHColor_h

class DHColor {
public:
  DHColor(const int red, const int green, const int blue);
  int getBlue();
  int getGreen();
  int getRed();

private:
  int _red;
  int _green;
  int _blue;
};

#endif
