#include "DList.h"

// 申请一个新节点。
DCListNode* BuyDCList(DCLDataType data)
{
	DCListNode* L = (DCListNode*)malloc(sizeof(DCListNode));

	if (L == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}

	L->data = data;
	L->next = NULL;
	L->prev = NULL;

	return L;
}

// 初始化带哨兵位的头节点。
DCListNode* DCListInit()
{
	DCListNode* L = BuyDCList(-1);
	L->prev = L;
	L->next = L;

	return L;
}

// 销毁整个链表。
void DCListDestroy(DCListNode* L)
{
	assert(L);

	DCListNode* cur = L->next;

	// 先保存下一个节点，再释放当前节点。
	while (cur != L)
	{
		DCListNode* next = cur->next;

		free(cur);
		cur = next;
	}

	free(L);
}

// 获取下标为 i 的节点。
DCListNode* DCListGetElem(DCListNode* L, int i)
{
	assert(L);
	assert(i >= 0);

	DCListNode* cur = L->next;
	int j = 0;

	while (cur != L && j < i)
	{
		cur = cur->next;
		++j;
	}

	if (cur == L)
	{
		return NULL;
	}

	return cur;
}

// 在 pos 后插入 x。
void DCListInsert(DCListNode* pos, DCLDataType x)
{
	assert(pos);

	DCListNode* newnode = BuyDCList(x);

	newnode->next = pos->next;
	pos->next->prev = newnode;
	pos->next = newnode;
	newnode->prev = pos;
}

// 头插。
void DCListPushFront(DCListNode* L, DCLDataType x)
{
	assert(L);
	assert(L->next);

	DCListInsert(L, x);
}

// 尾插。
void DCListPushBack(DCListNode* L, DCLDataType x)
{
	assert(L);
	assert(L->next);

	DCListInsert(L->prev, x);
}

// 删除 pos 节点。
void DCListDelete(DCListNode* pos)
{
	assert(pos);

	// 哨兵头节点不能当作普通数据节点删除。
	assert(pos->next != pos);

	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;

	free(pos);
}

// 头删。
void DCListPopFront(DCListNode* L)
{
	assert(L);

	if (L->next == L)
	{
		return;
	}

	DCListDelete(L->next);
}

// 尾删。
void DCListPopBack(DCListNode* L)
{
	assert(L);

	if (L->prev == L)
	{
		return;
	}

	DCListDelete(L->prev);
}

// 打印所有数据节点。
void DCListPrint(DCListNode* L)
{
	assert(L);

	DCListNode* cur = L->next;

	while (cur != L)
	{
		printf("%d", cur->data);
		cur = cur->next;
		if (cur != L)
		{
			printf(" <-> ");
		}
	}

	printf("\n");
}
