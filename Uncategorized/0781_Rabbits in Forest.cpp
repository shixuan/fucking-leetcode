class Solution {
public:
    int numRabbits(vector<int>& answers) {
        /* 
        * 报数相同的兔子有可能是同一颜色，若都是同一颜色，则当前颜色的兔子总数为n+1;
        * 若报数相同的兔子数量m大于所报的数n，则m-n数量的兔子是另一种颜色(m-n<n);
        */
        int map[1000] = { 0 };
        int ans = 0;
        for(int i : answers) {
            if(map[i] == 0) {   //为0有两种可能: 1.初始状态; 2.兔子数量大于所报的数(m>n)
                map[i] = i;
                ans += i + 1;
            }
            else
                map[i]--;
        }

        return ans;
    }
};