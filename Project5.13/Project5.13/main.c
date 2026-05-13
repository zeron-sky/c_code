#define _CRT_SECURE_NO_WARNINGS

//对于给定的由小写字母和空格混合构成的字符串s，将其翻转后输出。
//保证给定的字符串s 的首尾不为空格。

//#define N 10010
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr[N];
//	fgets(arr, N, stdin);
//	arr[strcspn(arr, "\n")] = '\0';
//	int len = strlen(arr);
//	for (int i = len - 1; i >= 0; i--)
//		printf("%c", arr[i]);
//	return 0;
//}


//模拟实现库函数strlen

//#include<stdio.h>
//
//size_t my_strlen(const char* p)
//{
//	const char* end = p;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - p;
//}
//
//int main()
//{
//	char arr[10];
//	scanf("%s", arr);
//	size_t len = my_strlen(arr);
//	printf("%zu", len);
//	return 0;
//}


//调整数组使奇数全部都位于偶数前面。
//
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

#include<stdio.h>

void Swap(int *a, int *b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void reorder_odd_even(int* p, int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while (left < right && (*(p + left) % 2) != 0)
			left++;
		while (left < right && (*(p + right) % 2) == 0)
			right--;
		if (left < right)
			Swap(p + left, p + right);
		else
			break;
	}
}

int main()
{
	int arr[10];
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++)
		scanf("%d", &arr[i]);
	reorder_odd_even(arr, sz);
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}