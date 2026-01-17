class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        int maxLen = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            int distinct = 0;
            for(int j=i; j<n; j++){
                freq[s[j] - 'a']++;
                if(freq[s[j] - 'a'] == 1) distinct++;
                if(distinct == k) maxLen = max(maxLen, j-i+1);
                if(distinct > k) break;
            }
        }
        return maxLen == INT_MIN ? -1 : maxLen;
    }
};

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        int l = 0, r = 0, maxLen = -1, distinct = 0;
        vector<int>mp(26,0);
        while(r < n){
            mp[s[r] - 'a']++;
            if(mp[s[r] - 'a'] == 1) distinct++;
            if(distinct > k){
                mp[s[l] - 'a']--;
                if(mp[s[l] - 'a'] == 0) distinct--;
                l++;
            }
            if(distinct == k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};