class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            bool leader = true;
            for(int j=i+1; j<n; j++){
                if(arr[j] > arr[i]) leader = false;
            }
            if(leader == true) ans.push_back(arr[i]);
        }
        return ans;
    }
};
//n^2

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans;
        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(arr[i] >= maxi) ans.push_back(arr[i]);
            maxi = max(maxi, arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};