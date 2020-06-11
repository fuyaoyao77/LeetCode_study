//1122. 数组的相对排序

/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中


*/

//hash + sort, plus

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> map;
        int i = 0, j = 0, k = 0, size1 = arr1.size(), size2 = arr2.size(); 
        vector<int> arrtarget(size1, 0), left(size1, 0);
        for(i = 0; i < size2; i++){
            map[arr2[i]] = 0;
        }
        for(i = 0; i < size1; i++){
            if(map.find(arr1[i]) != map.end()){
                ++map[arr1[i]];
            }
            else{
                left[j] = arr1[i];
                j++;
            }
        }
        for(i = 0; i < size2; i++){
            for(j = 0; j < map[arr2[i]]; j++){
                arrtarget[k] = arr2[i];
                k++;
            }
        }
        sort(left.begin(), left.end());
        for(i = 0; i < size1; i++){
            arrtarget[i] += left[i];
        }
        return arrtarget;
    }
};

