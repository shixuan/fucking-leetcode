class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        bool inc = true, dec = true;
        for(int i = 0; i < len - 1; i++){
            if(A[i] < A[i + 1]) dec = false;
            if(A[i] > A[i + 1]) inc = false;
        }

        return inc || dec;
    }
};