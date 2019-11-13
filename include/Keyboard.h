//
// Created by larryytr on 2019/11/14.
//

#ifndef PVZ_KEYBOARD_H
#define PVZ_KEYBOARD_H
#include <termio.h>
#include <stdio.h>


void init_keyboard(void);
void close_keyboard(void);
int kbhit(void);
int readch(void);
long long getTime();

#endif //PVZ_KEYBOARD_H
