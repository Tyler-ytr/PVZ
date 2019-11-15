//
// Created by Larryytr on 2019/11/14.
//
#include "Game.h"
#include "linux_env.h"

int Game::init() {
    screenClear();
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < RectnumH; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, GRAY);
        }
    }
    drawTextB(16, 4, "Plant VS Zombie", WHITE, BLACK);
    drawTextB(18, 17, "Start", WHITE, BLACK);
    drawTextB(18, 20, "Exit", WHITE, BLACK);
    init_keyboard();
    int state = 100;
    while (1) {
        kbhit();
        switch (readch()) {
            case 119:
                state += 1;
                break;
            case 115:
                state -= 1;
                break;
            case 10:
                if (state % 2 == 0) {
                    close_keyboard();
                    return 1;
                }//Start}
                else {
                    close_keyboard();
                    return 0;//Exit
                }
            default:
                break;
        }
        if (state % 2 == 0) {
            drawTextB(18, 17, "Start", WHITE, RED);
            drawTextB(18, 20, "Exit", WHITE, BLACK);//Start
        } else {
            drawTextB(18, 17, "Start", WHITE, BLACK);
            drawTextB(18, 20, "Exit", WHITE, RED);//Exit
        }

    }
    // close_keyboard();
}

void Game::test() {
    int state = init();
    if (state == 1) {
        printf("start");
        int j = play();
    } else {
        printf("Exit");
    }
}
int check_shop(int x,int y){
    if(y==0){
        return 1;
    }else{
        return 0;
    }
}
int Game::play() {
    int bx=0;int by=0;
    int x = 0;
    int y = 0;//存储坐标系
    int stop=0;
//    t=0;sun=0;
//    score=0;
    controller c1;
    plant temp;

    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < 1; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, shopcolor);
               // drawRect(i*RectW,j*RectH,RectW,RectH,LIGHTGRAY);
            // clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
        }
    }
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 1; j < RectnumH; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, grasscolor);
               drawRect(i*RectW,j*RectH,RectW,RectH,LIGHTGRAY);
            // clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
        }
    }
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < 1; j++) {
            drawdefence2(i*RectW,j*RectH,RectH,WHITE,shopcolor);
        }
    }
    drawRect(0*RectW,0*RectH,RectW,RectH,LIGHTGRAY);
   // drawdefence2(0,0,6,BLACK,RED);
//    for(int i=0;i<RectnumW;i++){
//        for(int j=1;j<RectnumH;j++){
//            drawdefence(i*6,j*6,6,WHITE,grasscolor);
//        }
//    }
//for(int i=0;i<5;i++){
//    for(int j=0;j<5;j++){
//        drawText(i*RectW+2, j*RectH+3,"豌豆射手", BLACK, plantcolor);
//        drawPixel(i*RectW+2, j*RectH+4 ,plantcolor);
//        drawPixel(i*RectW+2, j*RectH+5 ,plantcolor);
//        drawText(i*RectW+1, j*RectH+6,"HP:100", RED, plantcolor);
//    }
//}
//    drawPixel(4, RectH+2 ,ORANGE);
//    drawText(3, RectH+3,"向日葵", BLACK, ORANGE);
//    drawPixel(4, RectH+4 ,ORANGE);
//    drawPixel(4, RectH+5 ,plantcolor);
//    drawText(3, RectH+6,"HP:100", RED, plantcolor);
//    drawLine(2, RectH+3, 3, true, BLACK);
//    drawPixel(3, RectH+4 ,plantcolor);
//    drawLine(2, RectH+5, 3, true, RED);
//    drawLine(2, RectH+6, 3, true, RED);
    //drawText(3, RectH+6,"HP:100", RED, GRAY );
    temp.draw();
    init_keyboard();
    while (1) {
//a: 97  d:100;
//w:119 s:115
        my_sleep(50);
        kbhit();
        switch (readch()) {
            case 119://w
                if (y - 1 >= 0)y = y - 1;
                break;
            case 115://s
                if (y + 1 < RectnumH)y = y + 1;
                break;
            case 97://a
                if (x - 1 >= 0)x = x - 1;
                break;
            case 100://d
                if (x + 1 < RectnumW)x = x + 1;
                break;
            case 27:stop=1;break;//结束游戏
            default:
                break;
        }
        if(check_shop(x,y)){
            drawRect(x*RectW,y*RectH,RectW,RectH,LIGHTGRAY);
            drawdefence2(x*RectW,y*RectH,RectH,WHITE,LIGHTGRAY);
        }else{
            ;drawRect(x*RectW,y*RectH,RectW,RectH,LIGHTGRAY);
        }

        if(check_shop(bx,by)){
            drawRect(bx*RectW,by*RectH,RectW,RectH,shopcolor);
            drawdefence2(bx*RectW,by*RectH,RectH,WHITE,shopcolor);
        }else{
            ;drawRect(bx*RectW,by*RectH,RectW,RectH,grasscolor);
        }
        c1.time_passing();



        





        bx=x;
        by=y;
      //  break;
        if(stop==1){
          //  close_keyboard();
            break;
        }
    }
    close_keyboard();


}
