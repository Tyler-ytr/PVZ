#include <iostream>
#include "linux_env.h"
//#include "Map.h"
int main(){
   int t=0;
    screenClear();
    while(t<100){
my_sleep(1000);
 // screenClear();
     //   int pixel_map[][];
//    for(int i=0;i<60;i++){
//        for(int j=0;j<40;j++){
//            if(j==10||j==21||j==32){
//            drawPixel(i,j,GREEN);}
//            else {
//                drawPixel(i,j,WHITE);
//            }
//        }
//    }
      //  drawRect(0,0,5,5,RED);
        for(int i=0;i<RectnumW;i++){
            for(int j=0;j<RectnumH;j++){
                drawWholeRect(i*RectW,j*RectH,RectW,RectH,WHITE);
                drawRect(i*RectW,j*RectH,RectW,RectH,BLUE);
               // clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
            }
        }
        drawPixel(1,1,RED);
        drawPixel(1,4,RED);
        drawPixel(4,4,RED);
        drawPixel(4,1,RED);
        drawPixel(1,7,RED);
        drawPixel(6*6+4,5*6+4,PINK);
        drawPixel(6*RectnumW-1,0,YELLOW);
        drawPixel(6*RectnumW-1,6*RectnumH-1,YELLOW);
        drawPixel(4,4,YELLOW);
        drawPixel(6,6,YELLOW);
        drawPixel(MAPW,MAPH,GREEN);
        drawRect(3*RectW,3*RectH,RectW,RectH,BLUE);
    //    drawWholeRect(10,10,5,5,BLUE);
 //   drawLineB(0,1,3,false,RED);
       // printf("\033[H");
    t++;}
//    init_keyboard();
//    while(1)
//    {   my_sleep(50);
//        kbhit();
//        printf("\n%d\n", readch());
//        long long int tsdsd=getTime();
//    //    printf("\n%d",tsdsd);
//        if(readch()==113)break;
//    }
//    close_keyboard();

//    printf("\033[31mThe color,%s!\033[1m\n","haha");
//    printf("\033[31mThe color,%s!\033[4m\n","haha");
//    printf("\033[31mThe color,%s!\033[5m\n","haha");
//    printf("\033[31mThe color,%s!\033[7m\n","haha");
//    printf("\033[31mThe color,%s!\033[8m\n","haha");
//    printf("\033[31mThe color,%s!\033[0m\n","haha");
//    printf("\033[47;31mThe color,%s!\033[0m\n","haha");
//    printf("\033[47mThe color,%s!\033[0m\n","haha");
//    sleep(2);
//    printf("\033[47m%s!\033[5A\n","up 5");
//    sleep(2);
//    printf("\033[47m%s!\033[9B\n","down 9");
//    sleep(2);
//    printf("\033[47m%s!\033[19C\n","right 19");
//    printf("right19");
//    sleep(2);
//    printf("\033[47m%s!\033[10D\n","left 10");
//    printf("left 10");
//    sleep(2);
//    printf("\033[47m%s!\033[50;20H\n","move to y:50,x 20");
//    printf("y50 x 20");
//    sleep(2);
//    printf("\033[47m%s!\033[?25l\n","hide cursor");
//    sleep(2);
//    printf("\033[47m%s!\033[?25h\n","sow cursor");
//    sleep(2);
//    printf("\033[47m%s!\033[2J\n","clear scleen");

//    void drawPixel(int x, int y, int color);
//    void drawPixelC(int x, int y, char c1, char c2, int color, int backColor);
//    void screenClear();
//    void clearRect(int x, int y, int w, int h);
//    void drawLine(int x, int y, int l, bool hori, int color);
//    void drawLineC(int x, int y, int l, char c1, char c2, bool hori, int color, int backColor);
//    void drawRect(int x, int y, int w, int h, int color);
//    void drawWholeRect(int x, int y, int w, int h, int color);
//    void drawText(int x, int y, string str, int color, int backColor);
 // drawPixel(0,0,GREEN);
//my_sleep(1000);
  //drawPixelC(2,0,'h','e',BLUE,RED);
  //test();
  return 0;
}