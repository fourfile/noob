#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//数组初始化
void initarr(char arr[rows][cols], int r, int c,char set)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			arr[i][j]=set;
		}
	}
}
//打印地图
void printarr(char arr[rows][cols], int r, int c)
{
	printf("-----扫雷开始------\n");
	int i = 0;
	//打印列号
	for(i=0;i<=r;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= r; i++)
	{
		
		int j = 0;
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= c; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
//布置雷，布置雷的x,y范围是1-9
void setmine(char mine[rows][cols], int r, int c)
{
	int count = easymine;
	while (count)
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if(mine[x][y]=='0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//统计周围雷数量
int getminecount(char mine[rows][cols], int x, int y)
{
	int i = 0;
	int j = 0;
	int p = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (mine[x + i][y + j] == '1')
			{
				p++;
			}
		}
	}
	return p;
}
//排查雷
void findmine(char mine[rows][cols], char show[rows][cols], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while(1)
	{
		printf("请输入你要排查的坐标\n");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{//判断是否为雷
			if(mine[x][y]=='1')
			{
				printf("很遗憾，你被炸死了\n");
				printarr(mine, r,c);
				break;
			}
			else
			{
				
				//统计周围雷数量
				int count = getminecount(mine,x,y);
				show[x][y] = count + '0';
				printarr(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	if(win==r*c-easymine)
	{
		printf("恭喜你！！游戏通关！！");
		printarr(mine, row, col);
	}

}
