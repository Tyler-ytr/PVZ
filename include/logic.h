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
    Sunflower=1,
    coldshotter=2,
    Cherry_bomb=3,
    Nut_wall=4

};
enum Zombie_type{
    normal_zombie=0,
    iron_zombie=2,
    roadblock_zombie=1,
    reading_zombie=3

};



//extern class plant;
//extern class zombie;
class pea_bullet{
protected:
    int frozen;//正常是0 冰冻为1

    int speed;
    int attack_power;

    int t;


public:
    int alive;//打了没
    int bx;// 像素位置
    int by;
    pea_bullet(int bx,int by,int frozen,int speed,int attack_power);

    virtual void  move();
    virtual void work(class zombie &Z);
    void timepassing(){
        t+=1;
    }
    virtual void draw();
    void death();


};
class cold_bullet:public pea_bullet{
public:
    cold_bullet(int bx,int by,int frozen,int speed,int attack_power);
    virtual void move();
    virtual void work(class zombie&Z);
    virtual void draw();
};
class plant{
protected:
//    int x;
//    int y;
    int hp;
    std::string name;
    int speed;
    int t;
    int ID;


public:
    int x;
    int y;
    int type;
    int bx;//像素级别的位置
    int by;
    int Ready;//0:waiting 1:ready
    int alive;//活着为1,死了为0;
    int cost;
    int sun_catch;
    plant() {
        ;
    }
    plant(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID,int cost);
    virtual int work(class zombie &Z);
    virtual void draw();
    void hurt(int attcak_power);
    static void plant_show();
    void timepassing(){
        t+=1;
    };
    virtual void death();
    bool check_location(int x,int y);



};
class peashooter : public plant{
//Hp: 100
//Speed: 5 (5个时间片行动一次)
//name: peashooter

public:
    peashooter(int X, int Y, int ID);
    virtual void draw();
    virtual int work(class zombie&Z);
    virtual void death();

};

class sunflower:public plant{
public:

    sunflower(int X,int Y,int ID);
    void draw() override;
    int work(class zombie&Z) override;
    void death() override;

};
class coldshooter:public peashooter{
public:
    coldshooter(int X,int Y,int ID);
    void draw() override;
    int work(class zombie&Z) override;
    void death() override;
};
class cherrybomb:public plant{
    int bomb;
    int death_time;
public:
    cherrybomb(int X,int Y,int ID);
    virtual void draw();
    virtual int work(class zombie&Z);
    void death();


};
class nutwall:public plant{
public:
    nutwall(int X,int Y,int ID);
    virtual void draw();
    virtual  int work(class zombie&Z);
    void death();
};


class zombie{
protected:

    int hp;
    std::string name;
    int speed;
    int type;
    int ID;
    int attack_speed;

    int t;
    int frozen;//0是正常的 1是冰冻的;
    int attack_power;
public:
    int x;
    int y;
    int stop;
    int score;
    int alive;
    int bx;
    int by;
    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID,int attack_power,int attack_speed,int score);
    virtual void  draw();
    void death();
    void hurt(int attack_power);

    virtual void move();
    virtual int work(class plant& P);
    void freeze();
    void timepassing(){
        t+=1;
    }


};
class Normal_zombie:public zombie{
public:
    Normal_zombie(int X,int Y,int ID);
    void move(){
        zombie::move();
    }


};
class Iron_zombie:public zombie{
private:
    int iron;
public:
    Iron_zombie(int X,int Y,int ID);
    void move(){
        zombie::move();
    }
    void draw() override;
    int work(class plant& P) override;

};
class Roadblock_zombie:public zombie{
private:
    int roadblock;
public:
    Roadblock_zombie(int X,int Y,int ID);
    void move(){
        zombie::move();
    }
    void draw() override;
    int work(class plant& P) override ;

};
class Read_zombie:public zombie{
private:
    int reading;
public:
    Read_zombie(int X,int Y,int ID);
    void move(){
        zombie::move();
    }
    void draw()override;
    int work(class plant&P)override ;

};



class controller{
private:
    int sun;
    int t;
    int score;
    int plant_catch;//来自plant_list -1 为空
    int ID;
    int natual_sun_speed;
    int win_lose;//1 正常 0 失败 2 胜利


public:
    //int score;
    std::vector<class zombie*> zombie_group;
    std::vector<class plant*> plant_group;
    std::vector<class pea_bullet*>bullet_group;
    controller();
    static void map_init();
    void time_passing();
    void add_score(int s);
    void information_draw();
    void buy_plant(int x,int y);//购买处于逻辑位x,y的植物;
    void plant_flowers(int x,int y);//在逻辑位x,y上面种植植物(如果阳光够 否则就不种)(无论如何 都会让plant_catch清除);
    void zombie_productor(int x,int y,int type);//在逻辑位x,y上面"生产"僵尸;
    void plant_group_work();
    void bullet_group_work();
    void zombie_group_work();
    void both_draw();
    void both_work();
    void both_move();
    void plant_flowers_test(int x, int y);
    int check_win();
    void sun_catch(int x,int y);
    void delete_plant(int x,int y);
    void zombie_fram();
    int return_score(){
        return score;
    };


    //辅助函数:




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
