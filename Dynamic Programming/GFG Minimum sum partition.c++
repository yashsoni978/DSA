class Solution {
public:
    int minDifference(vector<int>& arr) {

        int n = arr.size();
        if(n == 0) return 0;

        int totSum = 0;
        for(int num : arr) 
            totSum += num;

        int targetSum = totSum / 2;   

        vector<bool> prev(targetSum + 1, false);

        prev[0] = true;

        if(arr[0] <= targetSum)
            prev[arr[0]] = true;

        for(int ind = 1; ind < n; ind++){

            vector<bool> curr(targetSum + 1, false);
            curr[0] = true;

            for(int target = 1; target <= targetSum; target++){

                bool notTake = prev[target];

                bool take = false;
                if(arr[ind] <= target)
                    take = prev[target - arr[ind]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        int ans = INT_MAX;

        for(int i = 0; i <= targetSum; i++){
            if(prev[i]){
                int s1 = i;
                int s2 = totSum - i;
                ans = min(ans, abs(s2 - s1));
            }
        }

        return ans;
    }
};
