class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int i, j, partsum = 0, sum = 0;
        for(i = 0; i < A.size(); i++){
            sum = sum + A[i];
        }
        if(sum%3 != 0){
            return false;
        }
        for(i = 0; i < A.size(); i++){
            partsum = partsum + A[i];
            if(partsum == sum/3){
                break;
            }
        }
        if(i == A.size()){
            return false;
        }
        partsum = 0;
        for(j = i + 1; j < A.size(); j++){
            partsum = partsum + A[j];
            if(partsum == sum/3){
                return true;
            }
        }
        return false;
    }
};
