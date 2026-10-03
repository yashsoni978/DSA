class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += arr[j];
                if(sum == k) maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mpp;
        int sum = 0, maxLen = 0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum == k){
                maxLen = max(maxLen, i+1);
            }
            int rem = sum - k;
            if(mpp.find(rem) != mpp.end()){
                int len = i - mpp[rem];
                maxLen = max(maxLen, len);
            }
            if(mpp.find(sum) == mpp.end()) mpp[sum] = i;
        }
        return maxLen;
    }
};