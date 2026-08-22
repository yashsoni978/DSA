class Solution {
  private:
    int helper(int mid, int n, int m){
        long long ans = 1;
        for(int i=1; i<=n; i++){
            ans *= mid;
            if(ans > m) return 2;
        }
        if(ans == m) return 1;
        return 0;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0) return 0;
        int low = 1, high = m;
        while(low <= high){
            int mid = (low + high)/2;
            if(helper(mid, n, m) == 1) return mid;
            else if(helper(mid, n, m) == 0) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};