//剑指offer面试题3: 数组中重复的数字    

/*
在一个长度为n的数组中，所有的数字范围为0-n-1，判断是否有重复的数字，并返回。

*/

//On  O1
class Solution{
public:
    bool duplication(vector<int>& numbers, int *duplication){
        int length = numbers.size();
        if(numbers == nullptr || length <= 0){
            return false;
        }
        for(int i = 0; i < length; i++){
            if(numbers[i] < 0 || numbers[i] > n-1){
                return false;
            }
        }

        for(int i = 0; i < length; i++){
            while(numbers[i] != i){
                if(numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
                //swap numbers[i]  and numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[numbers[i]];
                numbers[numbers[i]] = temp;
            }
        }
        return false;
    }
}





