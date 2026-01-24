class Solution {
private:
    bool isUgly(int n, unordered_map<int, bool>& mp){
        if(n <= 0) return false;
        if(n == 1) return true;
        if(mp.find(n) != mp.end()) return mp[n];
        if(n%2 == 0 && isUgly(n/2, mp)) return mp[n] = true;
        else if(n%3 == 0 && isUgly(n/3, mp)) return mp[n] = true;
        else if(n%5 == 0 && isUgly(n/5, mp)) return mp[n] = true;
        return mp[n] = false;
    }
public:
    int nthUglyNumber(int n) {
        unordered_map<int, bool>mp;
        mp.clear();
        int num = 1;
        while(n > 0){
            if(isUgly(num, mp)) n--;
            num++;
        }
        return num-1;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i=2; i<=n; i++){
            int two = dp[p2]*2;
            int three = dp[p3]*3;
            int five = dp[p5]*5;
            dp[i] = min({two, three, five});
            if(dp[i] == two) p2++;
            if(dp[i] == three) p3++;
            if(dp[i] == five) p5++;            
        }
        return dp[n];
    }
};