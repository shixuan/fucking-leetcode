class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(!check(s[i]) && i < j) i++;
            while(!check(s[j]) && i < j) j--;
            if(i < j)   swap(s[i++], s[j--]);
        }

        return s;
    }

    bool check(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};