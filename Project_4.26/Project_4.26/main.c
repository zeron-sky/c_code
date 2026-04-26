#define _CRT_SECURE_NO_WARNINGS

//写一个二分查找函数
//
//功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回 - 1.
//
//int bin_search(int arr[], int left, int right, int key)
//arr 是查找的数组
//left 数组的左下标
//right 数组的右下标
//key 要查找的数字

//#include<stdio.h>
//
//int bin_search(int left, int right, int key, int arr[])
//{
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if(arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("请输入10个整数：");
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int key;
//	printf("请输入要查找的数：");
//	scanf("%d", &key);
//	int ret = bin_search(0, sz - 1, key, arr);
//	if (ret != -1)
//		printf("找到了,下标是：%d\n", ret);
//	else
//		printf("没有找到\n");
//	return 0;
//}


//乘法口诀表
//#include<stdio.h>
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %2d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//实现函数判断year是不是闰年。
//#include<stdio.h>
//#include<stdbool.h>
//
//bool is_leap(int y)
//{
//	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
//}
//
//int main()
//{
//	int year;
//	printf("请输入年份：");
//	scanf("%d", &year);
//	if (is_leap(year))
//		printf("闰年\n");
//	else
//		printf("平年\n");
//	return 0;
//}


//实现一个函数is_prime，判断一个数是不是素数。
//利用上面实现的is_prime函数，打印100到200之间的素数。
//#include<stdio.h>
//#include<stdbool.h>
//#include<math.h>
//
//bool is_prime(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	printf("100 ~ 200的素数为：");
//	for (int i = 101; i <= 200; i += 2)
//	{
//		if (is_prime(i))
//			printf("%d ", i);
//	}
//	return 0;
//}


//创建一个整形数组，完成对数组的操作
//
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。

#include<stdio.h>
//实现函数init() 初始化数组为全0
void init(int arr[],int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

//实现print()  打印数组的每个元素
void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//实现reverse()  函数完成数组元素的逆置。
void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++; right--;
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("逆置前的数组：");
	print(arr, sz);

	reverse(arr, sz);

	printf("逆置后的数组：");
	print(arr, sz);

	printf("全部初始化为0的数组：");
	init(arr, sz);
	print(arr, sz);

	return 0;
}