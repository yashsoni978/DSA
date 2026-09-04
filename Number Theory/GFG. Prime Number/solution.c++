class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(n % i == 0) cnt++;
        }
        if(cnt == 2) return true;
        return false;
    }
};
//n and 1

class Solution {
  public:
    bool isPrime(int n) {
        // code here
        int cnt = 0;
        for(int i=1; i*i<=n; i++){
            if(n % i == 0){
                cnt++;
                if(n / i != i) cnt++;
            }
        }
        if(cnt == 2) return true;
        return false;
    }
};
//sqrt(n) and 1