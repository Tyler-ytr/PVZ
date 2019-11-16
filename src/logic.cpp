//
// Created by larryytr on 2019/11/13.
//
#include "logic.h"
//node smallmap[3][7];
//node bigmap[3][7];
//int sun=0;
//int t=0;
//int score=0;

//void check_exist(){
//    drawPixel(15,15,RED);
//}

controller::controller() {
    t = 0;
    score = 0;
    sun = 0;
    plant_catch = -1;
    ID = 0;
    natual_sun_speed = 30;
    win_lose = 1;
}

void cannot_buy() {
    drawLine(RectnumW * RectW, 3, RectW, true, WHITE);
    drawText(RectnumW * RectW + 1, 3, "Not enough sun", BLACK, WHITE);;
}

void can_buy() {
    drawLine(RectnumW * RectW, 3, RectW, true, WHITE);
    drawText(RectnumW * RectW + 1, 3, "Buy it!", BLACK, WHITE);;
}

void controller::buy_plant(int x, int y) {
    if (y == 0) {
        switch (x) {
            case 0:
                if (sun >= 175) {
                    plant_catch = coldshotter;
                    sun -= 175;
                    can_buy();
                } else {
                    cannot_buy();
                }
                break;
            case 1:
                if (sun >= 50) {
                    plant_catch = Sunflower;
                    sun -= 50;
                    can_buy();
                } else {
                    cannot_buy();
                }
                break;
            case 2:
                if (sun >= 100) {
                    plant_catch = peashotter;
                    sun -= 100;
                    can_buy();
                } else {
                    cannot_buy();
                }
                break;
            case 3:
                plant_catch = cherry_bomb;
                break;
            default:
                break;
        }
    }
}

void controller::plant_flowers(int x, int y) {

    class plant *temp_plant;
    if (plant_catch != -1) {
        switch (plant_catch) {
            case peashotter:
                temp_plant = new peashooter(x, y, ID);
                ID += 1;
                plant_group.push_back(temp_plant);
                break;
            case Sunflower:
                temp_plant = new sunflower(x, y, ID);
                ID += 1;
                plant_group.push_back(temp_plant);
                break;
            case coldshotter:
                temp_plant = new coldshooter(x, y, ID);
                ID += 1;
                plant_group.push_back(temp_plant);
                break;
            default:
                break;
        }


    }
    plant_catch = -1;

}

void controller::plant_flowers_test(int x, int y) {
    class plant *temp_plant;
    temp_plant = new peashooter(x, y, ID);
    ID += 1;
    plant_group.push_back(temp_plant);

}

void controller::zombie_productor(int x, int y, int type) {
    class zombie *temp_zombie;
    switch (type) {
        case normal_zombie:
            temp_zombie = new Normal_zombie(x, y, ID);
            ID += 1;
            zombie_group.push_back(temp_zombie);
            break;
        case iron_zombie:
            temp_zombie = new Iron_zombie(x, y, ID);
            ID += 1;
            zombie_group.push_back(temp_zombie);
            break;
        case roadblock_zombie:
            temp_zombie = new Roadblock_zombie(x, y, ID);
            ID += 1;
            zombie_group.push_back(temp_zombie);
            break;
            break;
    }
}

