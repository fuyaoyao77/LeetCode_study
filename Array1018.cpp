//1018. 可被 5 整除的二进制前缀

/*

给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。

返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。

 

示例 1：

输入：[0,1,1]
输出：[true,false,false]
解释：
输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为真。
示例 2：

输入：[1,1,1]
输出：[false,false,false]
示例 3：


输入：[0,1,1,1,1,1]
输出：[true,false,false,false,true,false]
示例 4：

输入：[1,1,1,0,1]
输出：[false,false,false,false,false]
 

提示：

1 <= A.length <= 30000
A[i] 为 0 或 1

*/

/*
解题思路
如1 11 111
先求1的余数，为1；
由于在11中，1移位至第二位，余数扩大两倍，故对5取余存储到ys中；
若加的数与ys的和刚好为5的倍数，则能整除，反之不能；
用ys存储前一项的余数即可；
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int i=0,ys=0;
        vector<bool> b;//存储结果
        while(i<A.size())
        {
            int sum=ys+A[i++];
            if(sum%5==0)
            {
                b.push_back(1);
                ys=0;
            }  
            else
            {
                b.push_back(0);
                ys=(sum*2)%5;
            }
        }
        return b;
    }
};






