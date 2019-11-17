//
// Created by Larryytr on 2019/11/14.
//
#include "Game.h"
#include "linux_env.h"
//#include "logic.h"

int Game::init() {
    screenClear();
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < RectnumH; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, GRAY);
        }
    }
    drawTextB(23, 4, "Plant VS Zombie ", WHITE, BLACK);
    drawText(24, 13, "殷天润 制作 ", WHITE, BLACK);
    drawTextB(25, 17, "Start", WHITE, BLACK);
    drawTextB(25, 20, "Exit", WHITE, BLACK);
    init_keyboard();
    int state = 100;
    while (1) {
        if (kbhit()) {
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
        }
        if (state % 2 == 0) {
            drawTextB(25, 17, "Start", WHITE, RED);
            drawTextB(25, 20, "Exit", WHITE, BLACK);//Start
        } else {
            drawTextB(25, 17, "Start", WHITE, BLACK);
            drawTextB(25, 20, "Exit", WHITE, RED);//Exit
        }

    }
    // close_keyboard();
}
int Game::failure(){
    ;   screenClear();
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < RectnumH; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, GRAY);
        }
    }
    drawTextB(23, 4, "Plant VS Zombie", WHITE, BLACK);
    drawTextB(20, 7, "THE ZOMBIES ATE YOUR BRAINS!!!", WHITE, BLACK);
    drawText_num(23, 10, "Your score is ",result, WHITE, BLACK);
    drawText(23, 13, "殷天润 制作 ", WHITE, BLACK);
    drawTextB(25, 17, "Restart", WHITE, BLACK);
    drawTextB(25, 20, "Exit", WHITE, BLACK);
    init_keyboard();
    int state = 100;
    while (1) {
        if (kbhit()) {
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
        }
        if (state % 2 == 0) {
            drawTextB(25, 17, "Restart", WHITE, RED);
            drawTextB(25, 20, "Exit", WHITE, BLACK);//Start
        } else {
            drawTextB(25, 17, "Restart", WHITE, BLACK);
            drawTextB(25, 20, "Exit", WHITE, RED);//Exit
        }

    }
}

void Game::test() {
    int state = init();
    while(1){
  //  int state = init();
    if (state == 1) {
     //   printf("start");
        int j = play();
        if (Game_win == 0) {
            int breakornot=failure();
            if(breakornot==0){
                screenClear();
                printf("Exit");
                break;
            }

       ;//     printf("Lose");
        }
        screenClear();

    } else {screenClear();
        printf("Exit");
        break;
    }

    }
  //  screenClear();
}

int check_shop(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return 0;
    }
}

int Game::play() {
    int bx = 0;
    int by = 0;
    int x = 0;
    int y = 0;//存储坐标系
    int stop = 0;
    int win = 0;
    controller c1;
    c1.plant_flowers_test(0, 1);
    c1.map_init();
    drawRect(0 * RectW, 0 * RectH, RectW, RectH, LIGHTGRAY);

    plant::plant_show();

    init_keyboard();
    while (1) {

        my_sleep(50);
        c1.time_passing();
        c1.zombie_fram();
        c1.both_move();
        c1.both_draw();
        c1.both_work();
        drawdefence((RectnumW) * RectW, RectH, RectH * 5, WHITE, grasscolor);
        c1.information_draw();
        win = c1.check_win();

//a: 97  d:100;
//w:119 s:115
        if (kbhit()) { ;
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
                case 98:
                    c1.buy_plant(x, y);
                    break;//b 购买
                case 110:
                    c1.plant_flowers(x, y);
                    break;//n 种植
                case 104:{
                    c1.sun_catch(x,y);//h 收货阳光
                    break;
                }
                case 106:{
                    c1.delete_plant(x,y);break;//j 铲除植物
                }
                case 27:
                    stop = 1;
                    break;//结束游戏
                default:
                    break;
            }
            if (check_shop(x, y)) {
                drawRect(x * RectW, y * RectH, RectW, RectH, LIGHTGRAY);
                drawdefence2(x * RectW, y * RectH, RectH, WHITE, LIGHTGRAY);
            } else { ;
                drawRect(x * RectW, y * RectH, RectW, RectH, LIGHTGRAY);
            }

            if (check_shop(bx, by)) {
                drawRect(bx * RectW, by * RectH, RectW, RectH, shopcolor);
                drawdefence2(bx * RectW, by * RectH, RectH, WHITE, shopcolor);
            } else { ;
                drawRect(bx * RectW, by * RectH, RectW, RectH, grasscolor);
            }
        }


        bx = x;
        by = y;
        //  break;
        if (stop == 1) {
            //  close_keyboard();
            break;
        }
        if (win == 0) {
            break;
        }
    }
    close_keyboard();
    if (win == 0) {
       result= c1.return_score();
        Game_win = 0;
        return 0;
    } else {
       result= c1.return_score();
        Game_win = 1;
        return 1;
    }


}