void controller::plant_group_work() {
    //https://blog.csdn.net/wangshubo1989/article/details/50121059
    vector<class plant *>::iterator itor2;
    for (vector<class plant *>::iterator temp_plant = plant_group.begin(); temp_plant != plant_group.end();) {
        if ((*temp_plant)->alive == 0) {
            itor2 = temp_plant;
            (*temp_plant)->death();
            plant_group.erase(itor2);
        } else {
            int flag = 0;
            for (vector<class zombie *>::iterator temp_zombie = zombie_group.begin();
                 temp_zombie != zombie_group.end(); temp_zombie++) {
                int result = (*temp_plant)->work(*(*temp_zombie));
                switch ((*temp_plant)->type) {
                    case peashotter: { ;
                        break;//对result进行处理;
                    }
                    case Sunflower: {
                        break;
                    }
                    case coldshotter: {
                        break;
                    }
                }
                flag = 1;

            }
            if (flag == 0) {
                zombie fake_zombie(-1, -1, -1, "fake", 10, -1, -1, -1, 20, -1);
                (*temp_plant)->work(fake_zombie);
            }
            //  check_exist();
            switch ((*temp_plant)->type) {//对常态work进行处理
                case peashotter: {
                    // check_exist();
                    if ((*temp_plant)->Ready == 1) {
                        int bx = (*temp_plant)->bx;
                        int by = (*temp_plant)->by;
                        class pea_bullet *temp_bullet;
                        temp_bullet = new pea_bullet(bx, by, 0, 3, 20);
                        bullet_group.push_back(temp_bullet);
                        (*temp_plant)->Ready = 0;
                        //     check_exist();
                    };
                    break;
                }
                case Sunflower: {
                    if ((*temp_plant)->Ready == 1) {
                        (*temp_plant)->sun_catch += 25;
                    }
                    break;
                }
                case coldshotter: {
                    if ((*temp_plant)->Ready == 1) {
                        int bx = (*temp_plant)->bx;
                        int by = (*temp_plant)->by;
                        ///waiting for changing!!!
                        class pea_bullet *temp_bullet;
                        temp_bullet = new cold_bullet(bx, by, 1, 3, 20);
                        bullet_group.push_back(temp_bullet);
                        (*temp_plant)->Ready = 0;
                    }
                    break;
                }

            }


            temp_plant++;
        }


    }
}

void controller::bullet_group_work() {
    vector<class pea_bullet *>::iterator itor2;
    for (vector<class pea_bullet *>::iterator temp_bullet = bullet_group.begin();
         temp_bullet != bullet_group.end();) {
        if ((*temp_bullet)->alive == 0) {
            itor2 = temp_bullet;
            (*temp_bullet)->death();
            bullet_group.erase(itor2);

        } else {
            for (vector<class zombie *>::iterator temp_zombie = zombie_group.begin();
                 temp_zombie != zombie_group.end(); temp_zombie++) {
                (*temp_bullet)->work(*(*temp_zombie));
            }
            //还可以加一个swicth做额外的鉴别;

            temp_bullet++;
        }

    }
}

