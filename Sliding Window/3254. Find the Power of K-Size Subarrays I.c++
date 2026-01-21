class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0; i<= n-k; i++){
            bool isValid = true;
            for(int j=i; j<i+k-1; j++){
                if(nums[j + 1] != nums[j] + 1){
                    isValid = false;
                    break;
                }
            }
            if(isValid) ans.push_back(nums[i+k-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n-k+1,-1);
        int cnt = 1;
        for(int i=1; i<k; i++){
            if(nums[i] == nums[i-1] + 1) cnt++;
            else cnt = 1;
        }
        if(cnt == k) res[0] = nums[k-1];
        int i = 1, j = k;
        while(j < n){
            if(nums[j] == nums[j-1] + 1) cnt++;
            else cnt = 1;
            if(cnt >= k) res[i] = nums[j];
            i++;
            j++;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<int>res;
        for(int j=0; j<n; j++){
            if(dq.size() == k) dq.pop_front();
            if(!dq.empty() && dq.back() != nums[j] - 1) dq.clear();
            dq.push_back(nums[j]);
            if(j >= k-1){
                if(dq.size() == k) res.push_back(dq.back());
                else res.push_back(-1);
            }
        }
        return res;
    }
};