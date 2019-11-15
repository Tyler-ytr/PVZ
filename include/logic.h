//
// Created by larryytr on 2019/11/13.
//
#pragma once
#ifndef PVZ_LOGIC_H
#define PVZ_LOGIC_H
#include <string>
extern int sun;//全局的阳光
extern int t;//全局的时间片
extern int score;



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


};
//extern class plant;
//extern class zombie;
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
    plant(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID);
    virtual void work(class zombie Z);
    virtual void draw();
};
class peashooter : public plant{
//Hp: 100
//Speed: 5 (5个时间片行动一次)
//name: peashooter

public:
    peashooter(int X, int Y, int Type, int ID);

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
public:

    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID);



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
