#define _CRT_SECURE_NO_WARNINGS
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

//#include<stdio.h>
//#include<stdbool.h>
//#include<string.h>
//
//void left(char* s)
//{
//	char n = *s;
//	char* m = s;
//	while (*(m + 1) != '\0')
//	{
//		*m = *(m + 1);
//		m++;
//	}
//	*m = n;
//}
//
//int is_left(char* p1, char* p2)
//{
//	int len1 = strlen(p1), len2 = strlen(p2);
//	if (len1 != len2)
//		return 0;
//
//	for (int i = 0; i < len2; i++)
//	{
//		left(p2);
//		if (strcmp(p1, p2) == 0)
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	char s1[] = "aabcd", s2[] = "bcdaa", s3[] = "abcd", s4[] = "acbd";
//	printf("测试一: %d\n", is_left(s1, s2));
//	printf("测试二：%d\n", is_left(s3, s4));
//	return 0;
//}


//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);

#include<stdio.h>
#include<stdbool.h>

int search(int arr[3][3], int x, int y, int n)
{
	int i = 0, j = y - 1;
	while (i < x && j >= 0)
	{
		if (arr[i][j] < n)
			i++;
		else if (arr[i][j] > n)
			j--;
		else
			return 1;
	}
	return 0;
}

int main()
{
	int i, j, n;
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

	printf("%d", search(arr, 3, 3, 5));

	return 0;
}