class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0;
        for(int w : weights) {
            left = max(w, left);
            right += w;
        }

        while(left < right) {
            int mid = (left + right) / 2;
            if(check(weights, D, mid))  left = mid + 1;
            else    right = mid;
        }

        return right;
    }

    bool check(vector<int>& weights, int D, int tar) {
        int count = 0;
        for(int i = 0, sum = 0; i < weights.size(); count++, sum = 0) {
            for( ; i < weights.size() && sum + weights[i] <= tar; i++) 
                sum += weights[i];
        }

        return count > D;
    }
};