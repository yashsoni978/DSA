class Solution {
private:
    void helper(int ind, vector<int>& nums, vector<bool>& used, vector<int>& ds, vector<vector<int>>& ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            ds.push_back(nums[i]);
            helper(ind+1, nums, used, ds, ans);
            ds.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        vector<bool>used(nums.size(), false);
        vector<vector<int>>ans;
        helper(0, nums, used, ds, ans);
        return ans;
    }
};

//n * n!
//n (rss) + used(n)

class Solution {
private:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            solve(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0, nums, ans);
        return ans;
    }
};
//sc :- n(rss)