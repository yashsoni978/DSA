class StockSpanner {
public:
    vector<int>prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int span = 1;
        int i = prices.size() - 2;//no need to count correct
        while(i >= 0 && prices[i] <= price){
            span++;
            i--;
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//no of days, total no of next calls

class StockSpanner {
public:
    stack<pair<int,int>>st; 
    int idx = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        idx++;
        while(!st.empty() && st.top().first <= price) st.pop();
        int pge = st.empty() ? -1 : st.top().second;
        st.push({price, idx});
        return idx - pge;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
//2n and n