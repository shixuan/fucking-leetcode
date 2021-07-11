class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(int n : encoded) {  // a^b=c, c^b=a, c^a=b
            first ^= n;
            ans.push_back(first);
        }

        return ans;
    }
};