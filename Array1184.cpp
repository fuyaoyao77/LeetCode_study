//1184. 公交站间的距离

/*
环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。
*/


//  直接计算就行，注意边界和初始条件


class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int i, sum = 0, sum1, size = distance.size();
        for(i = 0; i < size; i++){
            sum += distance[i];
        }
        if(start < destination){
            sum1 = 0;
            for(i = start; i < destination; i++){
                sum1 += distance[i];
            }
            return min(sum1,sum - sum1);
        }
        if(start > destination){
            sum1 = 0;
            for(i = destination; i < start; i++){
                sum1 += distance[i]; 
            }
            return min(sum1,sum - sum1);
        }
        return 0;
    }
};



