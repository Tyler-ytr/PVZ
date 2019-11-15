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
void controller::information_draw(){

}


plant::plant(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID) {
    x = X;
    y = Y;
    hp = Hp;
    name = Name;
    type = Type;
    this->ID = ID;
    this->speed=speed;
    //waiting for changing
    bx=x;
    by=y;//
}
void plant::work(class zombie Z) {
    printf("OKOKOKOKOKOKOK!!!");

    ;
}
void plant::draw(){
//waiting for changing;
;



}
void plant::plant_show(){
    //豌豆射手:
//    ;for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//            drawText(i*RectW+2, j*RectH+3,"豌豆射手", BLACK, plantcolor);
//            drawPixel(i*RectW+2, j*RectH+4 ,plantcolor);
//            drawPixel(i*RectW+2, j*RectH+5 ,plantcolor);
//            drawText(i*RectW+1, j*RectH+6,"HP:100", RED, plantcolor);
//        }
//    }

    drawText(2*RectW+2, 1*RectH+3,"豌豆射手", BLACK, plantcolor);
    drawPixel(2*RectW+2, 1*RectH+4 ,plantcolor);
    drawPixel(2*RectW+2, 1*RectH+5 ,plantcolor);
    drawText(2*RectW+1, 1*RectH+6,"HP:100", RED, plantcolor);
//寒冰射手
    drawText(0*RectW+2, 1*RectH+3,"寒冰射手", BLACK, coldblue);
    drawPixel(0*RectW+2, 1*RectH+4 ,coldblue);
    drawPixel(0*RectW+2, 1*RectH+5 ,coldblue);
    drawText(0*RectW+1, 1*RectH+6,"HP:100", RED,  coldblue);

//向日葵:

    drawPixel(RectW+4, RectH+2 ,ORANGE);
    drawText(RectW+3, RectH+3,"向日葵", BLACK, ORANGE);
    drawPixel(RectW+4, RectH+4 ,ORANGE);
    drawPixel(RectW+4, RectH+5 ,plantcolor);
    drawText(RectW+3, RectH+6,"HP:100", RED, plantcolor);

//樱桃炸弹：
    drawLine(3*RectW+2, RectH+3, 3, true, BLACK);
    drawPixel(3*RectW+3, RectH+4 ,plantcolor);
    drawLine(3*RectW+2, RectH+5, 3, true, RED);
    drawText(3*RectW+2, RectH+5," Boom!", BLACK, RED);
    drawLine(3*RectW+2, RectH+6, 3, true, RED);



}


zombie:: zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID){



       ;
   }

void zombie::draw(){
    //普通僵尸：
//    drawPixel(4, RectH+2 ,zombiecolor);
//    drawText(2, RectH+3,"普通僵尸", BLACK, zombiecolor);
//    drawPixel(4, RectH+4 ,RED);
//    drawPixel(4, RectH+5 ,GRAY );
//    drawText(3, RectH+6,"HP:100", RED, GRAY );
}
peashooter::peashooter(int X, int Y, int Type, int ID):plant(X,Y,100,"peashooter",5,Type,ID){
    ;

};