void controller::zombie_group_work() {
    vector<class zombie *>::iterator itor2;
    for (vector<class zombie *>::iterator temp_zombie = zombie_group.begin(); temp_zombie != zombie_group.end();) {
        if ((*temp_zombie)->alive == 0) {
            (*temp_zombie)->death();
            itor2 = temp_zombie;
            //add_score((*temp_zombie)->score);
            score += (*temp_zombie)->score;
            // (*temp_zombie)->death();
            zombie_group.erase(itor2);

        } else {
            int flag = 0;
            for (vector<class plant *>::iterator temp_plant = plant_group.begin();
                 temp_plant != plant_group.end(); temp_plant++) {
                int result = (*temp_zombie)->work(*(*(temp_plant)));
                if (result == 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                (*temp_zombie)->stop = 1;
            } else {
                (*temp_zombie)->stop = 0;
            }


            temp_zombie++;
        }
    };
}

void controller::time_passing() {
    t += 1;
    for (auto temp_bullet = bullet_group.begin(); temp_bullet != bullet_group.end(); temp_bullet++) {
        (*temp_bullet)->timepassing();
    }
    for (auto temp_plant = plant_group.begin(); temp_plant != plant_group.end(); temp_plant++) {
        (*temp_plant)->timepassing();
    }
    for (auto temp_zombie = zombie_group.begin(); temp_zombie != zombie_group.end(); temp_zombie++) {
        (*temp_zombie)->timepassing();
    }
    if (t % natual_sun_speed == 0) {
        sun += 25;
    }
}

void controller::add_score(int s) {
    score += s;
}

void controller::information_draw() {
    //drawWholeRect(RectnumW*RectW,0,RectH,RectW,WHITE);
    drawLine(RectnumW * RectW, 1, RectW, true, WHITE);
    drawLine(RectnumW * RectW, 2, RectW, true, WHITE);
    drawText_num(RectnumW * RectW + 1, 1, "sun:", sun, BLACK, WHITE);
    drawText_num(RectnumW * RectW + 1, 2, "score:", score, BLACK, WHITE);
    //   drawText(RectnumW*RectW+1,3,"Not enough sun",BLACK,WHITE);
    drawText(RectnumW * RectW + 1, 4, "You are dead!", BLACK, WHITE);;
}


void controller::both_draw() {
    for (auto temp_bullet = bullet_group.begin(); temp_bullet != bullet_group.end(); temp_bullet++) {
        //     check_exist();
        (*temp_bullet)->draw();
    }
    for (auto temp_plant = plant_group.begin(); temp_plant != plant_group.end(); temp_plant++) {
        (*temp_plant)->draw();
    }
    for (auto temp_zombie = zombie_group.begin(); temp_zombie != zombie_group.end(); temp_zombie++) {
        (*temp_zombie)->draw();
    }

    ;
}

void controller::both_work() {
    zombie_group_work();
    bullet_group_work();
    plant_group_work();
    //   zombie_group_work();
}

void controller::both_move() {
    for (auto temp_bullet = bullet_group.begin(); temp_bullet != bullet_group.end(); temp_bullet++) {
        //  check_exist();
        (*temp_bullet)->move();

    }
    for (auto temp_zombie = zombie_group.begin(); temp_zombie != zombie_group.end(); temp_zombie++) {

        (*temp_zombie)->move();
    }
}

void controller::map_init() {
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < 1; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, shopcolor);
            // drawRect(i*RectW,j*RectH,RectW,RectH,LIGHTGRAY);
            // clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
        }
    }
    for (int i = 0; i < RectnumW + 1; i++) {
        for (int j = 1; j < RectnumH; j++) {
            drawWholeRect(i * RectW, j * RectH, RectW, RectH, grasscolor);
            //     drawRect(i*RectW,j*RectH,RectW,RectH,LIGHTGRAY);
            // clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
        }
    }
    for (int i = 0; i < RectnumW; i++) {
        for (int j = 0; j < 1; j++) {
            drawdefence2(i * RectW, j * RectH, RectH, WHITE, shopcolor);
        }
    }
    drawWholeRect(RectnumW * RectW, 0, RectH, RectW, WHITE);
//    for(int i=0;i<RectnumW;i++){
//        drawWholeRect(i * RectW, RectnumH* RectH, RectW, RectH, WHITE);
//    }
    //  drawdefence((RectnumW)*RectW,RectH,RectH*5,WHITE,grasscolor);
}

int controller::check_win() {
    for (auto temp_zombie = zombie_group.begin(); temp_zombie != zombie_group.end(); temp_zombie++) {

        if ((*temp_zombie)->bx <= 0) {
            win_lose = 0;
            return 0;
        }
    }
    return 1;

}

void controller::sun_catch(int x, int y) {
    plant *temp_plant;
    for (auto iter = plant_group.begin(); iter != plant_group.end(); iter++) {
        if ((*iter)->check_location(x, y)) {
            temp_plant = *iter;
            sun += temp_plant->sun_catch;
            break;
        }
    }
}

void controller::delete_plant(int x, int y) {
    vector<class plant *>::iterator itor2;
    for (vector<class plant *>::iterator temp_plant = plant_group.begin(); temp_plant != plant_group.end();) {
        if ((*temp_plant)->check_location(x, y)) {
            (*temp_plant)->alive = 0;
            break;
        }


    }
}
////
////
////
////



plant::plant(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID, int cost) {
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
    alive = 1;
    this->t = 0;
    this->cost = cost;
    sun_catch = 0;

}


int plant::work(class zombie &Z) {
    // printf("OKOKOKOKOKOKOK!!!");

    ;
}

void plant::draw() {
//waiting for changing;
    ;

}

