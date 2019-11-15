//
// Created by larryytr on 2019/11/13.
//
#pragma once
#ifndef PVZ_LOGIC_H
#define PVZ_LOGIC_H
#include <string>
#include "Map.h"
#include "linux_env.h"
extern int sun;//全局的阳光
extern int t;//全局的时间片
extern int score;
enum Plant_type{
    peashotter=0,
    sunflower=1,
};
enum Zombie_type{
    norma_zombie=0,
};




class controller{
private:
    int sun;
    int t;
    int score;
public:
    //int score;
    controller();
    void time_passing();
    void add_score(int s);
    void information_draw();


};
//extern class plant;
//extern class zombie;
class pea_bullet{
private:
    int frozen;//正常是0 冰冻为1
    int bx;// 像素位置
    int by;
    int speed;
    int attack_power;
public:
    pea_bullet(int bx,int by,int frozen,int speed,int attack_power);
    void work(class zombie&Z);


};
class plant{
private:
    int x;
    int y;
    int hp;
    std::string name;
    int speed;
    int type;
    int ID;

public:
    int bx;//像素级别的位置
    int by;
    int Ready;//0:waiting 1:ready
    int alive;//活着为1,死了为0;
    plant() {
        ;
    }
    plant(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID);
    virtual void work(class zombie &Z);
    virtual void draw();
    void hurt(int attcak_power);
    void plant_show();
};
class peashooter : public plant{
//Hp: 100
//Speed: 5 (5个时间片行动一次)
//name: peashooter

public:
    peashooter(int X, int Y, int ID);

};
class zombie{
private:
    int x;
    int y;
    int hp;
    std::string name;
    int speed;
    int type;
    int ID;
    int alive;
public:

    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID);
 void  draw();
    void hurt(int attcak_power);



};









//enum LOCAL  {First=0,Middle=1,Last=2};



//typedef struct Node{
//    int used;
//    int dirty;
//    int plant_state;//有或者没有-1表示死亡;需要delete;
//    void * plant;//指向植物的指针;
//    int x;
//    int y;//自己的坐标;
//    enum LOCAL local;
//}node;
//extern node smallmap[3][7];//暴露给大家的全局map;
//extern node bigmap[3][7];//暴露给大家的全局map;
#endif //PVZ_LOGIC_H
