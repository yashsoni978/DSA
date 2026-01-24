class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<long,int>mp[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                auto diff = (long)nums[i] - nums[j];
                auto it = mp[j].find(diff);
                //If yes, it means we don't find any
                int cntAtJ = it == end(mp[j]) ? 0 : it->second;
                mp[i][diff] += cntAtJ + 1;
                res += cntAtJ; 
            }
        }
        return res;
    }
};