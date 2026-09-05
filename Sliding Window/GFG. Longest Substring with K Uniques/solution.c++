class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int maxLen = -1;
        int n = s.size();
        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
                mp[s[j] - 'a']++;
                if(mp.size() == k) maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int l = 0, r = 0, maxLen = -1;
        unordered_map<int,int>mp;
        while(r < n){
            mp[s[r] - 'a']++;
            while(mp.size() > k){
                mp[s[l] - 'a']--;
                if(mp[s[l] - 'a'] == 0) mp.erase(s[l] - 'a');
                l++;
            }
            if(mp.size() == k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int l = 0, r = 0, maxLen = -1;
        unordered_map<int,int>mp;
        while(r < n){
            mp[s[r] - 'a']++;
            if(mp.size() > k){
                mp[s[l] - 'a']--;
                if(mp[s[l] - 'a'] == 0) mp.erase(s[l] - 'a');
                l++;
            }
            if(mp.size() == k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};