class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int x = minutes;
        int base = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0) base += customers[i];
        }
        int res = 0;
        for(int i=0; i<=n-x; i++){
            int extra = 0;
            for(int j=i; j<i+x; j++){
                if(grumpy[j] == 1) extra += customers[j];
            }
            res = max(res, base + extra);
        }
        return res;
    }
};

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unsat = 0;
        for(int i=0; i<minutes; i++) unsat += customers[i] * grumpy[i];
        int maxUnsat = unsat;
        int i = 0, j = minutes;
        while(j < n){
            unsat += customers[j] * grumpy[j];
            unsat -= customers[i] * grumpy[i];
            maxUnsat = max(maxUnsat, unsat);
            i++;
            j++;
        }
        int totalCustomers = maxUnsat;
        for(int i=0; i<n; i++) totalCustomers += customers[i] * (1 - grumpy[i]);
        return totalCustomers;
    }
};