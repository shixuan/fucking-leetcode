class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 1;

        for(int i = 0; i < preorder.size(); i++) {
            if(preorder[i] == ',')  continue;
            if(count <= 0) return false;

            if(preorder[i] == '#')  count--;
            else {
                while(i < preorder.size() && preorder[i] >= '0' && preorder[i] <= '9') i++;
                i--;
                count++;
            }
        }

        return count == 0;
    }
};