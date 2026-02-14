class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        int m = items.size();
        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            int best = 0;
            for(int j=0; j<m; j++){
                if(items[j][0] <= queries[i]) best = max(best, items[j][1]);
            }
            ans[i] = best;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        int m = items.size();
        sort(items.begin(),items.end());
        vector<int>prefixMax(m);
        prefixMax[0] = items[0][1];
        for(int i=1; i<m; i++) prefixMax[i] = max(prefixMax[i-1], items[i][1]);
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int q = queries[i];
            int l = 0, r = m-1, idx = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(items[mid][0] <= q){
                    idx = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(idx != -1) ans[i] = prefixMax[idx];
            else ans[i] = 0;
        }
        return ans;
    }
};