class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for(int i : nums) {
            if(pos < 2 || i != nums[pos - 2])   nums[pos++] = i;
        }

        return pos;
    }
};