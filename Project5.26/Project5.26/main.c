#define _CRT_SECURE_NO_WARNINGS

//力扣 189. 轮转数组
//
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

//void rotate(int* nums, int numsSize, int k)
//{
//    k %= numsSize;
//    while (k--)
//    {
//        int end = nums[numsSize - 1];
//
//        for (int i = numsSize - 1; i > 0; i--)
//        {
//            nums[i] = nums[i - 1];
//        }
//        nums[0] = end;
//    }
//}


//力扣 面试题 17.04.消失的数字
//int missingNumber(int* nums, int numsSize)
//{
//    int sum1 = numsSize * (numsSize + 1) / 2;
//    int sum2 = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        sum2 += nums[i];
//    }
//    return sum1 - sum2;
//}