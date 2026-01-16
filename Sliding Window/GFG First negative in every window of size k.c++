class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        vector<int>ans;
        for(int i=0; i<=n-k; i++){
            bool found = false;
            for(int j=i; j<i+k; j++){
                if(arr[j] < 0){
                    ans.push_back(arr[j]);
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(0);
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        int i=0, j=0;
        deque<int>dq;
        vector<int>res;
        while(j < n){
            if(arr[j] < 0) dq.push_back(arr[j]);
            if(j - i + 1 == k){
                if(!dq.empty()) res.push_back(dq.front());
                else res.push_back(0);
                if(arr[i] < 0 && !dq.empty()) dq.pop_front();
                i++;
            }
            j++;
        }
        return res;
    }
};