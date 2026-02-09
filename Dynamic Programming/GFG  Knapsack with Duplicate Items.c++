class Solution {
  public:
  // code same as 0/1 knapsack just two changes base case and use of curr
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<int>prev(capacity+1,0);
        //Memo base case
        /*if(ind == 0){
    return (capacity / wt[0]) * val[0];
}*/
        for(int w=0; w<=capacity; w++) prev[w] = (w / wt[0]) * val[0];//we can pick an element multiple times
        for(int ind=1; ind < n; ind++){
            vector<int>curr(capacity+1,0);
            for(int weight=1; weight<=capacity; weight++){
                int notTake = prev[weight];
                int take = INT_MIN;
                if(wt[ind] <= weight) take = val[ind] + curr[weight - wt[ind]];//use curr instead of prev because we can take an item multiple times
                curr[weight] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};