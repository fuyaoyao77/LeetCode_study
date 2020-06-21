//581.最短无序连续子数组


/*
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

你找到的子数组应是最短的，请输出它的长度。

示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> A = nums;
        int i, left = 0, right = 0, nums_size = nums.size();
        sort(nums.begin(),nums.end());
        if(A == nums){
            return 0;
        }
        for(i = 0; i < nums_size; i++){
            if(nums[i] != A[i]){
                left = i;
                break;
            }
        }
        for(i = nums_size-1; i > 0; i--){
            if(nums[i] != A[i]){
                right = i;
                break;
            }
        }
        return right-left+1;
    }
};


