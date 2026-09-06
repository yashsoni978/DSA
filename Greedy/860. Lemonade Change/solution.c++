class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, tens = 0;
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five){
                    five--;
                    tens++;
                }
                else return false;
            }
            else{
                if(five && tens){
                    five--;
                    tens--;
                }
                else if(five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};

/*┌──────────────────────────────────────────────┐
│ 🟢 GREEDY IDEA                               │
│                                              │
│ For a $20 bill, always prefer:               │
│                                              │
│        $10 + $5  →  instead of  $5+$5+$5     │
│                                              │
│ Why? Keep more $5 bills for future customers.│
│                                              │
│ So, at every step, make the best local       │
│ choice that preserves future options.        │
└──────────────────────────────────────────────┘*/