/*双指针*/
class Solution {
public:
    int trap(vector<int>& height) {
        int empty = accumulate(height.begin(), height.end(), 0);
        int vol = 0;
        int left = 0, right = height.size() - 1;
        int lvl = 1;
        while(left <= right) {
            while(left <= right && height[left] < lvl) left++;
            while(left <= right && height[right] < lvl) right--;
            vol += right - left + 1;
            lvl++;
        }

        return vol - empty;
    }
};