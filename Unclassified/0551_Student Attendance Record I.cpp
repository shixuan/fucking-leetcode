class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for(auto &ch : s) {
            if(ch == 'A')
                A++;
            if(ch == 'L')
                L++;
            else
                L = 0;
            
            if(L >= 3 || A >= 2)
                return false;
        }

        return true;
    }
};