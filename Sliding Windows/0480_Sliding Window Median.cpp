class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<double> set;

        for(int i = 0, len = nums.size(); i < len; i++) {
            if(set.size() >= k)
                set.erase(set.find(nums[i - k]));
            set.insert(nums[i]);

            if(i >= k - 1) {
                auto mid = set.begin();
                advance(mid, k / 2);
                if(k % 2)
                    ans.push_back(*mid);
                else
                    ans.push_back((*mid + *prev(mid, 1)) / 2);
            }
        }

        return ans;
    }
};