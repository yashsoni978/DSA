class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxScore = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            unordered_set<int>st;
            for(int j=i; j<n; j++){
                if(st.count(nums[j])) break;
                st.insert(nums[j]);
                sum += nums[j];
            }
            maxScore = max(maxScore, sum);
        }
        return maxScore;
    }
};

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int i = 0, j = 0, sum = 0;
        unordered_set<int>st;
        while(j < n){
            if(!st.count(nums[j])){
                st.insert(nums[j]);
                sum += nums[j];
                maxSum = max(maxSum, sum);
                j++;
            }
            else{
                while(i < n && st.count(nums[j])){
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return maxSum; 
    }
};