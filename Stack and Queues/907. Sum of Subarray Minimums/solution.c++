class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        long long ans = 0;
        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=i; j<n; j++){
                mini = min(mini, arr[j]);
                ans = (ans + mini) % MOD;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        vector<int>psee(n), nse(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long contribution = (1LL * arr[i] * left % MOD) * right % MOD;
            ans = (ans + contribution) % MOD;
        }
        return ans;
    }
};

//5n and 5n