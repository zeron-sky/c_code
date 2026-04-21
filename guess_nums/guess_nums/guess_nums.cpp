#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//游戏逻辑
void game()
{
	int guess;
	int cnt = 5; // 5次猜数机会
	int r = rand() % 100 + 1;
	while (cnt)
	{
		printf("请猜一个数字:\n");
		printf("你当前还剩%d次机会：", cnt);
		scanf("%d", &guess);
		if (guess > r)
		{
			printf("猜大了！\n");
		}
		else if (guess < r)
		{
			printf("猜小了！\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
		cnt--;
	}
	if (cnt == 0)
	{
		printf("你失败了，正确的值为：%d\n", r);
	}
}

//打印菜单
void menu()
{
	printf("-----------------------------\n");
	printf("--------1.开始游戏------------\n");
	printf("--------0.退出游戏------------\n");
	printf("-----------------------------\n");
}

int main()
{
	// 初始化随机数种子（只执行1次）
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("请输入你的选择："); // 增加输入提示
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("\n"); // 游戏结束换行，分隔菜单
			break;
		case 0:
			printf("已退出！\n");
			break;
		default:
			printf("错误选择，请重试!\n\n");
			break;
		}
	} while (input); // 输入0退出循环
	return 0;
}