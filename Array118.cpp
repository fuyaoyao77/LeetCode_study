// 118.杨辉三角

/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]



*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows,vector<int>(numRows));
        for(int k = 0; k < numRows; k++){
            vector<int> ak(k+1,1);
            a[k] = ak;
        }
        int i,j;
        for(i = 2; i < numRows; i++){
            for(j = 1; j < i; j++){
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
        }
        return a;
    }
};



