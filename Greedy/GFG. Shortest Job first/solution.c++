//sort it so that smallest execution time taken by that job gets finished first
class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        sort(bt.begin(), bt.end());
        int totalTime = 0, waitTime = 0;
        for(int i=0; i<n; i++){
            waitTime += totalTime;
            totalTime += bt[i];
        }
        return (waitTime)/n;
    }
};