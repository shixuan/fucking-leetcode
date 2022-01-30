class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for(auto &w : words) {
            int mask = 0;
            for(auto &ch : w) mask |= (1 << (ch - 'a'));
            if(mask) freq[mask]++;
        }

        vector<int> ans;
        for(auto &w : puzzles) {
            int count = 0, mask = 0;
            for(int i = 1; i < 7; i++) mask |= (1<<w[i]-'a');   //跳过第一个字母

            for(int sub = mask; sub; sub = (sub - 1) & mask) {
                int tmp = sub | (1 << (w[0] - 'a'));
                if(freq.count(tmp)) count += freq[tmp];
            }

            ans.push_back(count += freq[1 << (w[0] - 'a')]); //加上首字母+空集的情况
        }

        return ans;
    }
};