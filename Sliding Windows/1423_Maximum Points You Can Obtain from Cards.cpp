class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int minP = accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0), sum = minP;
        for(int i = n - k; i < n; i++) {
            sum = sum + cardPoints[i] - cardPoints[i - n + k];
            minP = min(minP, sum);
        }

        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minP;
    }
};