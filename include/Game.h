//
// Created by Larryytr on 2019/11/14.
//

#ifndef PVZ_GAME_H
#define PVZ_GAME_H
class Game{
private:
    int button;

public:
    Game(){
        button=0;
    }
    int init();//初始化屏幕 有Start Exit 按enter键w s上下移动 enter键选择
    //可能还可以做一个选关界面
    void play();//游戏开始！1
    void test();




};














#endif //PVZ_GAME_H
