#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int DCLDataType;

// 双向循环链表节点。
typedef struct DCList
{
	DCLDataType data;
	struct DCList* prev;
	struct DCList* next;
} DCListNode;

// 申请一个新节点。
DCListNode* BuyDCList(DCLDataType data);

// 初始化带哨兵位的头节点。
DCListNode* DCListInit();

// 销毁整个链表。
void DCListDestroy(DCListNode* L);

// 获取下标为 i 的节点。
DCListNode* DCListGetElem(DCListNode* L, int i);

// 在 pos 后插入 x。
void DCListInsert(DCListNode* pos, DCLDataType x);

// 删除 pos 节点。
void DCListDelete(DCListNode* pos);

// 头插。
void DCListPushFront(DCListNode* L, DCLDataType x);

// 尾插。
void DCListPushBack(DCListNode* L, DCLDataType x);

// 头删。
void DCListPopFront(DCListNode* L);

// 尾删。
void DCListPopBack(DCListNode* L);

// 打印所有数据节点。
void DCListPrint(DCListNode* L);
