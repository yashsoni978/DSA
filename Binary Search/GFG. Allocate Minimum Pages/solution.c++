/*To even hold a book someone needs minimum (element in the array) pages*/

class Solution {
  private:
    bool canAllocate(long long pages, vector<int>& arr, int k){
        long long currPages = 0;
        int students = 1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > pages) return false;
            if(currPages + arr[i] <= pages){
                currPages += arr[i];
            }
            else{
                students++;
                currPages = arr[i];
            }
        }
        return students <= k;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(canAllocate(mid, arr, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return (int)ans;
    }
};