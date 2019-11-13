//
// Created by larryytr on 2019/11/13.
//

#ifndef PVZ_MAP_H
#define PVZ_MAP_H
#include "logic.h"
#define RectH 6
#define RectW 6
#define RectnumW 7
#define RectnumH 6
#define MAPH RectH*RectnumH-1//最下面的那个点
#define MAPW RectW*RectnumW-1//最右边的那个点
//每一个格子可以绘制的范围是 (x*6+1,y*6+1)---(x*6+4,y*6+4)
//花园的范围是 从 (1,1)-

extern node map[3][7];
void test();
#endif //PVZ_MAP_H
