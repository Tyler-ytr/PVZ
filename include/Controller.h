#pragma once
#ifndef _CONTROLLER_H
#define _CONTROLLER_H
//#include "Object.h"
#include "common.h"


node smallmap[3][7];
node bigmap[5][7];
class Controller{
private:
    int score;//分数;
public:
    int sun;
    int nature_get_sun;
    int max_length;//长度也就是列数
    int max_width;//宽度 也就是行数;

    node (*map)[7];
    void map_clear(){
        for(int i=0;i<max_width;i++){
            for(int j=0;j<max_length;j++){
                map[i][j].x=i;
                map[i][j].y=j;
                map[i][j].plant=nullptr;
                map[i][j].dirty=1;
                map[i][j].plant_state=0;
                map[i][j].used=1;
            }
        }
    }
    Controller(){
        max_length=7;
        max_width=5;
        map=bigmap;
//        map=new node*[max_width];
//        for(int i=0;i<max_width;i++)
//        {
//            map[i]=new node[max_length];
//        }
        map_clear();
        sun=0;
        score=0;
        nature_get_sun=25;


    }
//    Controller(int max_Length,int max_Width){
//        this->max_length=max_Length;
//        this->max_width=max_Width;
//        map=new node*[max_width];
//        for(int i=0;i<max_width;i++)
//        {
//            map[i]=new node[max_length];
//        }
//        for(int i=0;i<max_width;i++){
//            for(int j=0;j<max_length;j++){
//                map[i][j].x=i;
//                map[i][j].y=j;
//                map[i][j].plant=nullptr;
//                map[i][j].dirty=1;
//                map[i][j].plant_state=0;
//                map[i][j].used=1;
//            }
//        }
//        sun=0;
//        score=0;
//        nature_get_sun=25;
//
//    }
    void get_sun(){
        sun+=nature_get_sun;
    }








};

#endif
