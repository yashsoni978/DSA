class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int totalProfit = 0;
        for(int j=0; j<worker.size(); j++){
            int best = 0;
            for(int i=0; i<difficulty.size(); i++){
                if(worker[j] >= difficulty[i]) best = max(best, profit[i]);
            }
            totalProfit += best;
        }
        return totalProfit;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>>jobs;
        for(int i=0; i<n; i++) jobs.push_back({difficulty[i],profit[i]});
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int i = 0, maxProfitSeenSoFar = 0, totalProfit = 0;
        for(int w : worker){
            while(i < n && jobs[i].first <= w){
                maxProfitSeenSoFar = max(maxProfitSeenSoFar, jobs[i].second);   
                i++;
            }
            totalProfit += maxProfitSeenSoFar;
        }
        return totalProfit;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>>jobs;
        for(int i=0; i<n; i++) jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(),jobs.end());
        vector<int>prefixMax(n);
        prefixMax[0] = jobs[0].second;
        for(int i=1; i<n; i++) prefixMax[i] = max(prefixMax[i-1], jobs[i].second);
        int totalProfit = 0;
        for(int w : worker){
            int l = 0, r = n-1;
            int idx = -1;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(jobs[mid].first <= w){
                    idx = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(idx != -1) totalProfit += prefixMax[idx];
        }
        return totalProfit;
    }
};