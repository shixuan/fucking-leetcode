class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i = 0; i < len;) {
            if(n == 0)  return true;

            if(flowerbed[i] == 1) {
                i += 2; //当前有花，下一个一定不能种
            }
            else if(i == len - 1 || flowerbed[i + 1] == 0) {
                //当前为0，那么上一格子一定是0。因为如果是1，则会跳两格
                //如果下一格为0或者当前为最后一格，则一定能种
                n--;
                i += 2;
            }
            else {
                i += 3; //当前为0但不能种，说明下一格为1，那么跳三格
            }
        }

        return n <= 0;
    }
};