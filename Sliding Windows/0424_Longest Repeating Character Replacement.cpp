class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> tb(26, 0);
        int left = 0, right = 0;

        for(int maxl = 0, len = s.size(); right < len;) {
            maxl = max(maxl, ++tb[s[right] - 'A']);
            right++;
            if(right - left - maxl > k) {
                tb[s[left] - 'A']--;
                left++;
            }
        }

        return right - left;
    }
};