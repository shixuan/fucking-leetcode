class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int k = INT_MIN;
        stk.push(nums[nums.size() - 1]);
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < k)
                return true;
            while(!stk.empty() && nums[i] > stk.top()) {
                k = stk.top();
                stk.pop();  
            }
            stk.push(nums[i]);
        }
        return false;
    }
};