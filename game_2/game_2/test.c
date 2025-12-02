#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
 void menu()
 {
	 printf("****************************\n");
	 printf("********** 1.play **********\n");
	 printf("********** 0.exit **********\n");
	 printf("****************************\n");
}
 void game()
 {
	 //定义两个数组，一个存放雷放置的信息，一个放探索雷的信息
	 char mine[rows][cols ] ;
	 char show[rows][cols]  ;
	//初始化数组，mine全为0（0表示不是雷区，1表示为雷区），show全为*（*表示未探索区域） 
	 initarr(mine,rows,cols,'0');
	 initarr(show,rows,cols,'*');
	 //布置雷
	 setmine(mine,row,col);
	 //打印棋盘
	// printarr(mine,row,col);//雷的信息
	 printarr(show,row,col);
	 //排查雷
	 findmine(mine, show, row, col);
 }
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏逻辑
				break;
		case 0:
			printf("你已经退出游戏\n");
				break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}

