class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int u = coordinates[1][0] - x0, v = coordinates[1][1] - y0;
        int len = coordinates.size();
        if(len == 2)
            return true;
            
        for(int i = 2; i < len; i++) {
            int uNext = coordinates[i][0] - x0, vNext = coordinates[i][1] - y0;
            if(u * vNext - uNext * v)   //线性无关便不在一条直线上
                return false;
        }
        return true;
    }
};