void plant::death() {
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
    drawText(2 * RectW + 1, 0 * RectH + 1, "豌豆射手:100", BLACK, shopcolor);
    drawText(2 * RectW + 2, 0 * RectH + 3, "豌豆射手", BLACK, plantcolor);
    drawPixel(2 * RectW + 2, 0 * RectH + 4, plantcolor);
    drawPixel(2 * RectW + 2, 0 * RectH + 5, plantcolor);
    //drawText(2 * RectW + 1, 1 * RectH + 6, "HP:100", RED, plantcolor);
    drawText_num(2 * RectW + 1, 0 * RectH + 6, "HP:", 100, RED, plantcolor);
//寒冰射手
    drawText(0 * RectW + 1, 0 * RectH + 1, "寒冰射手:175", BLACK, shopcolor);
    drawText(0 * RectW + 2, 0 * RectH + 3, "寒冰射手", BLACK, coldblue);
    drawPixel(0 * RectW + 2, 0 * RectH + 4, coldblue);
    drawPixel(0 * RectW + 2, 0 * RectH + 5, coldblue);
    drawText(0 * RectW + 1, 0 * RectH + 6, "HP:100", RED, coldblue);


//向日葵:

    drawText(RectW + 1, 0 * RectH + 1, "向日葵 : 50", BLACK, shopcolor);
    drawPixel(RectW + 4, 0 * RectH + 2, ORANGE);
    drawText(RectW + 3, 0 * RectH + 3, "向日葵", BLACK, ORANGE);
    drawPixel(RectW + 4, 0 * RectH + 4, ORANGE);
    drawPixel(RectW + 4, 0 * RectH + 5, plantcolor);
    drawText(RectW + 3, 0 * RectH + 6, "HP:100", RED, plantcolor);

//樱桃炸弹：
    drawText(3 * RectW + 1, 0 * RectH + 1, "樱桃炸弹:150", BLACK, shopcolor);
    drawLine(3 * RectW + 2, 0 * RectH + 3, 3, true, BLACK);
    drawPixel(3 * RectW + 3, 0 * RectH + 4, plantcolor);
    drawLine(3 * RectW + 2, 0 * RectH + 5, 3, true, RED);
    drawText(3 * RectW + 2, 0 * RectH + 5, " Boom!", BLACK, RED);
    drawLine(3 * RectW + 2, 0 * RectH + 6, 3, true, RED);


}

void plant::hurt(int attcak_power) {
    this->hp -= attcak_power;
    if (hp <= 0) {
        alive = 0;
    }
}

bool plant::check_location(int x, int y) {
    if (this->x == x && this->y == y) {
        return true;
    } else {
        return false;
    }
}

//void plant::time_passing() {
//    t += 1;
//}

////
////
////
////下面是peashooter
peashooter::peashooter(int X, int Y, int ID) : plant(X, Y, 100, "peashooter", 23, peashotter, ID, 100) {
    bx = plant::x * RectW + 2 + 4;
    by = plant::y * RectH + 3;

};

void peashooter::draw() {
    if (alive == 1) {
        drawText(bx - 4, by, "豌豆射手", BLACK, plantcolor);
        drawPixel(bx - 4, by + 1, plantcolor);
        drawPixel(bx - 4, by + 2, plantcolor);
        // drawText(bx-5, by+3, "HP:100", RED, plantcolor);
        drawLine(bx - 5, by + 3, 4, true, grasscolor);
        drawText_num(bx - 5, by + 3, "HP:", hp, RED, plantcolor);
    } else {
        death();
    }
}

int peashooter::work(class zombie &Z) {
//    check_exist();
//    if(this->t!=0){
//        check_exist();
//    }
    if (t % speed == 0) {
        Ready = 1;
        //  check_exist();
        return 1;
    } else {
        return 0;
    }
}

