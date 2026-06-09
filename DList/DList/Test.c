#include "DList.h"

/* 统计链表中数据节点的数量（不含头结点） */
static int ListSize(DCListNode* L)
{
	int size = 0;
	DCListNode* cur = L->next;

	while (cur != L)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

/* 校验链表是否为空（头结点前驱和后继都指向自身） */
static void CheckEmptyList(DCListNode* L)
{
	assert(L != NULL);
	assert(L->next == L);
	assert(L->prev == L);
	assert(ListSize(L) == 0);
}

/* 按顺序校验链表中的每个数据节点 */
static void CheckListOrder(DCListNode* L, const int* expected, int size)
{
	int i = 0;
	DCListNode* cur = L->next;

	while (cur != L)
	{
		assert(i < size);
		assert(cur->data == expected[i]);
		cur = cur->next;
		++i;
	}

	assert(i == size);
	assert(ListSize(L) == size);
}

/* 校验链表的双向链接结构是否正确 */
static void CheckListLinks(DCListNode* L)
{
	assert(L != NULL);

	DCListNode* cur = L->next;
	DCListNode* prev = L;

	while (cur != L)
	{
		assert(cur->prev == prev);
		assert(prev->next == cur);
		prev = cur;
		cur = cur->next;
	}

	/* 最后一个节点的后继应指向头结点，头结点的前驱应指向最后一个节点 */
	assert(prev->next == L);
	assert(L->prev == prev);
}

/* 打印期望数组 */
static void PrintExpectedList(const int* expected, int size)
{
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		printf("%d", expected[i]);
		if (i < size - 1)
		{
			printf(" <-> ");
		}
	}
	printf("\n");
}

/* 测试节点申请接口 */
static void TestBuyDCList(void)
{
	DCListNode* node = NULL;

	printf("[1] 测试节点申请接口 BuyDCList...\n");

	node = BuyDCList(42);
	assert(node != NULL);
	assert(node->data == 42);
	assert(node->next == NULL);
	assert(node->prev == NULL);

	free(node);
	printf("节点申请接口测试通过。\n\n");
}

/* 测试初始化接口 */
static void TestInit(void)
{
	DCListNode* L = NULL;

	printf("[2] 测试初始化接口 DCListInit...\n");

	L = DCListInit();
	assert(L != NULL);
	assert(L->data == -1);
	CheckEmptyList(L);
	CheckListLinks(L);

	DCListDestroy(L);
	printf("初始化接口测试通过。\n\n");
}

