#pragma once
#ifndef _COMMON_H
#define _COMMON_H
#include "Object.h"
enum LOCAL  {First=0,Middle=1,Last=2};
typedef struct Node{
    int used;
    int dirty;
    int plant_state;//有或者没有-1表示死亡;需要delete;
    class Object * plant;//指向植物的指针;
    int x;
    int y;//自己的坐标;
    enum LOCAL local;
}node;


#endif
