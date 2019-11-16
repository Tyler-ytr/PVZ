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
    drawTextB(16, 4, "Plant VS Zombie", WHITE, BLACK);
    drawTextB(18, 17, "Start", WHITE, BLACK);
    drawTextB(18, 20, "Exit", WHITE, BLACK);
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
        if (Game_win == 0) {
            printf("Lose");
        }
        screenClear();

    } else {
        printf("Exit");
    }
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
//    t=0;sun=0;
//    score=0;
    controller c1;
    c1.plant_flowers_test(0, 1);
    //c1.zombie_productor(4,4,normal_zombie);
    c1.zombie_productor(6, 1, normal_zombie);
    c1.zombie_productor(7, 1, normal_zombie);
    c1.zombie_productor(5, 1, normal_zombie);
    c1.zombie_productor(9, 2, iron_zombie);
    c1.zombie_productor(8, 2, roadblock_zombie);
    c1.plant_flowers_test(0, 2);
    c1.map_init();
    drawRect(0 * RectW, 0 * RectH, RectW, RectH, LIGHTGRAY);

    plant::plant_show();

    init_keyboard();
    // kbhit();
    while (1) {

        my_sleep(50);
        c1.time_passing();
        c1.both_move();
        c1.both_draw();
        c1.both_work();
        drawdefence((RectnumW) * RectW, RectH, RectH * 5, WHITE, grasscolor);
        c1.information_draw();
        win = c1.check_win();

//        temp1.timepassing();
//        temp1.draw();
//        temp1.move();
//
//        temp2.timepassing();
//        temp2.move();
//        temp2.draw();
//        temp2.work(temp1);
        //  temp3.draw();
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
        Game_win = 0;
        return 0;
    } else {
        Game_win = 1;
        return 1;
    }


}
