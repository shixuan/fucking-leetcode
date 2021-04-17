class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> tb = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

    vector<string> letterCombinations(string digits) {
        dfs({}, 0, digits);
        return ans;
    }

    void dfs(string path, int idx, string digits) {
        if(idx >= digits.size()) return;

        for(char ch : tb[digits[idx]]) {
            path.push_back(ch);
            dfs(path, idx + 1, digits);
            if(path.size() == digits.size())
                ans.push_back(path);
            path.pop_back();
        }
    }
};