/* 测试头插接口 */
static void TestPushFront(void)
{
	int expected[] = { 3, 2, 1 };
	DCListNode* L = DCListInit();

	printf("[3] 测试头插接口 DCListPushFront...\n");

	DCListPushFront(L, 1);
	DCListPushFront(L, 2);
	DCListPushFront(L, 3);

	printf("期望结果：");
	PrintExpectedList(expected, sizeof(expected) / sizeof(expected[0]));
	printf("实际结果：");
	DCListPrint(L);

	CheckListOrder(L, expected, sizeof(expected) / sizeof(expected[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("头插接口测试通过。\n\n");
}

/* 测试尾插接口 */
static void TestPushBack(void)
{
	int expected[] = { 1, 2, 3 };
	DCListNode* L = DCListInit();

	printf("[4] 测试尾插接口 DCListPushBack...\n");

	DCListPushBack(L, 1);
	DCListPushBack(L, 2);
	DCListPushBack(L, 3);

	printf("期望结果：");
	PrintExpectedList(expected, sizeof(expected) / sizeof(expected[0]));
	printf("实际结果：");
	DCListPrint(L);

	CheckListOrder(L, expected, sizeof(expected) / sizeof(expected[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("尾插接口测试通过。\n\n");
}

/* 测试按位置查找接口 */
static void TestGetElem(void)
{
	DCListNode* L = DCListInit();
	DCListNode* node = NULL;

	printf("[5] 测试按位置查找接口 DCListGetElem...\n");

	DCListPushBack(L, 10);
	DCListPushBack(L, 20);
	DCListPushBack(L, 30);

	/* 测试正常查找 */
	node = DCListGetElem(L, 0);
	assert(node != NULL && node->data == 10);

	node = DCListGetElem(L, 1);
	assert(node != NULL && node->data == 20);

	node = DCListGetElem(L, 2);
	assert(node != NULL && node->data == 30);

	/* 测试越界查找 */
	node = DCListGetElem(L, 3);
	assert(node == NULL);

	node = DCListGetElem(L, 100);
	assert(node == NULL);

	/* 测试空链表查找 */
	{
		DCListNode* empty = DCListInit();
		node = DCListGetElem(empty, 0);
		assert(node == NULL);
		DCListDestroy(empty);
	}

	DCListDestroy(L);
	printf("按位置查找接口测试通过。\n\n");
}

/* 测试在指定位置之后插入接口 */
static void TestInsert(void)
{
	int expected_before[] = { 1, 2, 3 };
	int expected_after[] = { 1, 2, 99, 3 };
	DCListNode* L = DCListInit();
	DCListNode* pos = NULL;

	printf("[6] 测试指定位置后插入接口 DCListInsert...\n");

	DCListPushBack(L, 1);
	DCListPushBack(L, 2);
	DCListPushBack(L, 3);

	printf("插入前期望：");
	PrintExpectedList(expected_before, sizeof(expected_before) / sizeof(expected_before[0]));
	CheckListOrder(L, expected_before, sizeof(expected_before) / sizeof(expected_before[0]));

	/* 在值为 2 的节点后插入 99 */
	pos = DCListGetElem(L, 1);
	assert(pos != NULL);
	DCListInsert(pos, 99);

	printf("插入后期望：");
	PrintExpectedList(expected_after, sizeof(expected_after) / sizeof(expected_after[0]));
	printf("实际结果：    ");
	DCListPrint(L);

	CheckListOrder(L, expected_after, sizeof(expected_after) / sizeof(expected_after[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("指定位置后插入接口测试通过。\n\n");
}

/* 测试删除指定节点接口 */
static void TestDelete(void)
{
	int expected_before[] = { 1, 2, 3 };
	int expected_after[] = { 1, 3 };
	DCListNode* L = DCListInit();
	DCListNode* node = NULL;

	printf("[7] 测试删除指定节点接口 DCListDelete...\n");

	DCListPushBack(L, 1);
	DCListPushBack(L, 2);
	DCListPushBack(L, 3);

	printf("删除前期望：");
	PrintExpectedList(expected_before, sizeof(expected_before) / sizeof(expected_before[0]));
	CheckListOrder(L, expected_before, sizeof(expected_before) / sizeof(expected_before[0]));

	/* 删除值为 2 的节点 */
	node = DCListGetElem(L, 1);
	assert(node != NULL);
	DCListDelete(node);

	printf("删除后期望：");
	PrintExpectedList(expected_after, sizeof(expected_after) / sizeof(expected_after[0]));
	printf("实际结果：    ");
	DCListPrint(L);

	CheckListOrder(L, expected_after, sizeof(expected_after) / sizeof(expected_after[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("删除指定节点接口测试通过。\n\n");
}

/* 测试头删接口 */
static void TestPopFront(void)
{
	int expected[] = { 2, 3 };
	DCListNode* L = DCListInit();

	printf("[8] 测试头删接口 DCListPopFront...\n");

	DCListPushBack(L, 1);
	DCListPushBack(L, 2);
	DCListPushBack(L, 3);

	DCListPopFront(L);

	printf("期望结果：");
	PrintExpectedList(expected, sizeof(expected) / sizeof(expected[0]));
	printf("实际结果：");
	DCListPrint(L);

	CheckListOrder(L, expected, sizeof(expected) / sizeof(expected[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("头删接口测试通过。\n\n");
}

/* 测试尾删接口 */
static void TestPopBack(void)
{
	int expected[] = { 1, 2 };
	DCListNode* L = DCListInit();

	printf("[9] 测试尾删接口 DCListPopBack...\n");

	DCListPushBack(L, 1);
	DCListPushBack(L, 2);
	DCListPushBack(L, 3);

	DCListPopBack(L);

	printf("期望结果：");
	PrintExpectedList(expected, sizeof(expected) / sizeof(expected[0]));
	printf("实际结果：");
	DCListPrint(L);

	CheckListOrder(L, expected, sizeof(expected) / sizeof(expected[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("尾删接口测试通过。\n\n");
}

/* 测试空链表删除不会误删头结点 */
static void TestEmptyPop(void)
{
	DCListNode* L = DCListInit();

	printf("[10] 测试空链表删除操作...\n");

	DCListPopFront(L);
	CheckEmptyList(L);

	DCListPopBack(L);
	CheckEmptyList(L);

	printf("期望结果：(空)\n");
	printf("实际结果：");
	DCListPrint(L);

	DCListDestroy(L);
	printf("空链表删除测试通过。\n\n");
}

/* 测试打印接口 */
static void TestPrint(void)
{
	int expected[] = { 1, 2, 3 };
	DCListNode* L = DCListInit();

	printf("[11] 测试打印接口 DCListPrint...\n");

	DCListPushBack(L, 1);
	DCListPushBack(L, 2);
	DCListPushBack(L, 3);

	printf("期望结果：");
	PrintExpectedList(expected, sizeof(expected) / sizeof(expected[0]));
	printf("实际结果：");
	DCListPrint(L);

	/* 测试空链表打印 */
	{
		DCListNode* empty = DCListInit();
		printf("空链表期望输出：(换行)\n");
		printf("空链表实际输出：");
		DCListPrint(empty);
		DCListDestroy(empty);
	}

	DCListDestroy(L);
	printf("打印接口测试通过。\n\n");
}

/* 测试销毁接口 */
static void TestDestroy(void)
{
	DCListNode* L = DCListInit();

	printf("[12] 测试销毁接口 DCListDestroy...\n");

	DCListPushBack(L, 10);
	DCListPushBack(L, 20);
	DCListPushBack(L, 30);

	DCListDestroy(L);
	printf("销毁接口测试通过。\n\n");
}

/* 综合测试：混合操作验证 */
static void TestMixedOperations(void)
{
	int expected[] = { 10, 50, 30 };
	DCListNode* L = DCListInit();
	DCListNode* node = NULL;

	printf("[13] 测试综合操作...\n");

	/* 头插 10 */
	DCListPushFront(L, 10);
	/* 尾插 30 */
	DCListPushBack(L, 30);
	/* 在 10 后面插入 20 */
	node = DCListGetElem(L, 0);
	assert(node != NULL);
	DCListInsert(node, 20);
	/* 在 20 后面插入 50 */
	node = DCListGetElem(L, 1);
	assert(node != NULL);
	DCListInsert(node, 50);
	/* 删除 20 */
	node = DCListGetElem(L, 1);
	assert(node != NULL);
	DCListDelete(node);

	printf("期望结果：");
	PrintExpectedList(expected, sizeof(expected) / sizeof(expected[0]));
	printf("实际结果：");
	DCListPrint(L);

	CheckListOrder(L, expected, sizeof(expected) / sizeof(expected[0]));
	CheckListLinks(L);

	DCListDestroy(L);
	printf("综合操作测试通过。\n\n");
}

int main(void)
{
	printf("开始测试双向循环链表...\n\n");

	TestBuyDCList();
	TestInit();
	TestPushFront();
	TestPushBack();
	TestGetElem();
	TestInsert();
	TestDelete();
	TestPopFront();
	TestPopBack();
	TestEmptyPop();
	TestPrint();
	TestDestroy();
	TestMixedOperations();

	printf("所有手写测试全部通过！\n");
	return 0;
}
