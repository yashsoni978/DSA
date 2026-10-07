class Solution {
private:
    bool linearSearch(vector<int>& nums, int num){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == num) return true;
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 0;
        for(int i=0; i<n; i++){
            int x = nums[i], cnt = 1;
            while(linearSearch(nums, x+1) == true){
                x = x+1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
//n^2

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int longest = 0;
        int cnt = 0, lastSmaller = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
//n log n + n

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int>st;
        for(int i=0; i<n; i++) st.insert(nums[i]);
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};