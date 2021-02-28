class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int len = A.size();
        vector<int> diff(len + 1);
        int ans = 0, sum = 0;
        for(int i = 0; i < len; i++) {
            sum += diff[i];
            if((sum + A[i]) % 2 == 0) {
                if(i + K > len) return -1;
                diff[i + 1]++;  //A[i]此时被翻转，diff[i]已经用不到了，直接在diff[i+1]里++; sum++效果相同
                diff[i + K]--;
                ans++;
            }
        }

        return ans;
    }
};