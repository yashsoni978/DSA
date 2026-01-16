class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(j == i) continue;
                if(nums[i] == nums[j] && abs(i - j) <= k) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_set<int>st;
        while(j < n){
            if(abs(i - j) > k){
                st.erase(nums[i]);
                i++;
            }
            if(st.find(nums[j]) != st.end()) return true;
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};