class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), next(nums.begin(), k), 0);
        double avg = sum / k;
        for(int i = k, len = nums.size(); i < len; i++) {
            sum -= nums[i - k];
            sum += nums[i];
            if(avg < sum / k)
                avg = sum / k;
        }

        return avg;
    }
};