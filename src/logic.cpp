//
// Created by larryytr on 2019/11/13.
//
#include "logic.h"
//node smallmap[3][7];
//node bigmap[3][7];
//int sun=0;
//int t=0;
//int score=0;

controller::controller() {
    t = 0;
    score = 0;
    sun = 0;
}

void controller::time_passing() {
    t += 1;
}

void controller::add_score(int s) {
    score += s;
}


plant::plant(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID) {
    x = X;
    y = Y;
    hp = Hp;
    name = Name;
    type = Type;
    this->ID = ID;
    this->speed=speed;
}
void plant::work() {
    ;
}