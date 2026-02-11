class Solution {
private:
    bool canRun(long long T, int n, vector<int>& batteries){
        long long total = 0;
        for(long long b : batteries) total += min(b, T);
        return total >= 1LL * n * T;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int b : batteries) sum += b;
        long long maxTime = sum / n;
        long long ans = 0;
        for(long long T = 1; T <= maxTime; T++){
            if(canRun(T, n, batteries)) ans = T;
            else break;
        }
        return ans;
    }
};

class Solution {
private:
    bool canRun(long long T, int n, vector<int>& batteries){
        long long total = 0;
        for(long long b : batteries) total += min(b,T);
        return total >= 1LL * n * T;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(long long b : batteries) sum += b;
        long long maxTime = sum/n;
        long long maxMinutes = 0;
        long long l = 1, r = maxTime;
        while(l <= r){
            long long mid = l + (r-l) / 2;
            if(canRun(mid, n, batteries)){
                maxMinutes = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return maxMinutes;
    }
};

class Solution {
private:
    bool canRun(long long T, int n, vector<int>& batteries){
        long long total = 0;
        for(long long b : batteries) total += min(b,T);
        return total >= 1LL * n * T;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(long long b : batteries) sum += b;
        long long maxTime = sum/n;
        long long maxMinutes = 0;
        long long l = 1, r = maxTime;
        while(l <= r){
            long long mid = l + (r-l) / 2;
            if(canRun(mid, n, batteries)){
                maxMinutes = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return maxMinutes;
    }
};