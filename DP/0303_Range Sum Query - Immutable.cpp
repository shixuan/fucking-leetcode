class NumArray {
public:
    vector<int> sum;

    NumArray(vector<int>& nums) {
        int len = nums.size();
        sum.resize(len + 1);
        for(int i = 0; i < len; i++)
            sum[i + 1] = sum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */