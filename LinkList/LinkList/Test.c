/*
 * 文件: Test.c
 * 功能: 单链表功能测试程序
 * 说明: 自动运行所有测试函数，验证链表各项功能的正确性
 * 包含测试:
 *   - TestInit: 测试初始化和销毁
 *   - TestPushFront: 测试头插功能
 *   - TestPushBack: 测试尾插功能
 *   - TestPopFront: 测试头删功能
 *   - TestPopBack: 测试尾删功能
 *   - TestInsert: 测试指定位置插入
 *   - TestDelete: 测试指定位置删除
 *   - TestLocate: 测试查找功能
 *   - TestSize: 测试获取大小
 *   - TestMixed: 测试混合操作
 */

#include"LinkList.h"

/*
 * 函数: TestInit
 * 功能: 测试链表初始化和销毁功能
 * 测试点:
 *   - ListInit是否能成功创建头节点
 *   - 空链表的大小是否为0
 *   - 空链表是否返回为空
 *   - ListDestroy是否能成功销毁链表
 */
void TestInit()
{
	printf("===== 测试初始化 =====\n");
	
	// 初始化链表
	LNode* list = ListInit();
	printf("初始化成功，");
	
	// 测试打印空链表
	ListPrint(list);
	
	// 测试空链表大小
	printf("链表大小: %d\n", ListSize(list));
	
	// 测试空链表判断
	printf("是否为空: %s\n", ListEmpty(list) ? "是" : "否");
	
	// 销毁链表
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestPushFront
 * 功能: 测试头插功能（ListPushFront）
 * 测试点:
 *   - 多次头插后链表顺序是否正确（后插入的在前面）
 *   - 插入后链表大小是否正确
 * 预期结果: 链表顺序为 5->4->3->2->1
 */
void TestPushFront()
{
	printf("===== 测试头插 =====\n");
	LNode* list = ListInit();
	
	// 头插多个元素（顺序: 1, 2, 3, 4, 5）
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 4);
	ListPushFront(list, 5);
	
	// 预期输出: Head->5->4->3->2->1->NULL
	printf("头插5,4,3,2,1后: ");
	ListPrint(list);
	
	// 预期大小: 5
	printf("链表大小: %d\n", ListSize(list));
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestPushBack
 * 功能: 测试尾插功能（ListPushBack）
 * 测试点:
 *   - 多次尾插后链表顺序是否正确（保持插入顺序）
 *   - 插入后链表大小是否正确
 * 预期结果: 链表顺序为 1->2->3->4->5
 */
void TestPushBack()
{
	printf("===== 测试尾插 =====\n");
	LNode* list = ListInit();
	
	// 尾插多个元素（顺序: 1, 2, 3, 4, 5）
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	
	// 预期输出: Head->1->2->3->4->5->NULL
	printf("尾插1,2,3,4,5后: ");
	ListPrint(list);
	
	// 预期大小: 5
	printf("链表大小: %d\n", ListSize(list));
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestPopFront
 * 功能: 测试头删功能（ListPopFront）
 * 测试点:
 *   - 头删是否返回正确的值
 *   - 头删后链表是否正确更新
 *   - 删除所有节点后链表是否为空
 * 预期结果: 依次删除 1, 2, 3
 */
void TestPopFront()
{
	printf("===== 测试头删 =====\n");
	LNode* list = ListInit();
	
	// 先插入一些元素: 1->2->3
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	
	printf("初始链表: ");
	ListPrint(list);
	
	// 第一次头删: 删除1
	LDataType val = ListPopFront(list);
	printf("头删元素: %d\n", val);
	printf("删除后: ");
	ListPrint(list);
	
	// 第二次头删: 删除2
	val = ListPopFront(list);
	printf("头删元素: %d\n", val);
	printf("删除后: ");
	ListPrint(list);
	
	// 第三次头删: 删除3
	val = ListPopFront(list);
	printf("头删元素: %d\n", val);
	printf("删除后: ");
	ListPrint(list);
	
	// 预期为空
	printf("是否为空: %s\n", ListEmpty(list) ? "是" : "否");
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestPopBack
 * 功能: 测试尾删功能（ListPopBack）
 * 测试点:
 *   - 尾删是否返回正确的值
 *   - 尾删后链表是否正确更新
 *   - 删除所有节点后链表是否为空
 * 预期结果: 依次删除 3, 2, 1
 */
void TestPopBack()
{
	printf("===== 测试尾删 =====\n");
	LNode* list = ListInit();
	
	// 先插入一些元素: 1->2->3
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	
	printf("初始链表: ");
	ListPrint(list);
	
	// 第一次尾删: 删除3
	LDataType val = ListPopBack(list);
	printf("尾删元素: %d\n", val);
	printf("删除后: ");
	ListPrint(list);
	
	// 第二次尾删: 删除2
	val = ListPopBack(list);
	printf("尾删元素: %d\n", val);
	printf("删除后: ");
	ListPrint(list);
	
	// 第三次尾删: 删除1
	val = ListPopBack(list);
	printf("尾删元素: %d\n", val);
	printf("删除后: ");
	ListPrint(list);
	
	// 预期为空
	printf("是否为空: %s\n", ListEmpty(list) ? "是" : "否");
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestInsert
 * 功能: 测试指定位置插入功能（ListInsert）
 * 测试点:
 *   - 在位置0插入（相当于头插）
 *   - 在中间位置插入
 *   - 在末尾插入
 *   - 插入后链表顺序是否正确
 */
void TestInsert()
{
	printf("===== 测试指定位置插入 =====\n");
	LNode* list = ListInit();
	
	// 在位置0插入10: 10
	ListInsert(list, 0, 10);
	// 在位置1插入20: 10->20
	ListInsert(list, 1, 20);
	// 在位置2插入30: 10->20->30
	ListInsert(list, 2, 30);
	printf("依次在位置0,1,2插入10,20,30: ");
	ListPrint(list);
	
	// 在位置1插入15: 10->15->20->30
	ListInsert(list, 1, 15);
	printf("在位置1插入15: ");
	ListPrint(list);
	
	// 在位置4插入40: 10->15->20->30->40
	ListInsert(list, 4, 40);
	printf("在位置4插入40: ");
	ListPrint(list);
	
	// 预期大小: 5
	printf("链表大小: %d\n", ListSize(list));
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestDelete
 * 功能: 测试指定位置删除功能（ListPDelete）
 * 测试点:
 *   - 删除第一个节点（位置0）
 *   - 删除中间节点
 *   - 删除最后一个节点
 *   - 删除后链表是否正确更新
 */
void TestDelete()
{
	printf("===== 测试指定位置删除 =====\n");
	LNode* list = ListInit();
	
	// 先插入一些元素: 10->20->30->40->50
	ListPushBack(list, 10);
	ListPushBack(list, 20);
	ListPushBack(list, 30);
	ListPushBack(list, 40);
	ListPushBack(list, 50);
	
	printf("初始链表: ");
	ListPrint(list);
	
	// 删除位置0（第一个）: 删除10，剩余 20->30->40->50
	LDataType val = ListPDelete(list, 0);
	printf("删除位置0的元素: %d, 删除后: ", val);
	ListPrint(list);
	
	// 删除位置1（中间）: 删除30，剩余 20->40->50
	val = ListPDelete(list, 1);
	printf("删除位置1的元素: %d, 删除后: ", val);
	ListPrint(list);
	
	// 删除位置2（最后一个）: 删除50，剩余 20->40
	val = ListPDelete(list, 2);
	printf("删除位置2的元素: %d, 删除后: ", val);
	ListPrint(list);
	
	// 预期大小: 2
	printf("链表大小: %d\n", ListSize(list));
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestLocate
 * 功能: 测试查找功能（ListLocateElem 和 ListElem）
 * 测试点:
 *   - 查找存在的元素
 *   - 查找不存在的元素
 *   - 获取指定位置的元素
 */
void TestLocate()
{
	printf("===== 测试查找元素 =====\n");
	LNode* list = ListInit();
	
	// 插入一些元素: 10->20->30->40->50
	ListPushBack(list, 10);
	ListPushBack(list, 20);
	ListPushBack(list, 30);
	ListPushBack(list, 40);
	ListPushBack(list, 50);
	
	printf("链表: ");
	ListPrint(list);
	
	// 查找存在的元素30
	LNode* pos = ListLocateElem(list, 30);
	if (pos)
	{
		printf("找到元素30，地址: %p，值: %d\n", (void*)pos, pos->data);
	}
	
	// 查找不存在的元素99
	pos = ListLocateElem(list, 99);
	if (pos == NULL)
	{
		printf("未找到元素99\n");
	}
	
	// 获取位置2的元素（预期: 30）
	LNode* node = ListElem(list, 2);
	if (node)
	{
		printf("位置2的元素值: %d\n", node->data);
	}
	
	// 获取位置0的元素（预期: 10）
	node = ListElem(list, 0);
	if (node)
	{
		printf("位置0的元素值: %d\n", node->data);
	}
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestSize
 * 功能: 测试获取大小功能（ListSize）
 * 测试点:
 *   - 空链表大小
 *   - 插入后大小变化
 *   - 删除后大小变化
 */
void TestSize()
{
	printf("===== 测试获取大小 =====\n");
	LNode* list = ListInit();
	
	// 空链表大小: 0
	printf("空链表大小: %d\n", ListSize(list));
	
	// 插入1个元素后大小: 1
	ListPushBack(list, 1);
	printf("插入1个元素后大小: %d\n", ListSize(list));
	
	// 再插入2个元素后大小: 3
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	printf("插入3个元素后大小: %d\n", ListSize(list));
	
	// 头删1个元素后大小: 2
	ListPopFront(list);
	printf("头删1个元素后大小: %d\n", ListSize(list));
	
	// 尾删1个元素后大小: 1
	ListPopBack(list);
	printf("尾删1个元素后大小: %d\n", ListSize(list));
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: TestMixed
 * 功能: 测试混合操作
 * 测试点:
 *   - 头插和尾插混合使用
 *   - 头删和尾删混合使用
 *   - 指定位置插入和删除混合使用
 *   - 各种操作后链表状态是否正确
 */
void TestMixed()
{
	printf("===== 测试混合操作 =====\n");
	LNode* list = ListInit();
	
	// 头插和尾插混合
	ListPushFront(list, 2);  // 2
	ListPushFront(list, 1);  // 1->2
	ListPushBack(list, 3);   // 1->2->3
	ListPushBack(list, 4);   // 1->2->3->4
	printf("头插2,1 尾插3,4: ");
	ListPrint(list);
	
	// 头删和尾删混合
	LDataType val1 = ListPopFront(list);  // 删除1，剩余 2->3->4
	LDataType val2 = ListPopBack(list);   // 删除4，剩余 2->3
	printf("头删: %d, 尾删: %d\n", val1, val2);
	printf("剩余: ");
	ListPrint(list);
	
	// 指定位置插入
	ListInsert(list, 1, 10);  // 2->10->3
	printf("在位置1插入10: ");
	ListPrint(list);
	
	// 指定位置删除
	val1 = ListPDelete(list, 1);  // 删除10，剩余 2->3
	printf("删除位置1的元素: %d, 剩余: ", val1);
	ListPrint(list);
	
	ListDestroy(list);
	printf("销毁成功\n\n");
}

/*
 * 函数: main
 * 功能: 程序入口，运行所有测试函数
 * 返回: 0表示程序正常结束
 */
int main()
{
	printf("========================================\n");
	printf("       单链表功能测试程序\n");
	printf("========================================\n\n");
	
	// 依次运行所有测试函数
	TestInit();      // 测试初始化
	TestPushFront(); // 测试头插
	TestPushBack();  // 测试尾插
	TestPopFront();  // 测试头删
	TestPopBack();   // 测试尾删
	TestInsert();    // 测试指定位置插入
	TestDelete();    // 测试指定位置删除
	TestLocate();    // 测试查找
	TestSize();      // 测试获取大小
	TestMixed();     // 测试混合操作
	
	printf("========================================\n");
	printf("       所有测试完成！\n");
	printf("========================================\n");
	
	return 0;
}
