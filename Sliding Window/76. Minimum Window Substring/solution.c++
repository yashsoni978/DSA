class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        int minLen = INT_MAX, sIndex = -1;
        for(int i=0; i<n; i++){
            vector<int>mp(256,0);
            int cnt = 0;
            for(int k=0; k<m; k++) mp[t[k]]++;
            for(int j=i; j<n; j++){
                if(mp[s[j]] > 0) cnt++;
                mp[s[j]]--;
                if(cnt == m){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        sIndex = i;
                        break;
                    }
                }
            }
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minLen = INT_MAX, l = 0, r = 0, cnt = 0, sIndex = -1;
        vector<int>hash(256,0);
        for(int i=0; i<m; i++) hash[t[i]]++;//m
        while(r < n){//n
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while(cnt == m){//n
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

//2n + m