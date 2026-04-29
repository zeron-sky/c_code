#define _CRT_SECURE_NO_WARNINGS

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//输入：1729，输出：19


//#include<stdio.h>
//
//int DigitSum(int n)
//{
//	if (n == 0)
//		return 0;
//	return n % 10 + DigitSum(n / 10);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", DigitSum(n));
//	return 0;
//}


//递归方式实现打印一个整数的每一位

#include<stdio.h>

void DigitPrint(int n)
{
	if (n > 9)
		DigitPrint(n / 10);
	printf("%d ", n % 10);
}

int main()
{
	int n;
	scanf("%d", &n);
	DigitPrint(n);
	return 0;
}
