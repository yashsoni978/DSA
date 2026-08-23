class Solution {
private:
    bool canMake(int days, vector<int>& bloomDay, int m, int k){
        int noOfBouquets = 0;
        int cnt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days) cnt++;
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        if(noOfBouquets >= m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        for(int i=low; i<=high; i++){
            if(canMake(i, bloomDay, m, k)) return i;
        }
        return -1;
    }
};

class Solution {
private:
    bool canMake(int days, vector<int>& bloomDay, int m, int k){
        int noOfBouquets = 0;
        int cnt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= days) cnt++;
            else{
                noOfBouquets += (cnt/k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt/k);
        if(noOfBouquets >= m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(canMake(mid, bloomDay, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};