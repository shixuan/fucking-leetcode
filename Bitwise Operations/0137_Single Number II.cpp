class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int x : nums) {
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }

        return b;
    }
};