class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i+1; j<n; j++){
                sum = nums[i] + nums[j];
                if(sum == target) return {i,j};
            }
        }
        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()) return {mpp[more],i};
            mpp[num] = i;
        }
        return {-1,-1};
    }
};