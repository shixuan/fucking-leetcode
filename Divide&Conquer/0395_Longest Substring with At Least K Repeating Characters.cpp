class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.size();
        if(k <= 1) return len;
        if(k > len) return 0;
        unordered_map<char, int> tb;
        for(auto &ch : s) tb[ch]++;

        int pt = 0;
        while(pt < len && tb[s[pt]] >= k) pt++;
        if(pt == len) return len;
        int left = longestSubstring(s.substr(0, pt), k);

        while(pt < len && tb[s[pt]] < k) pt++;
        int right = longestSubstring(s.substr(pt, len), k);

        return max(left, right);
    }
};