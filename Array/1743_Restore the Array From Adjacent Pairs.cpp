class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for(auto adj : adjacentPairs) {
            mp[adj[0]].push_back(adj[1]);
            mp[adj[1]].push_back(adj[0]);
        }

        int n = adjacentPairs.size() + 1;
        vector<int> ans(n);
        for(auto [key, arr] : mp) {
            if(arr.size() == 1) {
                ans[0] = key;
                break;
            }
        }

        ans[1] = mp[ans[0]][0];
        for(int i = 2; i < n; i++) {
            auto adj = mp[ans[i - 1]];
            if(ans[i - 2] == adj[0])    ans[i] = adj[1];
            else ans[i] = adj[0];
        }

        return ans;
    }
};