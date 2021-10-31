class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long rest = k % (accumulate(chalk.begin(), chalk.end(), 0LL));
        for(int i = 0; i < chalk.size(); i++) {
            rest -= chalk[i];
            if(rest < 0)
                return i;
        }
        return 0;
    }
};