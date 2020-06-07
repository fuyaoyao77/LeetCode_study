//1089.复写零

/*
给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

示例 1：

输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：

输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

提示：

1 <= arr.length <= 10000
0 <= arr[i] <= 9

*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
         int last, count = 0, size = arr.size();
        for(int i = 0; i < size; i++){
            if(arr[i] == 0){
                count = count + 2;
            }
            else{
                count++;
            }
            if(count >= size){
                last = i;
                break;
            }
        }
        if(count == size){
            for(int j = last; j > -1; j--){
                if(arr[j] != 0){
                   arr[--size] = arr[j];
                }
                else{
                  arr[--size] = 0;
                  arr[--size] = 0; 
                }
            }
        }
        else{
            arr[--size] = 0;
            for(int j = last - 1; j > -1; j--){
                if(arr[j] != 0){
                   arr[--size] = arr[j];
                }
                else{
                  arr[--size] = 0;
                  arr[--size] = 0; 
                }
            } 
        }
    }
};








