#define _CRT_SECURE_NO_WARNINGS

#include"SqList.h"

void TestSqList()
{
	SqList L;
	SqListInit(&L);//初始化顺序表
	
	printf("插入1\n");
	SqListInsert(&L, 0, 1);//插入元素
	SqListPrint(&L);//打印顺序表

	printf("\n");

	printf("插入2\n");
	SqListInsert(&L, 1, 2);//插入元素
	SqListPrint(&L);//打印顺序表

	printf("\n");

	printf("插入3\n");
	SqListInsert(&L, 2, 3);//插入元素
	SqListPrint(&L);//打印顺序表

	printf("\n");

	printf("插入4\n");
	SqListInsert(&L, 3, 4);//插入元素
	SqListPrint(&L);//打印顺序表

	printf("\n");

	printf("扩容,插入5\n");
	SqListInsert(&L, 4, 5);//扩容，插入元素
	SqListPrint(&L);//打印顺序表

	printf("\n");

	//头删
	printf("头删\n");
	SqListPopFront(&L);
	SqListPrint(&L);

	printf("\n");

	//尾删
	printf("尾删\n");
	SqListPopBack(&L);
	SqListPrint(&L);

	printf("\n");

	//查找第i个元素
	printf("第i个元素是%d\n", GetElem(&L, 2));
	
	printf("\n");

	//查找元素3
	printf("元素3在第%d个位置\n", LocatElem(&L, 3));

	printf("\n");

	//中间删除(删除第i个元素)
	printf("删除的是第%d个元素\n", SqListDelete(&L, 2));
	
	printf("\n");

	//获取元素个数
	printf("当前元素个数为:%d\n", SqListSize(&L));
	SqListPrint(&L);

	//销毁顺序表，释放内存
	SqListDestroy(&L);
}

int main()
{
	//测试代码
	TestSqList();

	return 0;
}