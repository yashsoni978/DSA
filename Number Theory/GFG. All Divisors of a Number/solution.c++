class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int>arr;
        for(int i=1; i<=n; i++){
            if(n % i == 0) arr.push_back(i);
        }
        return arr;
    }
};

//n and 1

class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int>ans;
        for(int i=1; i*i <= n; i++){
            if(n % i == 0){
                ans.push_back(i);
                if(n / i != i) ans.push_back(n / i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//sqrt(n) + log n