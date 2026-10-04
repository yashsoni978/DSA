class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt > n/2) return nums[i];
        }
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++) mp[nums[i]]++;
        for(auto it : mp){
            if(it.second > n/2) return it.first;
        }
        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el == nums[i]) cnt++;
            else cnt--;
        }
        int cnt1 = 0;
        for(int i=0; i<n; i++){
            if(el == nums[i]) cnt1++;
        }
        if(cnt1 > n/2) return el;
        return -1;
    }
};

