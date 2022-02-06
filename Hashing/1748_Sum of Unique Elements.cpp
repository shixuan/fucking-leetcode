class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums)
            mp[n]++;
        
        int ans = 0;
        for (auto &[k, v] : mp) {
            if (1 == v)
                ans += k;
        }

        return ans;
    }
};