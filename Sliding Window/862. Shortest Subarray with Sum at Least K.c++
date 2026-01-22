class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int minLen = INT_MAX;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum >= k) minLen = min(minLen, j-i+1);
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        int minLen = INT_MAX;
        int i = 0, j = 0;
        vector<long long>cumSum(n,0);
        while(j < n){
            if(j == 0) cumSum[j] = nums[j];
            else cumSum[j] = cumSum[j-1] + nums[j];
            if(cumSum[j] >= k) minLen = min(minLen, j+1);
            while(!dq.empty() && cumSum[j] - cumSum[dq.front()] >= k){
                minLen = min(minLen, j - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cumSum[j] <= cumSum[dq.back()]) dq.pop_back();
            dq.push_back(j);
            j++;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};