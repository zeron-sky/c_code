/*
 * 文件: LinkList.c
 * 功能: 单链表（带头节点）的实现
 * 说明: 实现了链表的基本操作，包括增删查改等功能
 */

#include"LinkList.h"

/*
 * 函数: BuyListNode
 * 功能: 创建一个新的链表节点
 * 参数: data - 新节点存储的数据
 * 返回: 成功返回新节点地址，失败则退出程序
 */
LNode* BuyListNode(LDataType data)
{
	// 分配节点内存
	LNode* newnode = (LNode*)malloc(sizeof(LNode));
	
	// 内存分配失败处理
	if (newnode == NULL)
	{
		printf("内存分配失败\n");
		exit(-1);
	}

	// 初始化节点数据
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

/*
 * 函数: ListInit
 * 功能: 初始化链表，创建头节点
 * 参数: 无
 * 返回: 返回创建的头节点地址
 * 说明: 头节点的data字段存储无效值(-1)，不计入链表长度
 */
LNode* ListInit()
{
	// 创建头节点，data存储无效值
	LNode* node = BuyListNode(-1);
	return node;
}

/*
 * 函数: ListPrint
 * 功能: 打印链表中所有节点的数据
 * 参数: L - 链表的头节点指针
 * 返回: 无
 * 输出格式: Head->1->2->3->NULL
 */
void ListPrint(LNode* L)
{
	assert(L);  // 断言链表不为空
	
	printf("Head");  // 打印头节点标识

	// 从第一个有效节点开始遍历
	LNode* cur = L->next;
	
	// 遍历并打印每个节点的值
	while (cur)
	{
		printf("->%d", cur->data);
		cur = cur->next;
	}
	printf("->NULL\n");  // 打印结束标志并换行
}

/*
 * 函数: ListSize
 * 功能: 获取链表中有效节点的数量
 * 参数: L - 链表的头节点指针
 * 返回: 有效节点的数量（不包括头节点）
 */
int ListSize(LNode* L)
{
	assert(L);  // 断言链表不为空
	
	int size = 0;
	LNode* cur = L->next;  // 从第一个有效节点开始
	
	// 遍历计数
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

/*
 * 函数: ListLocateElem
 * 功能: 查找链表中第一个值为x的节点
 * 参数: L - 链表的头节点指针，x - 要查找的值
 * 返回: 找到返回节点地址，未找到返回NULL
 */
LNode* ListLocateElem(LNode* L, LDataType x)
{
	assert(L);  // 断言链表不为空
	
	LNode* cur = L->next;  // 从第一个有效节点开始
	
	// 遍历查找
	while (cur)
	{
		if (cur->data == x)
			return cur;  // 找到返回节点地址
		cur = cur->next;
	}
	return NULL;  // 未找到返回NULL
}

/*
 * 函数: ListElem
 * 功能: 获取链表中第i个位置的节点（从0开始计数）
 * 参数: L - 链表的头节点指针，i - 位置索引（从0开始）
 * 返回: 成功返回节点地址，位置无效返回NULL
 */
LNode* ListElem(LNode* L, int i)
{
	assert(L);      // 断言链表不为空
	assert(i >= 0); // 断言位置非负
	
	int j = 0;
	LNode* iNode = L->next;  // 从第一个有效节点开始
	
	// 遍历到第i个位置
	while (iNode && j < i)
	{
		j++;            // 累加计数器（修复：原代码缺少此行导致死循环）
		iNode = iNode->next;
	}
	
	return iNode;  // 返回节点地址，如果i超出范围则返回NULL
}

/*
 * 函数: ListInsert
 * 功能: 在链表的第i个位置插入新元素
 * 参数: L - 链表的头节点指针，i - 插入位置（从0开始），x - 要插入的值
 * 返回: 无
 * 说明: 插入后新元素成为第i个位置的节点
 * 算法: 找到第i-1个节点，在其后插入新节点
 */
void ListInsert(LNode* L, int i, LDataType x)
{
	assert(L);      // 断言链表不为空
	assert(i >= 0); // 断言位置非负

	// 找到第i-1个节点（i_1Node表示第i-1个节点）
	int j = -1;
	LNode* i_1Node = L;
	while(i_1Node && j < i - 1)
	{
		j++;
		i_1Node = i_1Node->next;
	}

	assert(i_1Node);  // 断言第i-1个节点存在
	
	// 创建新节点
	LNode* newNode = BuyListNode(x);

	// 将新节点插入到第i-1个节点之后
	newNode->next = i_1Node->next;
	i_1Node->next = newNode;
}

/*
 * 函数: ListPDelete
 * 功能: 删除链表中第i个位置的节点
 * 参数: L - 链表的头节点指针，i - 要删除的位置（从0开始）
 * 返回: 被删除节点的值
 * 说明: 位置i必须有效，否则程序会断言失败
 * 算法: 找到第i-1个节点，删除其后的第i个节点
 */
LDataType ListPDelete(LNode* L, int i)
{
	assert(L);      // 断言链表不为空
	assert(i >= 0); // 断言位置非负

	// 找到第i-1个节点
	LNode* i_1Node = L;
	int j = -1;
	while (i_1Node && j < i - 1)
	{
		j++;
		i_1Node = i_1Node->next;
	}

	// 如果没有第i-1个位置和第i个位置，说明位置i非法
	assert(i_1Node && i_1Node->next);

	// 删除第i个节点
	LNode* iNode = i_1Node->next;  // 保存第i个节点
	i_1Node->next = iNode->next;   // 第i-1个节点指向第i+1个节点
	
	// 保存被删除节点的值并释放内存
	LDataType x = iNode->data;
	free(iNode);
	iNode = NULL;
	
	return x;
}

/*
 * 函数: ListDestroy
 * 功能: 销毁链表，释放所有节点内存
 * 参数: L - 链表的头节点指针
 * 返回: 无
 * 注意: 调用后应将指针置为NULL，避免野指针
 *       本函数采用值传递，无法自动将调用者的指针置为NULL
 */
void ListDestroy(LNode* L)
{
	assert(L);  // 断言链表不为空
	
	// 从第一个有效节点开始释放
	LNode* cur = L->next;
	while (cur)
	{
		LNode* next = cur->next;  // 保存下一个节点地址
		free(cur);                // 释放当前节点
		cur = next;               // 移动到下一个节点
	}
	
	// 释放头节点
	free(L);
	// 注意：L = NULL 只修改了局部变量，调用者需手动置NULL
}

/*
 * 函数: ListEmpty
 * 功能: 判断链表是否为空
 * 参数: L - 链表的头节点指针
 * 返回: 链表为空返回true，否则返回false
 */
bool ListEmpty(LNode* L)
{
	assert(L);  // 断言链表不为空
	
	// 如果头节点的next为NULL，则链表为空
	return L->next == NULL;
}

/*
 * 函数: ListPushFront
 * 功能: 在链表头部插入新节点（头插法）
 * 参数: L - 链表的头节点指针，x - 要插入的值
 * 返回: 无
 * 说明: 新节点插入到头节点之后，成为第一个有效节点
 * 算法: 新节点指向原第一个节点，头节点指向新节点
 */
void ListPushFront(LNode* L, LDataType x)
{
	assert(L);  // 断言链表不为空
	
	// 创建新节点
	LNode* newNode = BuyListNode(x);
	
	// 新节点指向原第一个有效节点
	newNode->next = L->next;
	
	// 头节点指向新节点
	L->next = newNode;
}

/*
 * 函数: ListPushBack
 * 功能: 在链表尾部插入新节点（尾插法）
 * 参数: L - 链表的头节点指针，x - 要插入的值
 * 返回: 无
 * 说明: 新节点插入到链表末尾
 * 算法: 遍历找到最后一个节点，将其next指向新节点
 */
void ListPushBack(LNode* L, LDataType x)
{
	assert(L);  // 断言链表不为空
	
	// 创建新节点
	LNode* newNode = BuyListNode(x);
	
	// 找到最后一个节点
	LNode* tail = L;
	while (tail->next)
	{
		tail = tail->next;
	}
	
	// 最后一个节点指向新节点
	tail->next = newNode;
}

/*
 * 函数: ListPopFront
 * 功能: 删除链表的第一个有效节点（头删）
 * 参数: L - 链表的头节点指针
 * 返回: 被删除节点的值
 * 说明: 链表不能为空，否则程序会断言失败
 * 算法: 保存第一个节点，修改头节点指向，释放被删节点
 */
LDataType ListPopFront(LNode* L)
{
	assert(L);       // 断言链表不为空
	assert(L->next); // 断言链表有有效节点（非空链表）
	
	// 保存第一个有效节点
	LNode* first = L->next;
	
	// 头节点指向第二个节点
	L->next = first->next;
	
	// 保存被删除节点的值
	LDataType x = first->data;
	
	// 释放被删除节点
	free(first);
	first = NULL;
	
	return x;
}

/*
 * 函数: ListPopBack
 * 功能: 删除链表的最后一个有效节点（尾删）
 * 参数: L - 链表的头节点指针
 * 返回: 被删除节点的值
 * 说明: 链表不能为空，否则程序会断言失败
 * 算法: 遍历找到最后一个节点及其前驱，释放被删节点并修改指针
 */
LDataType ListPopBack(LNode* L)
{
	assert(L);       // 断言链表不为空
	assert(L->next); // 断言链表有有效节点（非空链表）
	
	LNode* tail = L;      // 当前遍历的节点
	LNode* prev = NULL;   // 当前节点的前驱节点
	
	// 遍历找到最后一个节点和它的前驱节点
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	
	// 保存被删除节点的值
	LDataType x = tail->data;
	
	// 处理删除后的指针连接
	if (prev == NULL)
	{
		// 只有一个有效节点，删除后链表为空
		L->next = NULL;
	}
	else
	{
		// 前驱节点指向NULL（成为新的末尾）
		prev->next = NULL;
	}
	
	// 释放被删除节点
	free(tail);
	tail = NULL;
	
	return x;
}
