#pragma once
#ifndef _OBJ_H
#define _OBJ_H
#include "Controller.h"
#include "common.h"
extern class Controller;
enum plant_list{
    pea_shooter=0,
    cherry_bomb=1,
};
enum zombie_list{
    normal_zombie=0,
    Iron_barrel_zombie=1,
};
/*plant* create_plant(int i){
  plant* temp;
  switch (i){
    case pea_shooter:temp=new pea_shooter();break;
    case cherry_bomb:temp=new cherry_bomb();break;
  }
    ;
}
*/
class object{
   protected:
   int speed;
   int hp;
   int x;
   int y;
   int time;
   class Controller *control;

  public:
  virtual void done()=0;
  object(Controller *Control,int X,int Y){
      control=Control;
      x=X;
      y=Y;
      time=0;
      speed=1;
      hp=100;
  }

 };

class plant:public object{
  protected:
  int sun;
  public:
  plant(Controller *Control,int X,int Y):object(Control,X,Y){
    ;
  }
  int sun_num(){
      return sun;
  }
  virtual void done(){
      ;
  }
  void attack(int power){
      int temphp=hp-power;
      if(temphp>=0){
        hp=temphp;
      }else{
          node**tempmap=control->map;
            tempmap[x][y].plant_state=-1;
      }

  }


};




enum STATE{Normal=0,Frozen=1};
class zombie:public object{
  protected:
    int state;
    int attack;
  public:
    void change_state(int S){
        state=S;
    }
    zombie(Controller*Control,int X,int Y):object(Control,X,Y){
        state=Normal;
    }
  virtual void done(){
      int tempy;

      if(y==0){
          tempy=0;
      }else{
          tempy=y-1;
      }
      int check_plant_next=control->map[x][tempy].plant_state;
      int check_plant_now=control->map[x][y].plant_state;




  }


};
class pea{
    private:
        int state;
};




#endif
