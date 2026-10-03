class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long cnt = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            long XOR = 0;
            for(int j=i; j<n; j++){
                XOR ^= arr[j];
                if(XOR == k) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long xr = 0, cnt = 0;
        int n = arr.size();
        unordered_map<int,int>mp;
        mp[xr]++;
        for(int i=0; i<n; i++){
            xr ^= arr[i];
            long x = xr ^ k;
            cnt += mp[x];
            mp[xr]++;
        }
        return cnt;
    }
};