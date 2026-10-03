class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int>temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};
//n^3 * log(no of unique triplets)
//2 * no of unique triplets

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            set<int>hashSet;
            for(int j=i+1; j<n; j++){
                int third = - (nums[i] + nums[j]);
                if(hashSet.find(third) != hashSet.end()){
                    vector<int>temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};

//n^2 * log(triplets) can use unordered set also
//2 * no of unique triplets + n

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());// to avoid using sets
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
//n log n + n^2
//no of unique triplets