//剑指 Offer 42. 连续子数组的最大和

/*
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100


执行结果：
通过
显示详情
执行用时：
44 ms
, 在所有 C++ 提交中击败了
79.39%
的用户
内存消耗：
23.5 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
炫耀一下:
*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size(), maxnum = nums[0];
        vector<int> dp(size,0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(dp[i-1] > 0){
                dp[i] = dp[i-1] + nums[i];
            }
            else{
                dp[i] = nums[i];
            }
            maxnum = max(maxnum,dp[i]);
        }
        return maxnum;
    }
};



