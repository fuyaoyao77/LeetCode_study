//697. 数组的度

/*

给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

示例 1:

输入: [1, 2, 2, 3, 1]
输出: 2
解释: 
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2:

输入: [1,2,2,3,1,4,2]
输出: 6
注意:

nums.length 在1到50,000区间范围内。
nums[i] 是一个在0到49,999范围内的整数。

*/


class Solution {
public:

    unordered_map<int,vector<int>> m;//统计开始和结束坐标
    unordered_map<int,int> m1;//统计度
    int findShortestSubArray(vector<int>& nums) {
        int max=0;//统计最大频数
        int min=50000;//统计最短长度
        //统计所有字符开始的坐标
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
            if(m1[nums[i]]>max) max=m1[nums[i]];
            if(m[nums[i]].size()==0){
                m[nums[i]].push_back(i);
            }
            else if(m[nums[i]].size()==1){
                m[nums[i]].push_back(i);
            }
            else if(m[nums[i]].size()==2){
                m[nums[i]][1]=i;
            }
        }
        unordered_map<int,int>::iterator it;
        for(it=m1.begin();it!=m1.end();it++){
            if(it->second!=max) continue;
            if(m[it->first].size()==2){
                if(m[it->first][1]-m[it->first][0]+1<min){
                min=m[it->first][1]-m[it->first][0]+1;
                }
            }
            else{
                return 1;
            }

        }
        return min;


    }
};











