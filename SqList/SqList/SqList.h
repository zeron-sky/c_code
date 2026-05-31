#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int SqDataType;

typedef struct
{
	SqDataType* arr;//存储动态数组数据的指针
	int size;//记录当前顺序表中已经存入元素的个数
	int capacity;//动态数组的容量大小
}SqList;

//初始化顺序表
void SqListInit(SqList* ps);

//销毁顺序表
void SqListDestroy(SqList* ps);

//返回顺序表中第i个元素下标位置的值(按位序查找)
SqDataType GetElem(SqList* ps, int i);

//返回第一个元素等于x的下标位置(按值查找)
int LocatElem(SqList* ps, SqDataType x);

//在顺序表的第i个位置插入x
void SqListInsert(SqList* ps, int i, SqDataType x);

//在顺序表中删除第i个元素 并返回删除的值
SqDataType SqListDelete(SqList* ps, SqDataType i);

//打印顺序表
void SqListPrint(SqList* ps);

//判断顺序表的元素是否为空
bool Empty(SqList* ps);

//获取顺序表的元素个数
int SqListSize(SqList* ps);

//头插尾插
void SqListPushBack(SqList* ps, SqDataType x);
void SqListPushFront(SqList* ps, SqDataType x);

//头删尾删
void SqListPopBack(SqList* ps);
void SqListPopFront(SqList* ps);
