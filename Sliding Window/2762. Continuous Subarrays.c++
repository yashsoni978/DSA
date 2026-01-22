class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            int mini = nums[i], maxi = nums[i];
            for(int j=i; j<n; j++){
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                if(abs(maxi - mini) <= 2) cnt++;
                else break;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        map<int,int>mp;
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;
            while(abs(mp.rbegin() -> first - mp.begin() -> first) > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        priority_queue<pair<int,int>>maxH;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minH;
        int i = 0, j = 0;
        while(j < n){
            maxH.push({nums[j], j});
            minH.push({nums[j], j});
            while(abs(maxH.top().first - minH.top().first > 2)){
                i++;
                while(!maxH.empty() && maxH.top().second < i) maxH.pop();
                while(!minH.empty() && minH.top().second < i) minH.pop();
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};