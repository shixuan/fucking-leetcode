class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        std::sort(properties.begin(), properties.end(),
            [](std::vector<int>& a, std::vector<int>& b) {
                return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
            }); // attack from high to low. If attack points are same, sort defend from low to high.

        int maxd = 0, ans = 0;
        for (auto& p : properties) {
            if (p[1] < maxd)
                ans++;
            else
                maxd = p[1];
        }

        return ans;
    }
};