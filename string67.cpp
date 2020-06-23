//67. 二进制求和

/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。


*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int carry = 0, n = max(a.size(),b.size());
        for(int i = 0; i < n; i++){
            carry += i < a.size()? (a.at(i) == '1') : 0;//a[i] = 1, carry加1
            carry += i < b.size()? (b.at(i) == '1') : 0;//b[i] = 1, carry加1
            ans.push_back(carry%2 == 1? '1' : '0');//2%2 = 0, 当前位为0
            carry = carry/2;//下一位加1，carry = 1
        }

        if(carry == 1){
            ans.push_back('1');  
        }       
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};