void peashooter::death() {
    drawLine(bx - 4, by, 4, true, grasscolor);
    //  drawText(bx - 4, by, "豌豆射手", BLACK, plantcolor);
    drawPixel(bx - 4, by + 1, grasscolor);
    drawPixel(bx - 4, by + 2, grasscolor);
    // drawText(bx-5, by+3, "HP:100", RED, plantcolor);
    // drawText_num(bx - 5, by + 3, "HP:", 100, RED, plantcolor);
    drawLine(bx - 5, by + 3, 4, true, grasscolor);
}

////
////
////
//// 下面是 coldshooter
coldshooter::coldshooter(int X, int Y, int ID) : peashooter(X, Y, ID) {
//    plant(X, Y, 100, "peashooter", 23, peashotter, ID,100)
    this->name = "coldshooter";
    this->speed = 25;
    this->type = coldshotter;
    this->cost = 175;;
}

void coldshooter::draw() {
//    ;    drawText(0 * RectW + 2, 0 * RectH + 3, "寒冰射手", BLACK, coldblue);
//    drawPixel(0 * RectW + 2, 0 * RectH + 4, coldblue);
//    drawPixel(0 * RectW + 2, 0 * RectH + 5, coldblue);
//    drawText(0 * RectW + 1, 0 * RectH + 6, "HP:100", RED, coldblue);
    if (alive == 1) {
        drawText(bx - 4, by, "豌豆射手", BLACK, coldblue);
        drawPixel(bx - 4, by + 1, coldblue);
        drawPixel(bx - 4, by + 2, coldblue);
        // drawText(bx-5, by+3, "HP:100", RED, plantcolor);
        drawLine(bx - 5, by + 3, 4, true, grasscolor);
        drawText_num(bx - 5, by + 3, "HP:", hp, RED, coldblue);
    } else {
        death();
    }
}

void coldshooter::death() {
    peashooter::death();
}

int coldshooter::work(struct zombie &Z) {
    peashooter::work(Z);
}



////
////
////
//// 下面是 sunflower

sunflower::sunflower(int X, int Y, int ID) : plant(X, Y, 100, "Sun flower", 30, Sunflower, ID, 50) {
    bx = X * RectW + 6;
    by = Y * RectH + 3;//waiting for changing
    plant::sun_catch = 0;
}

void sunflower::draw() {
    if (alive == 1) {

        drawPixel(bx - 2, by - 1, ORANGE);
        drawText(bx - 3, by, "向日葵", BLACK, ORANGE);
        drawPixel(bx - 2, by + 1, ORANGE);
        drawPixel(bx - 2, by + 2, plantcolor);
        drawLine(bx - 3, by + 3, 4, true, grasscolor);
        drawText_num(bx - 3, by + 3, "HP:", hp, RED, plantcolor);

    } else {
        death();
    }

}

int sunflower::work(class zombie &Z) {
    if (t % speed == 0) {
        Ready = 1;
        //  check_exist();
        return 1;
    } else {
        return 0;
    };
}

void sunflower::death() {
    drawPixel(bx - 2, by - 1, grasscolor);
    drawLine(bx - 3, by, 3, true, grasscolor);
    //drawText(bx-3, by, "向日葵", BLACK, ORANGE);
    drawPixel(bx - 2, by + 1, grasscolor);
    drawPixel(bx - 2, by + 2, grasscolor);
    //drawText_num(bx-3, by+3, "HP:",hp, RED, plantcolor);
    drawLine(bx - 3, by + 3, 4, true, grasscolor);;;
}


////
////
////
////下面是zombie
//zombie::    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID){
//    ;
//}
zombie::zombie(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID, int attack_power, int attack_speed,
               int score) {
    x = X;
    y = Y;
    hp = Hp;
    name = Name;
    type = Type;
    this->ID = ID;
    alive = 1;
    bx = x * RectW + 2;
    by = y * RectH + 3;
    t = 1;
    frozen = 0;
    stop = 0;
    this->speed = speed;
    this->attack_speed = attack_speed;
    this->attack_power = attack_power;
    this->score = score;

}

