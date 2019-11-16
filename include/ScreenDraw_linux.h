#pragma once
#include <string>
#include "Map.h"
#define BLACK         	0
#define RED           	9
#define GREEN         	28
#define YELLOW 			178
#define BLUE 			25
#define PURPLE 			55
#define DARKGREEN 		28
#define WHITE 			15
#define LIGHTGREEN      47
#define BROWN           94
#define ORANGE          208
#define GRAY            239
#define LIGHTGRAY       247
#define LIGHTYELLOW     11
#define LIGHTBLUE       27
#define SQUASHGREEN     76
#define PINK            165
#define DARKRED         88
#define shopcolor       12
#define grasscolor      72
//#define grasscolor      42
//#define grasscolor      245
#define coldblue        75
#define plantcolor      28
#define zombiecolor     106
#define ironcolor       103

using namespace std;

void drawPixel(int x, int y, int color);
void drawPixelB(int x, int y, int color);
void drawPixelC(int x, int y, char c1, char c2, int color, int backColor);
void screenClear();
void clearRect(int x, int y, int w, int h);
void drawLine(int x, int y, int l, bool hori, int color);
void drawLineC(int x, int y, int l, char c1, char c2, bool hori, int color, int backColor);
void drawRect(int x, int y, int w, int h, int color);
void drawWholeRect(int x, int y, int w, int h, int color);
void drawText(int x, int y, string str, int color, int backColor);
void drawLineB(int x, int y, int l, bool hori, int color);
void drawTextB(int x, int y, string str, int color, int backColor);
void drawdefence(int x,int y,int l,int color,int backColor);
void drawdefence2(int x,int y,int l,int color,int backColor);
void drawText_num(int x, int y, string str,int num,int color, int backColor);
//for(int i=0;i<RectnumW;i++){
//for(int j=0;j<RectnumH;j++){
//drawWholeRect(i*RectW,j*RectH,RectW,RectH,WHITE);
//drawRect(i*RectW,j*RectH,RectW,RectH,BLUE);
//// clearRect(i*RectH+1,j*RectW,RectH-2,RectW-2);
//}
//}
//drawPixel(1,1,RED);
//drawPixel(1,4,RED);
//drawPixel(4,4,RED);
//drawPixel(4,1,RED);
//drawPixel(1,7,RED);
//drawPixel(6*6+4,5*6+4,PINK);
//drawPixel(6*RectnumW-1,0,YELLOW);
//drawPixel(6*RectnumW-1,6*RectnumH-1,YELLOW);
//drawPixel(4,4,YELLOW);
//drawPixel(6,6,YELLOW);
//drawPixel(MAPW,MAPH,GREEN);
//drawRect(3*RectW,3*RectH,RectW,RectH,BLUE);
//drawLine(7,7,4,true,BROWN);
//drawText(7, 8, "TEST", GREEN, BROWN);