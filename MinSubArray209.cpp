//209. 长度最小的子数组

/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

 

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的连续子数组。
 

进阶：

如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

*/



//解法一，直接搜索每一个指标下的满足条件的连续子数组，求最小值就可以， On^2

/*
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i, j, size = nums.size(), sum = 0, minlen = size + 1;

        for(i = 0; i < size; i++){
            sum = 0;
            for(j = i; j < size; j++){
                sum += nums[j];
                if(sum >= s){
                    minlen = min(minlen,j - i + 1);
                    break;
                }
            }
        }
        return minlen == size + 1? 0 : minlen;
    }
};

*/


//双指针  On  O1
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, size = nums.size(), left = 0, right = 0, minlen = size + 1;
        if(size == 0) return 0;

        while(right < size){
            sum += nums[right];
            while(sum >= s){
                minlen = min(minlen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return minlen == size + 1? 0:minlen;
    }
};








