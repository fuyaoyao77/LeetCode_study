// 96. 不同的二叉搜索树

/*

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



*/

//动态规划，递推求和

class Solution {
public:
    int numTrees(int n) {
        // 二叉搜索数的特征，左子树小于根，右子树大于根
        vector<int> dp(n+1, 0);
        dp[0]=1;  // dp[0]初始化为1
        for(int i=1; i<=n; i++)  // 从1...n的二叉搜索数数目
            for(int j=1; j<=i; j++)  // 逐步选用1...n作为根节点
                dp[i]+=dp[j-1]*dp[i-j];  // 左侧j-1个数，右侧i-j个数
        return dp[n]; 
    }
};





