#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"

//初始化顺序表
void SqListInit(SqList* ps)
{
	assert(ps);
	ps->arr = (SqDataType*)malloc(sizeof(SqDataType) * 4);
	if (ps->arr == NULL)
	{
		//申请失败，退出
		printf("申请失败，退出\n");
		return;
	}
	//申请成功
	ps->capacity = 4;
	ps->size = 0;
}

//顺序表的销毁
void SqListDestroy(SqList* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->size = 0;
		ps->capacity = 0;
	}
}

//在顺序表的第i个位置插入x
void SqListInsert(SqList* ps, int i, SqDataType x)
{
	assert(ps);
	assert(i >= 0 && i <= ps->size);
	//顺序表满了，扩容
	if (ps->size == ps->capacity)
	{
		SqDataType* tmp = (SqDataType*)realloc(ps->arr, sizeof(SqDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			printf("扩容失败\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}
	//从i的位置开始，将i后面的元素往后挪
	for (int j = ps->size - 1; j >= i; j--)
	{
		ps->arr[j + 1] = ps->arr[j];
	}
	ps->arr[i] = x;
	ps->size++;
}

//删除第i个元素，返回删除的元素
SqDataType SqListDelete(SqList* ps, SqDataType i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);

	int x = ps->arr[i];
	for (int j = i; j < ps->size - 1; j++)
	{
		ps->arr[j] = ps->arr[j + 1];
	}
	ps->size--;
	return x;
}

//返回顺序表中第i个元素下标位置的值(按位序查找)
SqDataType GetElem(SqList* ps, int i)
{
	assert(ps);
	assert(i >= 0 && i < ps->size);

	return ps->arr[i];
}

//返回第一个元素等于x的下标位置(按值查找)
int LocatElem(SqList* ps, SqDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
			return i;
	}
	return -1;
}

//打印顺序表
void SqListPrint(SqList* ps)
{
	assert(ps);
	printf("顺序表的元素为:");
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//获取顺序表的元素个数
int SqListSize(SqList* ps)
{
	assert(ps);
	return ps->size;
}

//判断顺序表的元素是否为空
bool Empty(SqList* ps)
{
	assert(ps);
	return ps->size == 0;
}

//头插
void SqListPushFront(SqList* ps, SqDataType x)
{
	assert(ps);
	SqListInsert(ps, 0, x);
}

//尾插
void SqListPushBack(SqList* ps, SqDataType x)
{
	assert(ps);
	SqListInsert(ps, ps->size, x);
}

//头删
void SqListPopFront(SqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	SqListDelete(ps, 0);
}

//尾删
void SqListPopBack(SqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	SqListDelete(ps, ps->size - 1);
}