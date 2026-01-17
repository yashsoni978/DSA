class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp.clear();
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                if(mp.size() == k) cnt++;
                else if(mp.size() > k) break;
            }
        }
        return cnt;
    }
};

class Solution {
private:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        unordered_map<int,int>mp;
        while(r < n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};