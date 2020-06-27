//58. 最后一个单词的长度


/*

给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

 

示例:

输入: "Hello World"
输出: 5

*/


//方法：从后往前搜索，找到第一个非空格指标，即为right，从right出发找到第一个空格指标，即为left，若没有，则left = -1

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size(), left = -1, right = size - 1;
        if(size == 0) return 0;

        for(int j = size - 1; j >= 0; j--){
            if(s[j] != ' '){
                right = j;
                break;
            }
        }
        for(int j = right; j >= 0; j--){
            if(s[j] == ' '){
                left = j;
                break;
            }
        }
        return right - left;
    }
};







