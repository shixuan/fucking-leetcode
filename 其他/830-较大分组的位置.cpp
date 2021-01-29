class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int len = s.size();
        for (int left = 0, right = 0; right < len; left = right) { 
            while (right < len && s[left] == s[right]) right++;

            if (right - left >= 3) 
                ans.push_back({left, right - 1});
        }
        return ans;
    }
};