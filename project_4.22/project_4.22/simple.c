#define _CRT_SECURE_NO_WARNINGS

//打印1000年到2000年之间的闰年
//#include<stdio.h>
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
//			printf("%d ", i);
//	}
//	return 0;
//}


//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
#include<stdio.h>
int main()
{
	double sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			sum += -1.0 / i;
		}
		else
		{
			sum += 1.0 / i;
		}
	}
	printf("%f", sum);
	return 0;
}