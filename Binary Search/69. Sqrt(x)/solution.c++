class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int ans = 1;
        for(int i=1; i<=x; i++){
            if(1LL * i*i <= x) ans = i;
            else break;
        }
        return ans;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while(low <= high){
            int mid = low + (high-low) / 2;
            long long square = 1LL * mid * mid;
            if(square <= x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};