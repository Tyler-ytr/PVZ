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
    plant_catch = -1;
    ID = 0;
}

void controller::buy_plant(int x, int y) {
    if (y == 0) {
        switch (x) {
            case 0:
                plant_catch = coldshotter;
                break;
            case 1:
                plant_catch = sunflower;
                break;
            case 2:
                plant_catch = peashotter;
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
            default:
                break;
        }


    }
    plant_catch = -1;

}

void controller::zombie_productor(int x, int y, int type) {
    class zombie *temp_zombie;
    switch (type) {
        case normal_zombie:
            temp_zombie = new Normal_zombie(x, y, ID);
            ID += 1;
            zombie_group.push_back(temp_zombie);
            break;
    }
}

void controller::plant_group_work() {
    //https://blog.csdn.net/wangshubo1989/article/details/50121059
    vector<class plant *>::iterator itor2;
    for (vector<class plant *>::iterator temp_plant = plant_group.begin(); temp_plant != plant_group.end();) {
        if ((*temp_plant)->alive == 0) {
            itor2 = temp_plant;
            plant_group.erase(itor2);
        } else {
            for (vector<class zombie *>::iterator temp_zombie = zombie_group.begin();
                 temp_zombie != zombie_group.end(); temp_zombie++) {
                int result = (*temp_plant)->work(*(*temp_zombie));
                switch ((*temp_plant)->type) {
                    case peashotter: { ;
                        break;//对result进行处理;
                    }
                }

            }
            switch ((*temp_plant)->type) {//对常态work进行处理
                case peashotter: {
                    if ((*temp_plant)->Ready == 1) {
                        int bx = (*temp_plant)->bx;
                        int by = (*temp_plant)->by;
                        class pea_bullet *temp_bullet;
                        temp_bullet = new pea_bullet(bx, by, 0, 3, 20);
                        bullet_group.push_back(temp_bullet);
                    };
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
            itor2 = temp_zombie;
            zombie_group.erase(itor2);

        } else {
            for(vector<class plant*>::iterator temp_plant=plant_group.begin();temp_plant!=plant_group.end();temp_plant++){
                int result=(*temp_zombie)->work(*(*(temp_plant)));
                if(result==1)break;
            }


            temp_zombie++;
        }
    };
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
////
////
////
////



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
    this->t = 0;

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

    drawText(2 * RectW + 2, 0 * RectH + 3, "豌豆射手", BLACK, plantcolor);
    drawPixel(2 * RectW + 2, 0 * RectH + 4, plantcolor);
    drawPixel(2 * RectW + 2, 0 * RectH + 5, plantcolor);
    //drawText(2 * RectW + 1, 1 * RectH + 6, "HP:100", RED, plantcolor);
    drawText_num(2 * RectW + 1, 0 * RectH + 6, "HP:", 100, RED, plantcolor);
//寒冰射手
    drawText(0 * RectW + 2, 0 * RectH + 3, "寒冰射手", BLACK, coldblue);
    drawPixel(0 * RectW + 2, 0 * RectH + 4, coldblue);
    drawPixel(0 * RectW + 2, 0 * RectH + 5, coldblue);
    drawText(0 * RectW + 1, 0 * RectH + 6, "HP:100", RED, coldblue);


//向日葵:

    drawPixel(RectW + 4, 0 * RectH + 2, ORANGE);
    drawText(RectW + 3, 0 * RectH + 3, "向日葵", BLACK, ORANGE);
    drawPixel(RectW + 4, 0 * RectH + 4, ORANGE);
    drawPixel(RectW + 4, 0 * RectH + 5, plantcolor);
    drawText(RectW + 3, 0 * RectH + 6, "HP:100", RED, plantcolor);

//樱桃炸弹：
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

void plant::time_passing() {
    t += 1;
}

////
////
////
////下面是peashooter
peashooter::peashooter(int X, int Y, int ID) : plant(X, Y, 100, "peashooter", 5, peashotter, ID) {
    bx = plant::x * RectW + 2 + 4;
    by = plant::y * RectH + 3;

};

void peashooter::draw() {
    ;
    drawText(bx - 4, by, "豌豆射手", BLACK, plantcolor);
    drawPixel(bx - 4, by + 1, plantcolor);
    drawPixel(bx - 4, by + 2, plantcolor);
    // drawText(bx-5, by+3, "HP:100", RED, plantcolor);
    drawText_num(bx - 5, by + 3, "HP:", 100, RED, plantcolor);
}

int peashooter::work(class zombie &Z) {
    if (t % speed == 0) {
        Ready = 1;
        return 1;
    } else {
        return 0;
    }
}

////
////
////
////下面是zombie
//zombie::    zombie(int X, int Y, int Hp, std::string Name,int speed, int Type, int ID){
//    ;
//}
zombie::zombie(int X, int Y, int Hp, std::string Name, int speed, int Type, int ID,int attack_power) {
    x = X;
    y = Y;
    hp = Hp;
    name = Name;
    type = Type;
    this->ID = ID;
    alive = 1;
    bx = x * RectW + 2;
    by = y * RectH + 3;
    t = 0;
    frozen = 0;
    this->attack_power=attack_power;

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
        if (bx + 4 <= MAPW) {
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
        if (bx <= P.bx + 1 && bx >= -5) {
        return 1;
        }
    }
    return 0;
}

int zombie::work(class plant &P) {
    if(check_in_attack(bx,by,P)==1) {
        P.hurt(this->attack_power);return 1;
    }return 0;
}

void zombie::move() {
    if (t % speed == 0) {
        bx -= 1;
        x = bx / RectW;;
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
    this->t = 0;
}

void pea_bullet::work(class zombie &Z) {
    if (alive == 1) {
        if (Z.bx == this->bx + 1) {
            Z.hurt(attack_power);
            alive = 0;
        };
    } else { ;
    }
}

void pea_bullet::move() {
    if (t % speed == 0) {
        if (bx <= MAPW) {
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
//// 下面是 normal_zombie:
Normal_zombie::Normal_zombie(int X, int Y, int ID) : zombie(X, Y, 100, "normal zombie", 5, normal_zombie, ID,20) {
    ;
};
