class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int>pairs(n,0);
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                long long product = 1LL * spells[i] * potions[j];
                if(product >= success) cnt++; 
            }
            pairs[i] = cnt;
        }
        return pairs;
    }
};

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        int maxPotion = potions[m-1];
        vector<int>ans;
        for(int i=0; i<n; i++){
            int spell = spells[i];
            long long minPotion = ceil((1.0*success)/spell);
            if(minPotion > maxPotion){
                ans.push_back(0);
                continue;
            }
            int idx = lower_bound(potions.begin(),potions.end(),minPotion) - potions.begin();
            ans.push_back(m-idx); 
        }
        return ans;
    }
};

class Solution {
private:
    int bs(int l, int r, vector<int>& potions, int target){
        int index = -1;
        int mid = 0;
        while(l <= r){
            mid = l + (r-l)/2;
            if(potions[mid] >= target){
                index = mid;
                r = mid - 1;// we need least value >= target
            }
            else l = mid + 1;
        }
        return index;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        int maxPotion = potions[m-1];
        vector<int>ans;
        for(int i=0; i<n; i++){
            int spell = spells[i];
            long long minPotion = ceil((1.0*success)/spell);
            if(minPotion > maxPotion){
                ans.push_back(0);
                continue;
            }
            int idx = bs(0, m-1, potions, minPotion);
            ans.push_back(m-idx); 
        }
        return ans;
    }
};