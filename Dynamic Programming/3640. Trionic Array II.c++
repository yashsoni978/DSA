//O(n^4)
class Solution {
private:
    bool isTrionic(vector<int>& nums, int start, int end){
        int n = nums.size();
        int i = start;
        while(i+1 <= end && nums[i] < nums[i+1]) i++;
        if(i == start) return false;
        int beforeDec = i;
        while(i+1 <= end && nums[i] > nums[i+1]) i++;
        if(i == beforeDec) return false;
        bool moved = false;
        while(i+1 <= end && nums[i] < nums[i+1]){
            i++;
            moved = true;
        }
        return moved && i == end;
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                for(int k=j; k<n; k++){
                    if(isTrionic(nums,i,k)){
                        long long sum = 0;
                        for(int l=i; l<=k; l++){
                            sum += nums[l];
                        }
                        maxSum = max(maxSum, sum);
                    }
                }
            }
        }
        return maxSum;
    }
};

//o(n^3)
class Solution {
private:
    bool isTrionic(vector<int>& nums, int start, int end){
        int i = start;
        while(i+1 <= end && nums[i] < nums[i+1]) i++;
        if(i == start) return false;
        int beforeDec = i;
        while(i+1 <= end && nums[i] > nums[i+1]) i++;
        if(i == beforeDec) return false;
        bool moved = false;
        while(i+1 <= end && nums[i] < nums[i+1]){
            i++;
            moved = true;
        }
        return moved && i == end;
    }
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        vector<long long>pSum(n+1,0);
        for(int i=0; i<n; i++) pSum[i+1] = pSum[i] + nums[i];
        for(int i=0; i<n; i++){
            for(int k=i; k<n; k++){
                if(isTrionic(nums,i,k)){
                    long long sum = pSum[k+1] - pSum[i];
                    maxSum = max(sum, maxSum);
                }
            }
        }
        return maxSum;
    }
};

class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums) {
        if(i == n) {
            if(trend == 3) {
                return 0; //no more elements, you reached out of bound
            } else {
                return LLONG_MIN/2; //invalid small value
            }
        }

        if(memo[i][trend] != LLONG_MIN) {
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        //skip
        if(trend == 0) {
            skip = solve(i+1, 0, nums);
        }

        //i am at trend 3 and i can now end at nums[i]
        if(trend == 3) {
            take = nums[i]; //finish it here
        }

        if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1, nums));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1, nums));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }
        
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        memo.assign(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums); //solve(i, trend = 0)
    }
};