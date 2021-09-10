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
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1, target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};


int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    cout << "[" << endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<"[";
        for(int j = 0; j < ans[0].size(); j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
    
    return 0;
}
