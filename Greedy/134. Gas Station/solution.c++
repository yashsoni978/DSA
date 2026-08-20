class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0; i<n; i++){
            if(gas[i] < cost[i]) continue;
            int j = (i+1)%n;
            int currGas = gas[i];
            currGas = currGas - cost[i] + gas[j];
            while(j != i){
                if(currGas < cost[j]) break;
                currGas = currGas - cost[j]; 
                j = (j+1)%n;
                currGas = currGas + gas[j]; 
            }
            if(j == i) return i;
        }
        return -1;
    }
};

/*// If total becomes negative at i, every station from result to i cannot be a valid start.
// Greedily skip them all and choose i+1 as the next starting point.*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalGas < totalCost) return -1;
        int total = 0, res = 0;
        for(int i=0; i<n; i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                res = i + 1;
            }
        }
        return res;
    }
};