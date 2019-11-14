#include <iostream>
#include "linux_env.h"
#include "Game.h"
//#include "Map.h"
int main(){
//   int t=0;
//    screenClear();
//    for(int i=0;i<RectnumW;i++){
//        for(int j=0;j<RectnumH;j++){
//            drawWholeRect(i*RectW,j*RectH,RectW,RectH,GRAY);
//           // drawRect(i*RectW,j*RectH,RectW,RectH,BLUE);
//            // clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
//        }
//    }
//   // drawText(17, 17, "sdsdsd", GREEN, BROWN);
//   // drawPixel(41,35,RED);
//    //printf("\033[%d;%dH ", 25, 25);
//    drawTextB(16,4,"Plant VS Zombie",WHITE,BLACK);
//    drawTextB(18,17,"Start",WHITE,BLACK);
//    drawTextB(18,20,"Exit",WHITE,BLACK);
//    init_keyboard();
//    int state=100;
//    while(1)
//    {
//        kbhit();
//        if(readch()==119){
//            state+=1;
//        }
//        else if(readch()==115){
//            state-=1;
//        }
//        if(state%2==0){
//            drawTextB(18,17,"Start",WHITE,RED);
//            drawTextB(18,20,"Exit",WHITE,BLACK);
//        }else{
//            drawTextB(18,17,"Start",WHITE,BLACK);
//            drawTextB(18,20,"Exit",WHITE,RED);
//        }
//        if(readch()==27){
//            break;
//        }
//       // printf("\n%d\n", readch());
//    }
//    close_keyboard();
//
//    while(t<1000000){
////my_sleep(10);
//
//     //   int pixel_map[][];
////    for(int i=0;i<60;i++){
////        for(int j=0;j<40;j++){
////            if(j==10||j==21||j==32){
////            drawPixel(i,j,GREEN);}
////            else {
////                drawPixel(i,j,WHITE);
////            }
////        }
////    }
//      //  drawRect(0,0,5,5,RED);
//
////        drawPixel(1,1,RED);
////        drawPixel(1,4,RED);
////        drawPixel(4,4,RED);
////        drawPixel(4,1,RED);
////        drawPixel(1,7,RED);
////        drawPixel(6*6+4,5*6+4,PINK);
////        drawPixel(6*RectnumW-1,0,YELLOW);
////        drawPixel(6*RectnumW-1,6*RectnumH-1,YELLOW);
////        drawPixel(4,4,YELLOW);
////        drawPixel(6,6,YELLOW);
////        drawPixel(MAPW,MAPH,GREEN);
////        drawRect(3*RectW,3*RectH,RectW,RectH,BLUE);
////        drawLine(7,7,4,true,BROWN);
//   //    drawText(17, 17, "sdsdsd", GREEN, BROWN);
//
//
//    //    drawWholeRect(10,10,5,5,BLUE);
// //   drawLineB(0,1,3,false,RED);
//        //drawRect(17,17,3,2,RED);
////        drawTextB(18,17,"start",BLACK,WHITE);
//
//
//       // drawRect(18,17,5,1,RED);
//    //    printf(":%d\n",scanKeyboard_test());
//    t++;}
Game test1;
test1.test();
//int j=0;
//screenClear();
//for(int i=0;i<256;i++){
//
//    drawText(0,j,"colortest",i,WHITE);printf("                 %d",i+1);
//    j++;
//}
//screenClear();
//drawdefence(0,0,10,WHITE);
  return 0;
}