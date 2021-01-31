class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        for(int i = 0, prefix = 0, len = A.size(); i < len; i++) {
            prefix = ((prefix << 1) + A[i]) % 5;
            ans.push_back(prefix == 0);
        }
        return ans;
    }
};