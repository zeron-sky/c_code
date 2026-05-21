#define _CRT_SECURE_NO_WARNINGS

//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。

//#define SWAP_EVEN_ODD(n) ((n & 0x55555555) << 1) ^ ((n & 0xAAAAAAAA) >> 1)
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	//int even_mask = 0x55555555;
//	//int odd_mask = 0xAAAAAAAA;
//
//	//int m1 = n & even_mask;//取出偶数位
//	//int m2 = n & odd_mask;//取出奇数位
//
//	//int ret_even = m1 << 1;
//	//int ret_odd = m2 >> 1;
//
//	//int ret = ret_even ^ ret_odd;
//
//	printf("%d\n", SWAP_EVEN_ODD(n));
//	return 0;
//}


//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//考察：offsetof宏的实现

#define my_offsetof(n, m)  (size_t)&(((n*)0)->m)
#include<stdio.h>

struct S
{
	int a;
	int b;

};

int main()
{
	struct S s;
	struct S* p = &s;
	p->a = 10;
	p->b = 20;

	printf("b相对于首地址的偏移量为：%zu", my_offsetof(struct S, b));
	return 0;
}