#include <iostream>
#include "linux_env.h"
int main(){
my_sleep(1000); 
  screenClear();

  drawPixel(0,0,GREEN);
my_sleep(1000); 
  drawPixelC(2,0,'h','e',BLUE,RED);
  return 0;
}