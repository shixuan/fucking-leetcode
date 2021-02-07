class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int left = 0, right = 0, len = s.size();
        while(right < len) {
            cost += abs(s[right] - t[right]);
            if(cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            right++;
        }

        return right - left;
    }
};