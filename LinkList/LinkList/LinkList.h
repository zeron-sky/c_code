#pragma once

/*
 * 文件: LinkList.h
 * 功能: 单链表（带头节点）的头文件，包含结构体定义和函数声明
 * 说明: 本链表使用带头节点的方式实现，头节点不存储有效数据
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/* 链表数据类型，可根据需要修改 */
typedef int LDataType;

/*
 * 结构体: ListNode
 * 功能: 链表节点结构
 * 成员:
 *   - data: 节点存储的数据
 *   - next: 指向下一个节点的指针
 */
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
}LNode;

/*
 * 函数: BuyListNode
 * 功能: 创建一个新的链表节点
 * 参数: data - 新节点存储的数据
 * 返回: 成功返回新节点地址，失败则退出程序
 */
LNode* BuyListNode(LDataType data);

/*
 * 函数: ListInit
 * 功能: 初始化链表，创建头节点
 * 参数: 无
 * 返回: 返回创建的头节点地址
 * 说明: 头节点的data字段存储无效值(-1)，不计入链表长度
 */
LNode* ListInit();

/*
 * 函数: ListPrint
 * 功能: 打印链表中所有节点的数据
 * 参数: L - 链表的头节点指针
 * 返回: 无
 * 输出格式: Head->1->2->3->NULL
 */
void ListPrint(LNode* L);

/*
 * 函数: ListSize
 * 功能: 获取链表中有效节点的数量
 * 参数: L - 链表的头节点指针
 * 返回: 有效节点的数量（不包括头节点）
 */
int ListSize(LNode* L);

/*
 * 函数: ListLocateElem
 * 功能: 查找链表中第一个值为x的节点
 * 参数: L - 链表的头节点指针，x - 要查找的值
 * 返回: 找到返回节点地址，未找到返回NULL
 */
LNode* ListLocateElem(LNode* L, LDataType x);

/*
 * 函数: ListElem
 * 功能: 获取链表中第i个位置的节点（从0开始计数）
 * 参数: L - 链表的头节点指针，i - 位置索引（从0开始）
 * 返回: 成功返回节点地址，位置无效返回NULL
 */
LNode* ListElem(LNode* L, int i);

/*
 * 函数: ListInsert
 * 功能: 在链表的第i个位置插入新元素
 * 参数: L - 链表的头节点指针，i - 插入位置（从0开始），x - 要插入的值
 * 返回: 无
 * 说明: 插入后新元素成为第i个位置的节点
 */
void ListInsert(LNode* L, int i, LDataType x);

/*
 * 函数: ListPDelete
 * 功能: 删除链表中第i个位置的节点
 * 参数: L - 链表的头节点指针，i - 要删除的位置（从0开始）
 * 返回: 被删除节点的值
 * 说明: 位置i必须有效，否则程序会断言失败
 */
LDataType ListPDelete(LNode* L, int i);

/*
 * 函数: ListEmpty
 * 功能: 判断链表是否为空
 * 参数: L - 链表的头节点指针
 * 返回: 链表为空返回true，否则返回false
 */
bool ListEmpty(LNode* L);

/*
 * 函数: ListPushFront
 * 功能: 在链表头部插入新节点（头插法）
 * 参数: L - 链表的头节点指针，x - 要插入的值
 * 返回: 无
 * 说明: 新节点插入到头节点之后，成为第一个有效节点
 */
void ListPushFront(LNode* L, LDataType x);

/*
 * 函数: ListPushBack
 * 功能: 在链表尾部插入新节点（尾插法）
 * 参数: L - 链表的头节点指针，x - 要插入的值
 * 返回: 无
 * 说明: 新节点插入到链表末尾
 */
void ListPushBack(LNode* L, LDataType x);

/*
 * 函数: ListPopFront
 * 功能: 删除链表的第一个有效节点（头删）
 * 参数: L - 链表的头节点指针
 * 返回: 被删除节点的值
 * 说明: 链表不能为空，否则程序会断言失败
 */
LDataType ListPopFront(LNode* L);

/*
 * 函数: ListPopBack
 * 功能: 删除链表的最后一个有效节点（尾删）
 * 参数: L - 链表的头节点指针
 * 返回: 被删除节点的值
 * 说明: 链表不能为空，否则程序会断言失败
 */
LDataType ListPopBack(LNode* L);

/*
 * 函数: ListDestroy
 * 功能: 销毁链表，释放所有节点内存
 * 参数: L - 链表的头节点指针
 * 返回: 无
 * 注意: 调用后应将指针置为NULL，避免野指针
 *       本函数采用值传递，无法自动将调用者的指针置为NULL
 */
void ListDestroy(LNode* L);
