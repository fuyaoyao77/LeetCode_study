// 70. 爬楼梯

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

*/
//  写成矩阵，用递归的思想
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1, f2 = 2, fn;
        if(n == 1) return f1;
        if(n == 2) return f2;
        for(int i = 3; i <= n; i++){
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return fn;
    }
};


/*
#include <iostream>
#include <cstring>

#define Max_rank 3
#define mod 1000000007
struct Matrix {
    long long a[Max_rank][Max_rank];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    void init(){
        a[1][1] = a[1][2] = a[2][1] = 1;
        a[2][2] = 0;
    }

    Matrix operator*(const Matrix b) {
        Matrix res;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 2; j++)
                for (int u = 1; u <= 2; u++)
                    res.a[i][j] = (res.a[i][j] + a[i][u]*b.a[u][j])%mod;
        return res;
    }
};

long long q_pow(long long n){
    Matrix ans,base;
    ans.init();
    base.init();
    while(n > 0){
        if(n&1) ans =ans *base;
        base = base *base;
        n >>= 1;
    }
    return ans.a[1][1];
}
int main() {
    long long n;
    while(std::cin >> n){
        std::cout << q_pow(n-2) << std::endl;
    }
    return 0;
}


*/



