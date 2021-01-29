class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(k == 0) return ans;
        deque<int> window;   //双端队列，从队头到队尾依次存窗口内最大元素的index ~ 最小元素的index

        for(int right =0; right < nums.size(); right++){   //窗口每右移一次，都会产生一个最大值[队列头位置的元素]
            if(!window.empty() && window.front() <= right - k){   //队头不在窗口范围内
                window.pop_front();
            }
            while(!window.empty() && nums[right] > nums[window.back()]){   //待入队元素比队尾元素大，pop直到队尾元素大于待入队元素
                window.pop_back();
            }
            window.push_back(right);

            if(right >= k - 1) 
                ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};