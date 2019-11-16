//
// Created by Larryytr on 2019/11/14.
//

#ifndef PVZ_GAME_H
#define PVZ_GAME_H
#include"logic.h"
class Game{
private:
    int button;
    int result;//记录分数
    int Game_win;

public:
    Game(){
        button=0;
        result=0;
        Game_win=1;
    }
    int init();//初始化屏幕 有Start Exit 按enter键w s上下移动 enter键选择
    //可能还可以做一个选关界面
    int play();//游戏开始！1. 初始化地图  //返回的值 0 脑子没了 1 存活
    void test();




};














#endif //PVZ_GAME_H
