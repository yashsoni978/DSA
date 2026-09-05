class Solution {
  private:
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
  public:
    vector<int> primeRange(int l, int r) {
        // code here
        vector<int>ans;
        for(int i=l; i<=r; i++){
            if(isPrime(i)) ans.push_back(i);
        }
        return ans;
    }
};

/*For each number → O(√R)

Total TC → O((R - L + 1) × √R)

SC → O(1) auxiliary
       O(K) including output*/

