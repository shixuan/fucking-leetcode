/*
    nums = "----->-->"; k =3
    result = "-->----->";

    reverse "----->-->" we can get "<--<-----"
    reverse "<--" we can get "--><-----"
    reverse "<-----" we can get "-->----->"
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};