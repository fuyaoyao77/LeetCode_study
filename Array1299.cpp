//1299. 将每个元素替换为右侧最大元素

/*
给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。

 

示例：

输入：arr = [17,18,5,4,6,1]
输出：[18,6,6,6,1,-1]
 

提示：

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size(), maxarr = arr[size - 1];
        arr[size - 1] = -1;
        int i = size - 2;
        while(i > -1){
            int arri = arr[i];
            arr[i] = maxarr;
            maxarr = max(arri,maxarr);
            i--;
        }
        return arr;
    }
};

/*
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        ans[n - 1] = -1;
        for (int i = n - 2; i >= 0; --i) {
            ans[i] = max(ans[i + 1], arr[i + 1]);
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side/solution/jiang-mei-ge-yuan-su-ti-huan-wei-you-ce-zui-da-y-5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/



