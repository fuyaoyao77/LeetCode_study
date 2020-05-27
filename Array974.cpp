//974.和可被 K 整除的子数组

/*

给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

 

示例：

输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sums-divisible-by-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

方法一：哈希表 + 逐一统计
思路和算法

通常，涉及连续子数组问题的时候，我们使用前缀和来解决。

我们令 P[i] = A[0] + A[1] + ... + A[i]P[i]=A[0]+A[1]+...+A[i]。那么每个连续子数组的和 \textit{sum}(i, j)sum(i,j) 就可以写成 P[j] - P[i-1]P[j]−P[i−1]（其中 0 < i < j0<i<j）的形式。此时，判断子数组的和能否被 KK 整除就等价于判断 (P[j] - P[i-1]) \bmod K == 0(P[j]−P[i−1])modK==0，根据 同余定理，只要 P[j] \bmod K == P[i-1] \bmod KP[j]modK==P[i−1]modK，就可以保证上面的等式成立。

因此我们可以考虑对数组进行遍历，在遍历同时统计答案。当我们遍历到第 ii 个元素时，我们统计以 ii 结尾的符合条件的子数组个数。我们可以维护一个以前缀和模 KK 的值为键，出现次数为值的哈希表 \textit{record}record，在遍历的同时进行更新。这样在计算以 ii 结尾的符合条件的子数组个数时，根据上面的分析，答案即为 [0..i-1][0..i−1] 中前缀和模 KK 也为 P[i] \bmod KP[i]modK 的位置个数，即 \textit{record}[P[i] \bmod K]record[P[i]modK]。

最后的答案即为以每一个位置为数尾的符合条件的子数组个数之和。需要注意的一个边界条件是，我们需要对哈希表初始化，记录 \textit{record}[0] = 1record[0]=1，这样就考虑了前缀和本身被 KK 整除的情况。

注意：不同的语言负数取模的值不一定相同，有的语言为负数，对于这种情况需要特殊处理。

*/


class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> record = {{0, 1}};
        int sum = 0, ans = 0;
        for (int elem: A) {
            sum += elem;
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int modulus = (sum % K + K) % K;
            if (record.count(modulus)) {
                ans += record[modulus];
            }
            ++record[modulus];
        }
        return ans;
    }
};








