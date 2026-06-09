#include <vector>
#include <string>

#include <gtest/gtest.h>

extern "C" {
#include "..\DList.h"
}

namespace {

int ListSize(DCListNode* list)
{
    int size = 0;
    DCListNode* cur = list->next;

    while (cur != list)
    {
        ++size;
        cur = cur->next;
    }

    return size;
}

// 统一校验空链表的哨兵节点状态，避免每个测试重复写相同断言。
void ExpectEmptyList(DCListNode* list)
{
    ASSERT_NE(list, nullptr);
    EXPECT_EQ(list->next, list);
    EXPECT_EQ(list->prev, list);
    EXPECT_EQ(ListSize(list), 0);
}

// 顺序遍历并同时校验前驱/后继关系，确保双向循环链表结构完整。
void ExpectListValues(DCListNode* list, const std::vector<int>& expected)
{
    ASSERT_NE(list, nullptr);

    DCListNode* cur = list->next;
    DCListNode* prev = list;
    size_t index = 0;

    while (cur != list)
    {
        ASSERT_LT(index, expected.size());
        EXPECT_EQ(cur->data, expected[index]);
        EXPECT_EQ(cur->prev, prev);
        EXPECT_EQ(prev->next, cur);

        prev = cur;
        cur = cur->next;
        ++index;
    }

    EXPECT_EQ(index, expected.size());
    EXPECT_EQ(list->prev, prev);
    EXPECT_EQ(prev->next, list);
    EXPECT_EQ(ListSize(list), static_cast<int>(expected.size()));
}

class DCListTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        list_ = DCListInit();
    }

    void TearDown() override
    {
        if (list_ != nullptr)
        {
            DCListDestroy(list_);
            list_ = nullptr;
        }
    }

    void FillWith(const std::vector<int>& values)
    {
        for (int value : values)
        {
            DCListPushBack(list_, value);
        }
    }

    DCListNode* list_ = nullptr;
};

TEST(BuyDCListTest, CreatesSingleDetachedNode)
{
    // 单独验证节点申请接口，确保新节点数据和初始链接状态都正确。
    DCListNode* node = BuyDCList(42);

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(node->data, 42);
    EXPECT_EQ(node->next, nullptr);
    EXPECT_EQ(node->prev, nullptr);

    free(node);
}

TEST(DCListInitTest, CreatesEmptyCircularList)
{
    DCListNode* list = DCListInit();

    ExpectEmptyList(list);

    DCListDestroy(list);
}

TEST_F(DCListTest, PushFrontInsertsValuesAtHead)
{
    DCListPushFront(list_, 3);
    DCListPushFront(list_, 2);
    DCListPushFront(list_, 1);

    ExpectListValues(list_, { 1, 2, 3 });
}

TEST_F(DCListTest, PushBackInsertsValuesAtTail)
{
    DCListPushBack(list_, 1);
    DCListPushBack(list_, 2);
    DCListPushBack(list_, 3);

    ExpectListValues(list_, { 1, 2, 3 });
    EXPECT_EQ(list_->prev->data, 3);
}

TEST_F(DCListTest, GetElemReturnsNodeAtZeroBasedIndex)
{
    FillWith({ 10, 20, 30 });

    ASSERT_NE(DCListGetElem(list_, 0), nullptr);
    EXPECT_EQ(DCListGetElem(list_, 0)->data, 10);
    ASSERT_NE(DCListGetElem(list_, 1), nullptr);
    EXPECT_EQ(DCListGetElem(list_, 1)->data, 20);
    ASSERT_NE(DCListGetElem(list_, 2), nullptr);
    EXPECT_EQ(DCListGetElem(list_, 2)->data, 30);
}

TEST_F(DCListTest, GetElemReturnsNullForOutOfRangeIndex)
{
    FillWith({ 10, 20 });

    EXPECT_EQ(DCListGetElem(list_, 2), nullptr);
    EXPECT_EQ(DCListGetElem(list_, 100), nullptr);
}

TEST_F(DCListTest, GetElemReturnsNullForEmptyList)
{
    ExpectEmptyList(list_);
    EXPECT_EQ(DCListGetElem(list_, 0), nullptr);
}

TEST_F(DCListTest, InsertAddsNodeAfterSpecifiedPosition)
{
    FillWith({ 1, 2, 4 });

    DCListNode* pos = DCListGetElem(list_, 1);
    ASSERT_NE(pos, nullptr);

    DCListInsert(pos, 3);

    ExpectListValues(list_, { 1, 2, 3, 4 });
}

TEST_F(DCListTest, DeleteRemovesSpecifiedNode)
{
    FillWith({ 1, 2, 3 });

    DCListNode* node = DCListGetElem(list_, 1);
    ASSERT_NE(node, nullptr);

    DCListDelete(node);

    ExpectListValues(list_, { 1, 3 });
}

TEST_F(DCListTest, PopFrontRemovesFirstNode)
{
    FillWith({ 1, 2, 3 });

    DCListPopFront(list_);

    ExpectListValues(list_, { 2, 3 });
}

TEST_F(DCListTest, PopBackRemovesLastNode)
{
    FillWith({ 1, 2, 3 });

    DCListPopBack(list_);

    ExpectListValues(list_, { 1, 2 });
}

TEST_F(DCListTest, EmptyPopOperationsKeepSentinelNodeValid)
{
    // 这个边界用例用于防止空链表删除时误把头结点当成数据节点释放。
    DCListPopFront(list_);
    DCListPopBack(list_);

    ExpectEmptyList(list_);
}

TEST_F(DCListTest, DestroyHandlesNonEmptyListWithoutFatalFailure)
{
    FillWith({ 10, 20, 30, 40 });

    EXPECT_NO_FATAL_FAILURE(DCListDestroy(list_));
    list_ = nullptr;
}

TEST_F(DCListTest, PrintOutputsValuesInOrder)
{
    FillWith({ 1, 2, 3 });

    testing::internal::CaptureStdout();
    DCListPrint(list_);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 <-> 2 <-> 3\n");
}

TEST_F(DCListTest, PrintOutputsOnlyNewlineForEmptyList)
{
    testing::internal::CaptureStdout();
    DCListPrint(list_);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "\n");
}

} // namespace
