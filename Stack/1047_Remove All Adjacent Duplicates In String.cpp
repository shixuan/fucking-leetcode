class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for(auto &ch : S) {
            if(!ans.empty() && ans.back() == ch)
                ans.pop_back();
            else
                ans.push_back(ch);
        }

        return ans;
    }
};