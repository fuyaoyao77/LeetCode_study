//167.两数之和


/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

*/

// map
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        //vector<int> index(2,0);
        int i;
        for(i = 0; i < numbers.size(); i++){
            map[numbers[i]] = i;
        }
        for(i = 0; i < numbers.size(); i++){
            if(map.find(target - numbers[i]) != map.end()){
                if(i != map[target - numbers[i]]){
                    return {i + 1, ,map[target - numbers[i]] + 1};
                    //index[0] = i + 1;
                    //index[1] = map[target - numbers[i]] + 1;
                    //break;
                }
            }
        }
        //return index;
        return {-1,-1};
    }
};

//double link

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while(low < high){
            if(numbers[low] + numbers[high] == target) return {low + 1, high + 1};
            if(numbers[low] + numbers[high] > target){
                high--;
            } 
            else{
                low++;
            }  
        }
        return {-1,-1};
    }
};



*/






