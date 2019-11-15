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

void controller::information_draw() {
    ;
}


plant::plant(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID) {
    x = X;
    y = Y;
    hp = Hp;
    name = Name;
    type = Type;
    this->ID = ID;
    this->speed = speed;
    Ready = 0;
    //waiting for changing
    bx = x;
    by = y;//

}

int plant::work(class zombie &Z) {
    printf("OKOKOKOKOKOKOK!!!");

    ;
}

void plant::draw() {
//waiting for changing;
    ;


}

void plant::plant_show() {
    //豌豆射手:
//    ;for(int i=0;i<5;i++){
//        for(int j=0;j<5;j++){
//            drawText(i*RectW+2, j*RectH+3,"豌豆射手", BLACK, plantcolor);
//            drawPixel(i*RectW+2, j*RectH+4 ,plantcolor);
//            drawPixel(i*RectW+2, j*RectH+5 ,plantcolor);
//            drawText(i*RectW+1, j*RectH+6,"HP:100", RED, plantcolor);
//        }
//    }

    drawText(2 * RectW + 2, 1 * RectH + 3, "豌豆射手", BLACK, plantcolor);
    drawPixel(2 * RectW + 2, 1 * RectH + 4, plantcolor);
    drawPixel(2 * RectW + 2, 1 * RectH + 5, plantcolor);
    drawText(2 * RectW + 1, 1 * RectH + 6, "HP:100", RED, plantcolor);
    drawText_num(2 * RectW + 1, 1 * RectH + 6, "HP:",100, RED, plantcolor);
//寒冰射手
    drawText(0 * RectW + 2, 1 * RectH + 3, "寒冰射手", BLACK, coldblue);
    drawPixel(0 * RectW + 2, 1 * RectH + 4, coldblue);
    drawPixel(0 * RectW + 2, 1 * RectH + 5, coldblue);
    drawText(0 * RectW + 1, 1 * RectH + 6, "HP:100", RED, coldblue);


//向日葵:

    drawPixel(RectW + 4, RectH + 2, ORANGE);
    drawText(RectW + 3, RectH + 3, "向日葵", BLACK, ORANGE);
    drawPixel(RectW + 4, RectH + 4, ORANGE);
    drawPixel(RectW + 4, RectH + 5, plantcolor);
    drawText(RectW + 3, RectH + 6, "HP:100", RED, plantcolor);

//樱桃炸弹：
    drawLine(3 * RectW + 2, RectH + 3, 3, true, BLACK);
    drawPixel(3 * RectW + 3, RectH + 4, plantcolor);
    drawLine(3 * RectW + 2, RectH + 5, 3, true, RED);
    drawText(3 * RectW + 2, RectH + 5, " Boom!", BLACK, RED);
    drawLine(3 * RectW + 2, RectH + 6, 3, true, RED);


}

void plant::hurt(int attcak_power) {
    this->hp -= attcak_power;
    if (hp <= 0) {
        alive = 0;
    }
}

////
////
////
////下面是peashooter
peashooter::peashooter(int X, int Y, int ID) : plant(X, Y, 100, "peashooter", 5, peashotter, ID) {
    ;

};


////
////
////
////下面是zombie
//zombie::    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID){
//    ;
//}
zombie::zombie(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID) {
    x = X;
    y = Y;
    hp = Hp;
    name = Name;
    type = Type;
    this->ID = ID;
    alive = 1;
    bx = x * RectW + 2;
    by = y * RectH + 3;
    t=0;
}

void zombie::draw() {
    //普通僵尸：


//    drawPixel(x*RectW+4, y*RectH+2 ,zombiecolor);
//    drawText(x*RectW+2, y*RectH+3,"普通僵尸", BLACK, zombiecolor);
//    drawPixel(x*RectW+4, y*RectH+4 ,RED);
//    drawPixel(x*RectW+4, y*RectH+5 ,GRAY );
//    drawText(x*RectW+3, y*RectH+6,"HP:100", RED, GRAY );
//僵尸模板如上：

    if(bx+4<=MAPW){
        int cx=bx+1;
        drawPixel(cx + 2, by - 1, grasscolor);
        drawLine(cx,by,4,true,grasscolor);
    //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
        drawPixel(cx + 2, by + 1, grasscolor);
        drawPixel(cx + 2, by + 2, grasscolor);
        drawLine(cx+1,by+3,4,true,grasscolor);
   //     drawText(cx + 1, by + 3, "HP:100", RED, GRAY);
    }
//
    drawPixel(bx + 2, by - 1, zombiecolor);
    drawText(bx, by, "普通僵尸", BLACK, zombiecolor);
    drawPixel(bx + 2, by + 1, RED);
    drawPixel(bx + 2, by + 2, GRAY);
    drawText(bx + 1, by + 3, "HP:100", RED, GRAY);


}

void zombie::hurt(int attcak_power) {
    this->hp -= attcak_power;
    if (hp <= 0) {
        alive = 0;
    }
}

int zombie::work() {
    ;
}

void zombie::move() {
    if(t%speed==0){    bx -= 1;
        x = bx / RectW;;}

    ;
}
void zombie::check_alive_draw() {
    if(alive==0){
        int cx=bx;
        drawPixel(cx + 2, by - 1, grasscolor);
        drawLine(cx,by,4,true,grasscolor);
        //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
        drawPixel(cx + 2, by + 1, grasscolor);
        drawPixel(cx + 2, by + 2, grasscolor);
        drawLine(cx+1,by+3,4,true,grasscolor);
    }
}


////
////
////
////下面是pea-bullet
pea_bullet::pea_bullet(int bx, int by, int frozen, int speed, int attack_power) {
    this->bx = bx;
    this->by = by;
    this->frozen = frozen;
    this->speed = speed;
    this->attack_power = attack_power;
    this->alive = 1;
    this->t=0;
}

void pea_bullet::work(class zombie &Z) {
    ;
}
void pea_bullet::move() {
    if(t%speed==0){
    if(bx<=MAPW)
    {
        bx+=1;
    }else{
        alive=0;
    }}

}
void pea_bullet:: draw(){
    drawPixel(bx-1, by, grasscolor);
    drawPixel(bx, by, plantcolor);
}
