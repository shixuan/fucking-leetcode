class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        spiltAndInsert(freq, s1);   // equivalent to only emerging once in s1+s2
        spiltAndInsert(freq, s2);

        vector<string> ans;
        for(auto& [w, f] : freq) {
            if (1 == f) {
                ans.push_back(w);
            }
        }

        return ans;
    }

    void spiltAndInsert(unordered_map<string, int>& freq, string& s) {
        stringstream stream(s);
        string word;
        while (stream >> word) {
            freq[word]++;
        }
    }
};