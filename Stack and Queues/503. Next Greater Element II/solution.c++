class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n, -1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<i+n; j++){
                int idx = j % n;
                if(nums[idx] > nums[i]){
                    nge[i] = nums[idx];
                    break;
                }
            }
        }
        return nge;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>nge(n);
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            if(i < n){
                if(st.empty()) nge[i] = -1;
                else nge[i] = st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
};

//4n and 2n