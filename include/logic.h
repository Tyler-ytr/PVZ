//
// Created by larryytr on 2019/11/13.
//
#pragma once
#ifndef PVZ_LOGIC_H
#define PVZ_LOGIC_H
enum LOCAL  {First=0,Middle=1,Last=2};



typedef struct Node{
    int used;
    int dirty;
    int plant_state;//有或者没有-1表示死亡;需要delete;
    void * plant;//指向植物的指针;
    int x;
    int y;//自己的坐标;
    enum LOCAL local;
}node;
extern node smallmap[3][7];//暴露给大家的全局map;
extern node bigmap[3][7];//暴露给大家的全局map;
extern int sun;//全局的阳光
extern int t;//全局的时间片
extern int score;








#endif //PVZ_LOGIC_H
