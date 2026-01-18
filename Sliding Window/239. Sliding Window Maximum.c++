class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int n = nums.size();
        for(int i=0; i<= n-k; i++){
            int maxi = nums[i];
            for(int j=i; j<i+k; j++){
                maxi = max(maxi, nums[j]);
            }
            res.push_back(maxi);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        deque<int>dq;
        for(int i=0; i<n; i++){
            //step 1
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            //step2
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            //step 3
            dq.push_back(i);
            //step 4
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(!pq.empty() && pq.top().second <= i-k) pq.pop();
            pq.push({nums[i] , i});
            if(i >= k-1) ans.push_back(pq.top().first);
        }   
        return ans;
    }
};