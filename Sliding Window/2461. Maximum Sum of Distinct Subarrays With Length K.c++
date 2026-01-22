class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        int n = nums.size();
        for(int i=0; i<= n-k; i++){
            long long sum = 0;
            unordered_set<int>st;
            bool isDistinct = true;
            for(int j=i; j<i+k; j++){
                if(st.count(nums[j])){
                    isDistinct = false;
                    break;
                }
                st.insert(nums[j]);
                sum += nums[j];
            }
            if(isDistinct) maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0;
        long long currWindowSum = 0;
        int i = 0, j = 0;
        unordered_set<int>st;
        while(j < n){
            while(st.count(nums[j])){
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            currWindowSum += nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k){
                maxSum = max(maxSum, currWindowSum);
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxSum;
    }
};