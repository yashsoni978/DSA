/*Normal NGE:
→ Find NGE for every element of the same array.

NGE I:
→ Find NGE for nums2 using the normal monotonic stack.
→ Store the result in a map:
   element → its NGE
→ Use nums1 to query the map and build the answer.

Why map?
Because nums1 contains elements from nums2, so we can directly get:
mp[x] = NGE of x in nums2.

Flow:
nums2 → NGE using stack → map → query using nums1*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]) st.pop();
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) mp[nums2[i]] = nge[i];
        vector<int>ans;
        for(int x : nums1) ans.push_back(mp[x]);
        return ans;
    }
};