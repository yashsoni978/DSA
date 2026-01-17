class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(256,0);
            for(int j=i; j<n; j++){
                freq[s[j]]++;
                if(freq[s[j]] > 1) break;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int>hash(256,-1);
        int l = 0, r = 0, maxLen = 0;
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l) l = 1 + hash[s[r]];
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};