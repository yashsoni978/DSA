/*high = max - min because the farthest distance between 2 cows would be max - min*/

class Solution {
  private:
    bool canWePlace(int dist, vector<int>& arr, int k){
        int cntCows = 1, lastStall = arr[0]; //we always keep the first cow as first as possible
        for(int i=1; i<arr.size(); i++){
            if(arr[i] - lastStall >= dist){
                cntCows++;
                lastStall = arr[i];
            }
        }
        if(cntCows >= k) return true;
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        int mini = *min_element(arr.begin(), arr.end());
        int low = 1, high = maxi - mini;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(canWePlace(mid, arr, k) == true){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};