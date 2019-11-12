#include <iostream>
#include "ScreenDraw.h"
int main(){
  screenClear();
  drawPixel(0,0,GREEN);
  drawPixelC(2,0,'h','e',BLUE,RED);
  return 0;
}