//53. 最大子数组


/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

*/



//贪心算法
//记录当前最大和，和，之前和，之前和小于0，则摒弃

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }
        int i = 0, pre_sum = 0, max_sum = nums[0];
        while(i < nums.size()){
            pre_sum = pre_sum + nums[i];
            max_sum = max(max_sum,pre_sum);
            if(pre_sum < 0){
                pre_sum = 0;
            }
            i++;
        }
        return max_sum;
    }
};



