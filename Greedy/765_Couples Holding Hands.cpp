class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        vector<int> pos(len);
        for(int i = 0; i < len; i++) pos[row[i]] = i;

        int ans = 0;
        for(int i = 0; i < len; i += 2) {
            int pair = row[i] ^ 1;  // xor找下标
            if(row[i + 1] == pair) continue;
            //不需要实际去swap，减少执行时间。只需记录被换过去的人的位置变化。
            row[pos[pair]] = row[i + 1];
            pos[row[i + 1]] = pos[pair];
            ans++;
        }

        return ans;
    }
};