void zombie::draw() {
    //普通僵尸：


//    drawPixel(x*RectW+4, y*RectH+2 ,zombiecolor);
//    drawText(x*RectW+2, y*RectH+3,"普通僵尸", BLACK, zombiecolor);
//    drawPixel(x*RectW+4, y*RectH+4 ,RED);
//    drawPixel(x*RectW+4, y*RectH+5 ,GRAY );
//    drawText(x*RectW+3, y*RectH+6,"HP:100", RED, GRAY );
//僵尸模板如上：
    if (alive == 1) {
        if (bx + 4 <= MAPW + RectW) {
            int cx = bx + 1;
            drawPixel(cx + 2, by - 1, grasscolor);
            drawLine(cx, by, 4, true, grasscolor);
            //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
            drawPixel(cx + 2, by + 1, grasscolor);
            drawPixel(cx + 2, by + 2, grasscolor);
            drawLine(cx + 1, by + 3, 4, true, grasscolor);
            //     drawText(cx + 1, by + 3, "HP:100", RED, GRAY);
        }
//
        drawPixel(bx + 2, by - 1, zombiecolor);
        drawText(bx, by, "普通僵尸", BLACK, zombiecolor);
        drawPixel(bx + 2, by + 1, RED);
        drawPixel(bx + 2, by + 2, GRAY);
        // drawText(bx + 1, by + 3, "HP:100", RED, GRAY);
        drawText_num(bx + 1, by + 3, "HP:", hp, RED, GRAY);
    } else {
        death();
    }

}

void zombie::hurt(int attcak_power) {
    this->hp -= attcak_power;
    if (hp <= 0) {
        alive = 0;
    }
}

int check_in_attack(int bx, int by, class plant P) {
    if (by <= P.by + 1 && by >= P.by - 3) {
        if (bx <= P.bx + 1 && bx >= P.bx - 5) {
            return 1;
        }
    }
    return 0;
}

int zombie::work(class plant &P) {
    if (check_in_attack(bx, by, P) == 1) {
        if (t % attack_speed == 0) {
            P.hurt(this->attack_power);
        }
        return 1;
    }
    return 0;
}

void zombie::move() {
    if (stop == 0) {
        if (t % speed == 0) {
            //;stop=1;
            bx -= 1;
            x = bx / RectW;
        }
    }


    ;
}

void zombie::death() {
    if (alive == 0) {
        int cx = bx;
        drawPixel(cx + 2, by - 1, grasscolor);
        drawLine(cx, by, 4, true, grasscolor);
        //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
        drawPixel(cx + 2, by + 1, grasscolor);
        drawPixel(cx + 2, by + 2, grasscolor);
        drawLine(cx + 1, by + 3, 4, true, grasscolor);
        cx = bx + 1;
        drawPixel(cx + 2, by - 1, grasscolor);
        drawLine(cx, by, 4, true, grasscolor);
        //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
        drawPixel(cx + 2, by + 1, grasscolor);
        drawPixel(cx + 2, by + 2, grasscolor);
        drawLine(cx + 1, by + 3, 4, true, grasscolor);
    }
}

void zombie::freeze() {
    this->frozen = 1;
    this->speed = 10;//如果修改了初始值记得修改这里;
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
    this->t = 0;
}


void pea_bullet::work(class zombie &Z) {
    if (alive == 1) {
        if (Z.bx == this->bx + 1 && this->by <= Z.by + 1 && this->by >= Z.by - 3) {
            Z.hurt(attack_power);
            alive = 0;
        };
    } else { ;
    }
}

void pea_bullet::move() {
    if (t % speed == 0) {
        if (bx < MAPW) {
            bx += 1;
        } else {
            alive = 0;
        }
    }

}

void pea_bullet::draw() {
    if (alive == 1) {
        drawPixel(bx - 1, by, grasscolor);
        drawPixel(bx, by, plantcolor);
        //   drawPixel(bx - 1, by, grasscolor);
    } else {
        death();
    }
}

void pea_bullet::death() {
    if (alive == 0) {
        drawPixel(bx, by, grasscolor);
    }
}

