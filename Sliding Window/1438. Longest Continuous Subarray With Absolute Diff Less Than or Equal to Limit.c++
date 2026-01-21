class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>ans;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int mini = nums[i] , maxi = nums[i];
            for(int j=i; j<n; j++){
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                if(maxi - mini <= limit) maxLen = max(maxLen, j-i+1);
                else break; 
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<pair<int,int>>maxH;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minH;
        int i = 0, j = 0, maxLen = 0;
        while(j < n){
            maxH.push({nums[j], j});
            minH.push({nums[j], j});
            while(maxH.top().first - minH.top().first > limit){
                i = min(maxH.top().second, minH.top().second) + 1;
                while(maxH.top().second < i) maxH.pop();
                while(minH.top().second < i) minH.pop();
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }   
        return maxLen;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxLen = 0;
        deque<int>minDq, maxDq;
        int l = 0, r = 0;
        while(r < n){
            while(!minDq.empty() && nums[r] < minDq.back()) minDq.pop_back();
            minDq.push_back(nums[r]);
            while(!maxDq.empty() && nums[r] > maxDq.back()) maxDq.pop_back();
            maxDq.push_back(nums[r]);
            while(maxDq.front() - minDq.front() > limit){
                if(nums[l] == maxDq.front()) maxDq.pop_front();
                if(nums[l] == minDq.front()) minDq.pop_front();
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};