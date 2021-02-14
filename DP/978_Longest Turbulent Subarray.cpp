class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        vector<int> up(len, 1), down(len, 1);
        int ans = 1;
        for(int i = 1; i < len; i++) {
            if(arr[i - 1] > arr[i])
                down[i] = up[i - 1] + 1;
            else if(arr[i - 1] < arr[i])
                up[i] = down[i - 1] + 1;
            ans = max(ans, max(down[i], up[i]));
        }
        return ans;
    }
};