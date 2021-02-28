class Solution {
public:
    int _subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> freq;
        int left = 0, right = 0, res = 0;
        while (right < A.size()) {
            freq[A[right]]++;
            right++;
            while (freq.size() > K) {
                freq[A[left]]--;
                if (freq[A[left]] == 0) 
                    freq.erase(A[left]);
                left++;
            }
            res += right - left;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return _subarraysWithKDistinct(A, K) - _subarraysWithKDistinct(A, K - 1);
    }
};