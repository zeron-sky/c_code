#define _CRT_SECURE_NO_WARNINGS

//写一个代码打印1 - 100之间所有3的倍数的数字
//#include<stdio.h>
//int main()
//{
//	for (int i = 3; i <= 100; i += 3)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}



//写代码将三个整数数按从大到小输出。
//
//例如：
//
//输入：2 3 1
//
//输出：3 2 1


//#include<stdio.h>
//int main()
//{
//	int a, b, c, tmp;
//	scanf("%d%d%d", &a, &b, &c);
//	if (b > a)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (c > a)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (c > b)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}



//给定两个数，求这两个数的最大公约数
//
//例如：
//
//输入：20 40
//
//输出：20

#include<stdio.h>
int main()
{
	int a, b, tmp;
	scanf("%d%d", &a, &b);
		while (a != 0)
		{
			tmp = a % b;
			b = a;
			a = tmp;
		}
		printf("%d", b);
	return 0;
}