////
////
////
//// 下面是 cold_bullet
cold_bullet::cold_bullet(int bx, int by, int frozen, int speed, int attack_power) : pea_bullet(bx, by, 1, speed,
                                                                                               attack_power) {
    ;
}

void cold_bullet::draw() {
    if (alive == 1) {
        drawPixel(bx - 1, by, grasscolor);
        drawPixel(bx, by, coldblue);
        //   drawPixel(bx - 1, by, grasscolor);
    } else {
        pea_bullet::death();
    }
}

void cold_bullet::move() {
    pea_bullet::move();
}

void cold_bullet::work(struct zombie &Z) {
    if (alive == 1) {
        if (Z.bx == this->bx + 1 && this->by <= Z.by + 1 && this->by >= Z.by - 3) {
            Z.hurt(attack_power);
            Z.freeze();
            alive = 0;
        };
    } else { ;
    }
}


////
////
////
//// 下面是 normal_zombie:
Normal_zombie::Normal_zombie(int X, int Y, int ID) : zombie(X, Y, 100, "normal zombie", 5, normal_zombie, ID, 10, 25,
                                                            25) {
    ;
};


Iron_zombie::Iron_zombie(int X, int Y, int ID) : zombie(X, Y, 300, "iron zombie", 5, iron_zombie, ID, 10, 25,
                                                        50) {
    this->iron = 1;
}

void Iron_zombie::draw() {

    if (alive == 1) {
        if (bx + 4 <= MAPW + RectW) {
            int cx = bx + 1;
            drawPixel(cx + 2, by - 1, grasscolor);
            drawLine(cx, by, 4, true, grasscolor);
            //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
            drawPixel(cx + 2, by + 1, grasscolor);
            drawPixel(cx + 2, by + 2, grasscolor);
            drawLine(cx + 1, by + 3, 4, true, grasscolor);
            //     drawText(cx + 1, by + 3, "HP:100", RED, GRAY);
        }
        if (iron == 0) { drawPixel(bx + 2, by - 1, zombiecolor); }
        else {
            drawPixel(bx + 2, by - 1, ironcolor);
        }
        drawText(bx, by, "铁桶僵尸", BLACK, zombiecolor);
        drawPixel(bx + 2, by + 1, RED);
        drawPixel(bx + 2, by + 2, GRAY);
        // drawText(bx + 1, by + 3, "HP:100", RED, GRAY);
        drawText_num(bx + 1, by + 3, "HP:", hp, RED, GRAY);
    } else {
        death();
    }

}


Roadblock_zombie::Roadblock_zombie(int X, int Y, int ID) : zombie(X, Y, 200, "roadblock zombie", 5, roadblock_zombie,
                                                                  ID, 10, 25,
                                                                  50) {
    this->roadblock = 1;
}

void Roadblock_zombie::draw() {

    if (alive == 1) {
        if (bx + 4 <= MAPW + RectW) {
            int cx = bx + 1;
            drawPixel(cx + 2, by - 1, grasscolor);
            drawLine(cx, by, 4, true, grasscolor);
            //    drawText(cx, by, "普通僵尸", BLACK, zombiecolor);
            drawPixel(cx + 2, by + 1, grasscolor);
            drawPixel(cx + 2, by + 2, grasscolor);
            drawLine(cx + 1, by + 3, 4, true, grasscolor);
            //     drawText(cx + 1, by + 3, "HP:100", RED, GRAY);
        }
        if (roadblock == 0) { drawPixel(bx + 2, by - 1, zombiecolor); }
        else {
            drawPixel(bx + 2, by - 1, ORANGE);
        }
        drawText(bx, by, "路障僵尸", BLACK, zombiecolor);
        drawPixel(bx + 2, by + 1, RED);
        drawPixel(bx + 2, by + 2, GRAY);
        // drawText(bx + 1, by + 3, "HP:100", RED, GRAY);
        drawText_num(bx + 1, by + 3, "HP:", hp, RED, GRAY);
    } else {
        death();
    }

}
