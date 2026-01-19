class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int cost = 0;
            for(int j=i; j<n; j++){
                cost += abs(s[j] - t[j]);
                if(cost <= maxCost) maxLen = max(maxLen, j-i+1);
                else break;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int l = 0, r = 0, maxLen = 0, cost = 0;
        while(r < n){
            cost += abs(s[r] - t[r]);
            while(cost > maxCost){
                cost -= abs(s[l] - t[l]);
                l++; 
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};