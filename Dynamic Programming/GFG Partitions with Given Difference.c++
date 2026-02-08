//s1 - s2 = d(given)
//totSum = s1 + s2 => s2 = totSum - s1(put in above equation)
//s1 - totSum + s1 = d => s1 = (totSum - d) / 2;

class Solution {
  private:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int>prev(target+1,0);
        if(arr[0] == 0) prev[0] = 2; //Case 1 : pick and notPick
        //Case 2 : arr[0] != 0
        //if it is equal to <= target we can pick it 
        //else we will not pick
        else prev[0] = 1;//notPick
        if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;//pick
        for(int ind = 1; ind < n; ind++){
            vector<int>curr(target+1,0);
            for(int tar=0; tar<=target; tar++){//have to take it from 0 as questions says elements can start from 0
                int notTake = prev[tar];
                int take = 0;
                if(arr[ind] <= tar) take = prev[tar - arr[ind]];
                curr[tar] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int totSum = 0;
        for(int num : arr) totSum += num;
        if((totSum - diff < 0) || ((totSum - diff) % 2)) return false;
        return perfectSum(arr, (totSum - diff) / 2);
    }
};
