//1139. 最大的以 1 为边界的正方形

/*
给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。

 

示例 1：

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9
示例 2：

输入：grid = [[1,1,0,0]]
输出：1
 

提示：

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] 为 0 或 1

*/


class Solution {//dp
public:
    int i,j,k,t,m,n,res,len;
    int left[100][100];//表示此点（包括）向左有多少连续的1
    int up[100][100];//表示此点（包括）向上有多少连续的1
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        m = grid.size();n = grid[0].size();
        for(i=0;i<m;i++) {
             for(j=0;j<n;j++) {
                if(j&&grid[i][j-1]) left[i][j] = left[i][j-1] + grid[i][j]; 
                else left[i][j] = grid[i][j];
             }
        }
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(j&&grid[j-1][i]) up[j][i] = up[j-1][i] + grid[j][i];
                else up[j][i] = grid[j][i];
            }
        }
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]) {
                    len = min(left[i][j],up[i][j]);//找最小交接长度
                    k = i - len + 1;
                    t = j - len + 1;
                    while(k<=i-res) {//在大于最优长度的范围内寻找解
                        if(up[i][t]>=len&&left[k][j]>=len) {res = i-k+1;break;}
                        k++;t++;len--;
                    }
                }
            }
        }
        return res*res;
    }
};







