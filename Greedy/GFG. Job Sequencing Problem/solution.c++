class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>>jobs;
        int n = deadline.size();
        for(int i=0; i<n; i++) jobs.push_back({profit[i], deadline[i]});
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int>slot(maxDeadline+1, -1);
        int cntJobs = 0, maxProfit = 0;
        for(int i=0; i<n; i++){
            int d = jobs[i].second;
            for(int j=d; j>0; j--){
                if(slot[j] == -1){
                    slot[j] = 1;
                    maxProfit += jobs[i].first;
                    cntJobs++;
                    break;
                }
            }
        }
        return {cntJobs, maxProfit};
    }
};

/*Time Complexity
Creating jobs: O(n)
Sorting jobs: O(n log n)
Finding maximum deadline: O(n)
For each job, you may scan backward through the slots up to its deadline: O(n) in the worst case.
Across all n jobs: O(n²)

Therefore:

TC = O(n log n + n²)
   = O(n²)
Space Complexity
jobs → O(n)
slot → O(maxDeadline), and maxDeadline ≤ n

Therefore:

SC = O(n)*/