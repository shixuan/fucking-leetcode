class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool check(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }

    void dfs(string s) {
        if(s.size() == 0) {
            ans.push_back(path);
            return;
        }

        for(int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if(check(sub)) {
                path.push_back(sub);
                dfs(s.substr(i));
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s);
        return ans;
    }
};