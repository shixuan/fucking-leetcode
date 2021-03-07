class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        //even = #(i/2)'s 1, odd = #(i-1)'s 1 + 1 = #(i/2)'s 1 + 1
        for(int i = 1; i <= num; i++)
            res.push_back(res[i >> 1] + (i & 1));

        return res;
    }
};