class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right) {
            long sum = left * left + right * right;
            if(sum == c)    return true;
            if(sum > c)  right--;
            else    left++;
        }

        return false;
    }
};