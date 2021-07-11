class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for(char ch : s) {
            map[ch]++;
        } 

        vector<pair<char, int>> pairs;
        for(auto [key, value] : map) {
            pairs.push_back({key, value});
        }
        sort(pairs.begin(), pairs.end(), compare);

        string ans = "";
        for(auto [key, value] : pairs) {
            while(value--) {
                ans += key;
            }
        }

        return ans;
    }

    static bool compare(const pair<char, int> a, const pair<char, int> b) {
        return a.second > b.second;
    }
};