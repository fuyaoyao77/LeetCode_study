//最长回文子串

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

*/



//利用中心扩展算法

class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int low, int high) {     //扩展
        while (low >= 0 && high < s.size() && s[low] == s[high]) {
            --low;
            ++high;
        }
        return {low + 1, high - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        pair<int,int> p1,p2;                      //pair的使用和索引
        for (int i = 0; i < s.size(); ++i) {
            p1 = expandAroundCenter(s, i, i);        //奇数和偶数情形
            p2 = expandAroundCenter(s, i, i + 1);
            if (p1.second - p1.first > end - start) {
                start = p1.first;
                end = p1.second;
            }
            if (p2.second - p2.first > end - start) {
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end - start + 1);      //substr(5,3)从下标5开始返回长度为3的子串
    }
};









