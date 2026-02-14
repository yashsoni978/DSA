class Solution {
private:
    bool possible(int x, int n, vector<int>& quantities){
        long long stores = 0;
        for(int q : quantities) stores += (q+x-1)/x;    
        return stores <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxQ = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        for(int x=1; x<=maxQ; x++){
            if(possible(x, n, quantities)){
                ans = x;
                break; //we want smallest feasible
            }
        }
        return ans;
    }
};


class Solution {
private:
    bool possible(int x, int n, vector<int>& quantities){
        long long stores = 0;
        for(int q : quantities) stores += (q+x-1)/x;    
        return stores <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxQ = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        int l = 1, r = maxQ;
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(possible(mid, n, quantities)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};