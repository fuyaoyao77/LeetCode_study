
//1160.拼写数组
/*
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。



方法一：哈希表记数
思路和算法

显然，对于一个单词 word，只要其中的每个字母的数量都不大于 chars 中对应的字母的数量，那么就可以用 chars 中的字母拼写出 word。所以我们只需要用一个哈希表存储 chars 中每个字母的数量，再用一个哈希表存储 word 中每个字母的数量，最后将这两个哈希表的键值对逐一进行比较即可。

复杂度分析

时间复杂度：O(n)O(n)，其中 nn 为所有字符串的长度和。我们需要遍历每个字符串，包括 chars 以及数组 words 中的每个单词。

空间复杂度：O(S)O(S)，其中 SS 为字符集大小，在本题中 SS 的值为 2626（所有字符串仅包含小写字母）。程序运行过程中，最多同时存在两个哈希表，使用的空间均不超过字符集大小 SS，因此空间复杂度为 O(S)O(S)。


*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> chars_cnt;
        for (char c : chars)
            ++chars_cnt[c];
        int ans = 0;
        for (string word : words) {
            unordered_map<char, int> word_cnt;
            for (char c : word)
                ++word_cnt[c];
            bool is_ans = true;
            for (char c : word)
                if (chars_cnt[c] < word_cnt[c]) {
                    is_ans = false;
                    break;
                }
            if (is_ans)
                ans += word.size();
        }
        return ans;
    }
};


