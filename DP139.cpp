//139. 单词拆分

/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



方法一：动态规划
思路和算法

我们定义 \textit{dp}[i]dp[i] 表示字符串 ss 前 ii 个字符组成的字符串 s[0..i-1]s[0..i−1] 是否能被空格拆分成若干个字典中出现的单词。从前往后计算考虑转移方程，每次转移的时候我们需要枚举包含位置 i-1i−1 的最后一个单词，看它是否出现在字典中以及除去这部分的字符串是否合法即可。公式化来说，我们需要枚举 s[0..i-1]s[0..i−1] 中的分割点 jj ，看 s[0..j-1]s[0..j−1] 组成的字符串 s_1s 
1
​	
 （默认 j = 0j=0 时 s_1s 
1
​	
  为空串）和 s[j..i-1]s[j..i−1] 组成的字符串 s_2s 
2
​	
  是否都合法，如果两个字符串均合法，那么按照定义 s_1s 
1
​	
  和 s_2s 
2
​	
  拼接成的字符串也同样合法。由于计算到 \textit{dp}[i]dp[i] 时我们已经计算出了 \textit{dp}[0..i-1]dp[0..i−1] 的值，因此字符串 s_1s 
1
​	
  是否合法可以直接由 dp[j]dp[j] 得知，剩下的我们只需要看 s_2s 
2
​	
  是否合法即可，因此我们可以得出如下转移方程：

\textit{dp}[i]=\textit{dp}[j]\ \&\&\ \textit{check}(s[j..i-1])
dp[i]=dp[j] && check(s[j..i−1])

其中 \textit{check}(s[j..i-1])check(s[j..i−1]) 表示子串 s[j..i-1]s[j..i−1] 是否出现在字典中。

对于检查一个字符串是否出现在给定的字符串列表里一般可以考虑哈希表来快速判断，同时也可以做一些简单的剪枝，枚举分割点的时候倒着枚举，如果分割点 jj 到 ii 的长度已经大于字典列表里最长的单词的长度，那么就结束枚举，但是需要注意的是下面的代码给出的是不带剪枝的写法。

对于边界条件，我们定义 \textit{dp}[0]=truedp[0]=true 表示空串且合法。

有能力的读者也可以考虑怎么结合字典树 \textit{Trie}Trie 来实现，这里不再展开。
*/

//动态规划，dp i 表示前i个字符是否成功， 前i个又分为前j和后i-j是否成功，后i-j当做一个字符串用hash表确认


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};





