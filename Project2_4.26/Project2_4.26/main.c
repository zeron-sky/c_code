#define _CRT_SECURE_NO_WARNINGS

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
//#include<stdio.h>
//
//int Total1(int money)
//{
//	int total = money;//当前可以喝多少瓶饮料
//	int empty = money;//产生的空瓶
//
//	while (empty >= 2)
//	{
//		total += empty / 2;//饮料总数
//		empty = empty / 2 + empty % 2;
//	}
//	return total;
//}
//
//int Total2(int money)
//{
//	return money * 2 - 1;
//}
//
//int main()
//{
//	printf("给20元,可以喝%d瓶汽水\n", Total1(20));
//	printf("给20元,可以喝%d瓶汽水\n", Total2(20));
//	return 0;
//}


//用C语言在屏幕上输出图案

//#include<stdio.h>
//
//void print(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n - i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = n - 1; i >= 1; i--)
//	{
//		for (int j = 1; j <= n - i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	print(7);
//	return 0;
//}


//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
//如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

//#include<stdio.h>
//#include<stdbool.h>
//
//int power(int m, int n)
//{
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= m;
//	}
//	return ret;
//}
//
//bool is_narcissistic_number(int n)
//{
//	int cnt = 0;
//	int tmp = n;
//	if (n == 0)
//		return true;
//
//	while (tmp)
//	{
//		cnt++;
//		tmp /= 10;
//	}
//	tmp = n;
//	int sum = 0;
//	while (tmp)
//	{
//		sum += power(tmp % 10 , cnt);
//		tmp /= 10;
//	}
//	return sum == n;
//}
//
//int main()
//{
//	for (int i = 0; i <= 100000; i++)
//	{
//		if (is_narcissistic_number(i))
//			printf("%d ", i);
//	}
//	return 0;
//}


//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

//#include<stdio.h>
//
//int sum(int m)
//{
//	int s = 0, ret = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		s = s * 10 + m;
//		ret += s;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", sum(n));
//	return 0;
//}


//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）

#include<stdio.h>
//非递归写法
int fact1(int m)
{
	int ret = 1;
	for (int i = 1; i <= m; i++)
	{
		ret *= i;
	}
	return ret;
}

//递归写法
int fact2(int m)
{
	if (m == 0 || m == 1)
		return 1;
	return (m * fact2(m - 1));
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("非递归写法,%d的阶乘为:%d\n", n, fact1(n));
	printf("递归写法,%d的阶乘为:%d", n, fact2(n));

	return 0;
}