//1010. 总持续时间可被 60 整除的歌曲

/*
在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。

示例 1：

输入：[30,20,150,100,40]
输出：3
解释：这三对的总持续时间可被 60 整数：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60
示例 2：

输入：[60,60,60]
输出：3
解释：所有三对的总持续时间都是 120，可以被 60 整数。
 

提示：

1 <= time.length <= 60000
1 <= time[i] <= 500
*/
// just test diff
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int len = time.size();
        if (len < 2) {
            return 0;
        }

        int count = 0;
        vector<int> remains(60, 0);
        for (int i = 0; i < len; i++) {
            int remain = time[i] % 60; // 计算余数
            count += remains[(60 - remain)%60]; // 找到它的小伙伴
            ++remains[remain]; // 记录当前余数的个数
        }
        return count;
    }
};








