class Solution {
private:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        if(ind == arr.size()){
            if(target == 0) ans.push_back(ds);
            return;
        }
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(ind+1, target, arr, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

//2^target * k (k for putting into ds) and 2 choices to the power target because lets say we have 1 and target is 10 then we have to pick 1 10 times or target times