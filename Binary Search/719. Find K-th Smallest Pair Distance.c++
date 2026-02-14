class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>distances;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) distances.push_back(abs({nums[i] - nums[j]}));
        }
        sort(distances.begin(),distances.end());
        return distances[k-1];
    }
};

class Solution {
private:
    bool possible(int dist, vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i] - nums[j]) <= dist) cnt++;
            }
        }
        return cnt >= k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int smallestDistance = 0;
        for(int dist=0; dist<=maxi-mini; dist++){
            if(possible(dist, nums, k)){
                smallestDistance = dist;
                break; //first distance satisfying condition
            }
        }
        return smallestDistance;
    }
};

//TLE 
class Solution {
private:
    bool possible(int dist, vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i] - nums[j]) <= dist) cnt++;
            }
        }
        return cnt >= k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int smallestDistance = 0;
        int l = 0, r = maxi - mini;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(mid, nums, k)){
                smallestDistance = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return smallestDistance;
    }
};

class Solution {
private:
    bool possible(int dist, vector<int>& nums, int k){
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = 0;
        while(r < n){
            while(nums[r] - nums[l] > dist) l++;
            cnt += (r - l);
            r++;
        }
        return cnt >= k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int smallestDistance = 0;
        int l = 0, r = maxi - mini;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(mid, nums, k)){
                smallestDistance = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return smallestDistance;
    }
};