//643. 子数组最大平均数 I

/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

示例 1:

输入: [1,12,-5,-6,50,3], k = 4
输出: 12.75
解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

注意:

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i;
        double sum = 0.0, maxave;
        for(i = 0; i < k; i++){
            sum +=nums[i];
        }
        maxave = sum/k;
        for(i = 1; i < nums.size() - k + 1; i++){
            sum = sum - nums[i - 1] + nums[i + k - 1];
            maxave = max(maxave,sum/k);
        }
        return maxave;
    }
};





