//
// Created by Larryytr on 2019/11/14.
//
#include "Game.h"
#include "linux_env.h"
int Game:: init(){
    screenClear();
    for(int i=0;i<RectnumW;i++){
        for(int j=0;j<RectnumH;j++){
            drawWholeRect(i*RectW,j*RectH,RectW,RectH,GRAY);
        }
    }
    drawTextB(16,4,"Plant VS Zombie",WHITE,BLACK);
    drawTextB(18,17,"Start",WHITE,BLACK);
    drawTextB(18,20,"Exit",WHITE,BLACK);
    init_keyboard();
    int state=100;
    while(1)
    {
        kbhit();
        switch (readch()){
            case 119:state+=1;break;
            case 115:state-=1;break;
            case 10: if(state%2==0){close_keyboard(); return 1;}//Start}
                     else{
                    close_keyboard(); return 0;//Exit
                     }
            default:break;
        }
        if(state%2==0){
            drawTextB(18,17,"Start",WHITE,RED);
            drawTextB(18,20,"Exit",WHITE,BLACK);//Start
        }else{
            drawTextB(18,17,"Start",WHITE,BLACK);
            drawTextB(18,20,"Exit",WHITE,RED);//Exit
        }

    }
   // close_keyboard();
}
void  Game::test(){
    int state=init();
    if(state==1){
        printf("start");
    }else{
        printf("Exit");
    }
}
void Game::play(){

;


}
