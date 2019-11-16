//
// Created by larryytr on 2019/11/13.
//
#pragma once
#ifndef PVZ_LOGIC_H
#define PVZ_LOGIC_H
#include <string>
#include <vector>
#include "Map.h"
#include "linux_env.h"
extern int sun;//全局的阳光
extern int t;//全局的时间片
extern int score;
class plant;
enum Plant_type{
    peashotter=0,
    sunflower=1,
    coldshotter=2,
    cherry_bomb=3

};
enum Zombie_type{
    norma_zombie=0,
};





//extern class plant;
//extern class zombie;
class pea_bullet{
protected:
    int frozen;//正常是0 冰冻为1

    int speed;
    int attack_power;
    int alive;//打了没
    int t;



public:
    int bx;// 像素位置
    int by;
    pea_bullet(int bx,int by,int frozen,int speed,int attack_power);

    void move();
    void work(class zombie &Z);
    void timepassing(){
        t+=1;
    }
    virtual void draw();
    void death();


};
class plant{
protected:
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
    virtual int work(class zombie &Z);
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
    virtual void draw();

};
class zombie{
protected:
    int x;
    int y;
    int hp;
    std::string name;
    int speed;
    int type;
    int ID;
    int alive;
    int t;
    int frozen;//0是正常的 1是冰冻的;
public:
    int bx;
    int by;
    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID);
    void  draw();
    void death();
    void hurt(int attack_power);
    void move();
    virtual int work();
    void timepassing(){
        t+=1;
    }


};
class Normal_zombie:public zombie{

};



class controller{
private:
    int sun;
    int t;
    int score;
    int plant_catch;//来自plant_list -1 为空
    int ID;

public:
    //int score;
    std::vector<class zombie*> zombie_group;
    std::vector<class plant*> plant_group;
    controller();
    void time_passing();
    void add_score(int s);
    void information_draw();
    void buy_plant(int x,int y);//购买处于逻辑位x,y的植物;
    void plant_flowers(int x,int y);//在逻辑位x,y上面种植植物(如果阳光够 否则就不种)(无论如何 都会让plant_catch清除);
    void zombie_productor(int x,int y,int type);//在逻辑位x,y上面"生产"僵尸;



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
