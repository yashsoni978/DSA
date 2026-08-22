class Solution {
  private:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0, high = arr.size() - 1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int lb = lowerBound(arr, x);
        if(lb == n || arr[lb] != x) return {-1,-1};
        return {lb, upperBound(arr, x) - 1};
    }
};

class Solution {
  private:
    int firstOccurence(vector<int>& arr, int x){
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == x){
                ans = mid;
                high = mid - 1;
            }
            else if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
    int lastOccurence(vector<int>& arr, int x){
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == x){
                ans = mid;
                low = mid + 1;
            }
            else if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int first = firstOccurence(arr, x);
        if(first == -1) return {-1,-1};
        int last = lastOccurence(arr, x);
        return {first, last};
    }
};