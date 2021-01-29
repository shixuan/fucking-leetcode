class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int len = A.size(), carry = 0;
        vector<int> ans;
        for(int i = len - 1; i >= 0; i--) {
            int sum = A[i] + K % 10 + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
            K /= 10;
        }
        if(carry != 0) {
            K += carry;
        }
        for(; K > 0; K /= 10) {
            ans.push_back(K % 10);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};