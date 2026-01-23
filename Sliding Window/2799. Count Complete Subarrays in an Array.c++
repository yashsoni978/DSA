class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int totalDistinct = st.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            unordered_set<int>st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                if(st.size() == totalDistinct) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int c = st.size();
        unordered_map<int,int>mp;
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() == c){
                cnt += (n-j);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return cnt;
    }
};