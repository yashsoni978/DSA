class Solution {
private:
    bool canEat(int hours, vector<int>& piles, int h){
        long long totalHours = 0;
        for(int i=0; i<piles.size(); i++){
            totalHours += ceil((double)piles[i] / hours);
        }
        return totalHours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        for(int i=low; i<=high; i++){
            if(canEat(i, piles, h)){
                ans = i;
                break;
            }
        }
        return ans;
    }
};

class Solution {
private:
    bool canEat(int hours, vector<int>& piles, int h){
        long long totalHours = 0;
        for(int i=0; i<piles.size(); i++){
            totalHours += ceil((double)piles[i] / hours);
        }
        return totalHours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(canEat(mid, piles, h)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};