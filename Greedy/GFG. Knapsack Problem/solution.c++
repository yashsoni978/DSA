class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double,int>>items;
        for(int i=0; i<n; i++){
            double ratio = (double)val[i]/wt[i];
            items.push_back({ratio, i});
        }
        sort(items.begin(), items.end(), greater<pair<double,int>>());
        double maxValue = 0;
        for(int i=0; i<n; i++){
            int idx = items[i].second;
            if(wt[idx] <= capacity){
                maxValue += val[idx];
                capacity -= wt[idx];
            }
            else{
                maxValue += items[i].first * capacity;
                break;
            }
        }
        return maxValue;
    }
};
