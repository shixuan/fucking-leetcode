class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0, ans = 0;
        for (auto& r : rectangles) {
            int tmp = r[0] < r[1] ? r[0] : r[1];
            if (tmp > maxLen) {
                maxLen = tmp;
                ans = 1;
            }
            else {
                if (tmp == maxLen)
                    ans++;
            }
        }
        return ans;
    }
};