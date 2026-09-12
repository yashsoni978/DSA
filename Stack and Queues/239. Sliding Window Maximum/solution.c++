class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0; i<=(n-k); i++){
            int mx = nums[i];
            for(int j=i; j<i+k; j++) mx = max(mx, nums[j]);
            ans.push_back(mx);
        }
        return ans;
    }
};
//n-k * k and n-k

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
//2n and k + (n - k)