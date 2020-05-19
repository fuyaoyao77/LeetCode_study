/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

*/

class Solution {
public:
    bool checkhuiwen(string s,int low,int high){     //check是否是回文
        int i=low,j=high;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    
    bool validPalindrome(string s) {
        int low=0,high=s.size()-1;
        while(low<high){
            if(s[low]==s[high]){
                low++;
                high--;
            }
            else{
                return checkhuiwen(s,low,high-1)||checkhuiwen(s,low+1,high);   //check 去掉左边剩下的是否回文，去掉右边是否回文
            }
        }
        return true;
    }
};




