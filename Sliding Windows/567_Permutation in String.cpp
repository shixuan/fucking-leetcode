class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int sLen = s1.size(), tLen = s2.size();
        if(sLen > tLen) return false;

        vector<int> sFreq(26, 0), tFreq(26, 0);

        for(int i = 0; i < sLen; i++) {
            sFreq[s1[i] - 'a']++;
            tFreq[s2[i] - 'a']++;
        }

        for(int i = sLen; i < tLen; i++) {
            if(sFreq == tFreq) return true;
            tFreq[s2[i - sLen] - 'a']--;
            tFreq[s2[i] - 'a']++;
        }

        return sFreq == tFreq;
    }
};