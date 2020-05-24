
//实现matlab里面的reshape函数

/*
在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。

给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。

如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

示例 1:

输入: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
输出: 
[[1,2,3,4]]
解释:
行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
示例 2:

输入: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
输出: 
[[1,2],
 [3,4]]
解释:
没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
注意：

给定矩阵的宽和高范围在 [1, 100]。
给定的 r 和 c 都是正数。

*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if(m == 0 || m * n != r * c){
            return nums;
        }

        vector<vector<int>> A;  //https://www.cnblogs.com/superjn/p/10730541.html
        vector<int> B;         //学习vector<vector<int>> 的用法，插入，访问，大小等等
        int count = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                B.push_back(nums[i][j]);
                if(n * i + j == count * c-1){   //重新排列
                    A.push_back(B);
                    B.clear();
                    count++;
                }
            }
        }
        return A;
    }
};


/*
1、定义
vector<vector<int>> A;//错误的定义方式
vector<vector<int> > A;//正缺的定义方式
2、插入元素
若想定义A = [[0,1,2],[3,4,5]]，则：
//正确的插入方式
vector<vector<int> > A;
//A.push_back里必须是vector
vector<int> B;
B.push_back(0);
B.push_back(1);
B.push_back(2);
A.push_back(B);
B.clear();
B.push_back(3);
B.push_back(4);
B.push_back(5);
A.push_back(B);
//错误的插入方式
vector<vector<int> > A;
A[0].push_back(0);
A[0].push_back(1);
A[0].push_back(2);
A[1].push_back(3);
A[1].push_back(4);
A[1].push_back(5);
3、长度
//vector<vector<int> >A中的vector元素的个数
len = A.size();   //行数
//vector<vector<int> >A中第i个vector元素的长度
len = A[i].size();  //列数
4、访问某元素
访问某元素时，方法和二维数组相同，例如：
//根据前面的插入，可知输出5。
printf("%d\n", A[1][2]);
*/
