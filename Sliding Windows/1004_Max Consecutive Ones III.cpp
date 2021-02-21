class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, count = 0, len = A.size();
        while(right < len) {
            if(A[right] == 0) count++;
            if(count > K) {
                if(A[left] == 0) count--;
                left++;
            }
            right++;
        }

        return right - left;
    }
};