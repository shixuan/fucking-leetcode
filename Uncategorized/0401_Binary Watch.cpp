class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 60; j++) {
                if(countOne(i) + countOne(j) == turnedOn)
                    ans.push_back(to_string(i) + ":" + 
                                    (j < 10 ? "0" + to_string(j) : to_string(j)));
            }
        }

        return ans;
    }

    int countOne(int n) {
        int res = 0;
        while(n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};