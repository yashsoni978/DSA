class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(ans.size() == 0 || ans[0] != nums[i]){
                int cnt = 0;
                for(int j=0; j<n; j++){
                    if(nums[j] == nums[i]) cnt++;
                }
                if(cnt > n/3) ans.push_back(nums[i]);
            }
            if(ans.size() == 2) break;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();;
        vector<int>ans;
        unordered_map<int,int>mp;
        int mini = (int)(n/3) + 1;//to get rid of second loop to check for n/3 condn
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == mini) ans.push_back(nums[i]);
            if(ans.size() == 2) break;
        }
        return ans;
    }
};

class Solution {
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el1 = INT_MIN, el2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }
        vector<int>ans;
        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini) ans.push_back(el1);
        if(cnt2 >= mini) ans.push_back(el2);
        return ans;
    }
};