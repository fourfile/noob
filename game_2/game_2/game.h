#pragma once
#define row 9
#define col 9
#define rows row+2
#define cols col+2
//简单模式
#define easymine 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//初始化棋盘
void initarr(char arr[rows][cols], int r, int c,char set);
//打印棋盘
void printarr(char arr[rows][cols], int r, int c);
//布置雷
void setmine(char mine[rows][cols], int r, int c);
//排查雷
void findmine(char mine[rows][cols], char show[rows][cols], int r, int c);
