//15. 三数之和

/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


//自己的版本
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, size = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> target;
        for(i = 0; i < size - 2; i++){
            j = i + 1;
            k = size - 1;
            while(j < k){
                if(nums[j] + nums[k] + nums[i] == 0){
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[j]);
                    a.push_back(nums[k]);
                    target.push_back(a);
                    a.clear();
                    j++;
                }
                if(nums[j] + nums[k] + nums[i] > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(nums[i] == nums[i+1] && i < size - 2){
                i++;
            }
        }
        target.erase(unique(target.begin(), target.end()), target.end());
        return target;
    }
};

*/






