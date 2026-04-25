#define _CRT_SECURE_NO_WARNINGS

//空心正方形图案
//#include <stdio.h>
//
//int main()
//{
//	int a;
//	while (scanf("%d", &a) != EOF)
//	{
//		for (int i = 1; i <= a; i++)
//		{
//			for (int j = 1; j <= a; j++)
//			{
//				if (i == 1 || j == 1 || i == a || j == a)
//
//					printf("* ");
//				else
//					printf("  ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//X形图案
//#include <stdio.h>
//
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= n; j++)
//			{
//				if (j == i || j == n + 1 - i)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//矩阵转置
//#include <stdio.h>
//
//int main() {
//	int n, m;
//	long long arr[10][10];
//	while (scanf("%d %d", &n, &m) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				scanf("%lld", &arr[i][j]);
//			}
//		}
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				printf("%lld ", arr[j][i]);
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}


//逆序输出
//#include <stdio.h>
//
//int arr[15];
//
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 9; i >= 0; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//有序序列合并
//#include <stdio.h>
//
//int a[1010], b[1010], c[2010];
//
//int main()
//{
//	int n, m;
//	scanf("%d%d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &b[i]);
//	}
//	int i = 0, j = 0, k = 0;
//	while (i < n && j < m)
//	{
//		if (a[i] <= b[j])
//		{
//			c[k++] = a[i++];
//		}
//		else if (b[j] < a[i])
//		{
//			c[k++] = b[j++];
//		}
//	}
//	while (i < n)
//	{
//		c[k++] = a[i++];
//	}
//	while (j < m)
//	{
//		c[k++] = b[j++];
//	}
//	for (int i = 0; i < n + m; i++)
//	{
//		printf("%d ", c[i]);
//	}
//	return 0;
//}


//编写一个程序，从用户输入中读取10个整数并存储在一个数组中。然后，计算并输出这些整数的平均值。

//#include<stdio.h>
//int main()
//{
//	int arr[10];
//	double sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//		sum += arr[i];
//	}
//	printf("%.2f", sum / 10);
//	return 0;
//}


//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

//#include <stdio.h>
//
//#define N 5
//
//int a[N], b[N];
//
//int main()
//{
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &b[i]);
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		int tmp = a[i];
//		a[i] = b[i];
//		b[i] = tmp;
//	}
//
//	printf("\n交换后A数组：");
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//	printf("\n交换后B数组：");
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d ", b[i]);
//	}
//
//	printf("\n");
//
//	return 0;
//}


//求10 个整数中最大值

#include<stdio.h>

int arr[10];

int main()
{
	int x, max;
	scanf("%d", &x);
	max = x;
	for (int i = 1; i < 10; i++)
	{
		scanf("%d", &x);
		if (x > max)
			max = x;
	}
	printf("最大值为：%d", max);
}