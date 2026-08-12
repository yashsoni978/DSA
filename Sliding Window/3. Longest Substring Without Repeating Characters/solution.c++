class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
                mp[s[j]]++;
                if(mp[s[j]] > 1) break;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0, maxLen = 0, l = 0, r = 0;
        vector<int>hash(256,-1);
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l) l = hash[s[r]] + 1;
            }
            len = r-l+1;
            maxLen = max(maxLen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
