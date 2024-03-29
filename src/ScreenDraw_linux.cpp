
#include <iostream>
#include <string>
#include <sstream>
#include "ScreenDraw_linux.h"
#include <cstdio>
#include <algorithm>

void drawPixel(int x, int y, int color){
    int tx = std::max(x, 0) + 1;
    int ty = std::max(y, 0) + 1;

    printf("\033[%d;%dH\033[48;5;%dm  \033[0m\n", ty, 2*tx-1, color);
}

void drawPixelC(int x, int y, char c1, char c2, int color, int backColor){
    int tx = std::max(x, 0) + 1;
    int ty = std::max(y, 0) + 1;

    printf("\033[%d;%dH\033[38;5;%dm\033[48;5;%dm%c%c\033[0m\n", ty, 2*tx-1, color, backColor, c1, c2);
}
void drawPixelB(int x,int y,int color){//Pixel里面的文字闪烁
    int tx = std::max(x, 0) + 1;
    int ty = std::max(y, 0) + 1;

    printf("\033[%d;%dH\033[48;5;%dm  \033[5m\n", ty, 2*tx-1, color);
}
void screenClear(){
    printf("\033[2J\n");
}

void clearRect(int x, int y, int w, int h){
    printf("\033[0m");
    for(int i = 0; i < h; ++i){
        printf("\033[%d;%dH", y+1+i, 2*(x+1)-1);
        for(int j = 0; j < w; ++j){
            printf("  ");
        }
    }
    printf("\n");
}

void drawLine(int x, int y, int l, bool hori, int color){
    if(hori){
        printf("\033[%d;%dH", y+1, 2*(x+1)-1);
        printf("\033[48;5;%dm", color);
        for(int i = 0; i < l; ++i){
            printf("  ");
        }
        printf("\033[0m\n");
    }
    else{
        for(int i = 0; i < l; ++i){
            drawPixel(x, y+i, color);
        }
    }
}

void drawLineB(int x, int y, int l, bool hori, int color){//线里面的文字闪烁
    if(hori){
        printf("\033[%d;%dH", y+1, 2*(x+1)-1);
        printf("\033[48;5;%dm", color);
        for(int i = 0; i < l; ++i){
            printf("  ");
        }
        printf("\033[5m\n");
    }
    else{
        for(int i = 0; i < l; ++i){
            drawPixelB(x, y+i, color);
        }
    }
}

void drawLineC(int x, int y, int l, char c1, char c2, bool hori, int color, int backColor){
    if(hori){
        printf("\033[%d;%dH", y+1, 2*(x+1)-1);
        printf("\033[38;5;%dm\033[48;5;%dm", color, backColor);
        for(int i = 0; i < l; ++i){
            printf("%c%c", c1, c2);
        }
        printf("\033[0m\n");
    }
    else{
        for(int i = 0; i < l; ++i){
            drawPixelC(x, y+i, c1, c2, color, backColor);
        }
    }
}

void drawRect(int x, int y, int w, int h, int color){
    drawLine(x, y, w, 1, color);
    drawLine(x, y+h-1, w, 1, color);
    drawLine(x, y, h, 0, color);
    drawLine(x+w-1, y, h, 0, color);
}

void drawWholeRect(int x, int y, int w, int h, int color){
    for(int i = 0; i < h; ++i){
        drawLine(x, y+i, w, 1, color);
    }
}

void drawText(int x, int y, string str, int color, int backColor){
    printf("\033[%d;%dH", y+1, 2*x+1);
    printf("\033[38;5;%dm", color);
    printf("\033[48;5;%dm", backColor);
    printf(str.c_str());
    printf("\033[0m\n");
}
void drawText_num(int x, int y, string str,int num,int color, int backColor){
    printf("\033[%d;%dH", y+1, 2*x+1);
    printf("\033[38;5;%dm", color);
    printf("\033[48;5;%dm", backColor);
    printf(str.c_str());
    printf("%d",num);
    printf("\033[0m\n");
}
void drawdefence(int x,int y,int l,int color,int backColor){

    for(int i = 0; i < l; ++i){
        printf("\033[%d;%dH", y+i+1, 2*x+1);
        printf("\033[38;5;%dm", color);
        printf("\033[48;5;%dm", backColor);
        printf("|");
        printf("\033[0m\n");
        printf("\033[%d;%dH", y+i+1, 2*x);
        printf("\033[38;5;%dm", color);
        printf("\033[48;5;%dm", backColor);
        printf("|");
        printf("\033[0m\n");
    }
//    printf("|");
//    printf("\033[0m\n");
}
void drawdefence2(int x,int y,int l,int color,int backColor){

    for(int i = 0; i < l; ++i){
        printf("\033[%d;%dH", y+i+1, 2*x+1);
        printf("\033[38;5;%dm", color);
        printf("\033[48;5;%dm", backColor);
        printf("|");
        printf("\033[0m\n");
        printf("\033[%d;%dH", y+i+1, 2*(x+RectH));
        printf("\033[38;5;%dm", color);
        printf("\033[48;5;%dm", backColor);
        printf("|");
        printf("\033[0m\n");
    }
//    printf("|");
//    printf("\033[0m\n");
}
void drawTextB(int x, int y, string str, int color, int backColor){
    printf("\033[%d;%dH", y+1, 2*x+1);
    printf("\033[38;5;%dm", color);
    printf("\033[48;5;%dm", backColor);
    printf(str.c_str());
    printf("\033[0m\n");
}
