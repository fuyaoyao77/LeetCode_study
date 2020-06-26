//557. 反转字符串中的单词 III

/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

通过次数60,763提交次数85,698

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/

//思路：
//利用reverse函数， 再利用双指针，指向每一个单词的起始位置和末尾，  最后一个单词没有空格，所以单独再反转一次


class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0, size = s.size();
        if(size == 0) return s;

        while(right < size){
            if(s[right] != ' '){
                right++;
            }
            else{
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
                right++;
            }  
        }
        reverse(s.begin() + left, s.begin() + right);
        return s;
    }
};





