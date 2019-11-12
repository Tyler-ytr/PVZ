#include "linux_env.h"
void my_sleep(int time){
  int i=time*1000;
 usleep(i); 
}