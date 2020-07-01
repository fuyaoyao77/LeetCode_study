//367. 有效的完全平方数


/*

给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

*/


//典型的二分法


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1 || num == 4) return true;

        int left = 0, right = num/2, middle = 0;
        while(left < right){
            long middle = (left + right)/2;
            if(middle*middle < num){
                left = middle + 1;
            }
            else if(middle*middle > num){
                right = middle;
            }
            else{
                return true;
            }
        }
        return false;
    }
};



