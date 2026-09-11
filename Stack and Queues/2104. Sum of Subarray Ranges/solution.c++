class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            int mini = nums[i], maxi = nums[i];
            for(int j=i; j<n; j++){
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};

class Solution {
private:
    long long sumMin(vector<int>& nums){
        int n = nums.size();
        vector<int>psee(n), nse(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            ans += 1LL * nums[i] * left * right;
        }
        return ans;
    }
    long long sumMax(vector<int>& nums){
        int n = nums.size();
        vector<int>pge(n),nge(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            ans += 1LL * nums[i] * left * right;
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};