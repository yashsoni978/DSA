class Solution {
private:
    bool possible(int penalty, vector<int>& nums, int maxOperations){
        long long ops = 0;
        for(int q : nums){
            ops += (q-1) / penalty;
            if(ops > maxOperations) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxP = *max_element(nums.begin(),nums.end());
        int minPenalty = 0;
        for(int penalty = 1; penalty <= maxP; penalty++){
            if(possible(penalty, nums, maxOperations)){
                minPenalty = penalty;
                break;// we need least feasible
            }
        }
        return minPenalty;
    }
};

class Solution {
private:
    bool possible(int penalty, vector<int>& nums, int maxOperations){
        long long ops = 0;
        for(int q : nums){
            ops += (q-1) / penalty;
            if(ops > maxOperations) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxP = *max_element(nums.begin(),nums.end());
        int minPenalty = 0;
        int l = 1, r = maxP;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(mid, nums, maxOperations)){
                minPenalty = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return minPenalty;
    }
};