class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int minLen = INT_MAX, sIndex = -1;
        for(int i = 0; i < n; i++){
            vector<int>freq(256,0);
            int cnt = 0;
            for(int k=0; k<m; k++) freq[t[k]]++;
            for(int j=i; j<n; j++){
                if(freq[s[j]] > 0) cnt++;
                freq[s[j]]--;
                if(cnt == m){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int>freq(256,0);
        for(int i=0; i<m; i++) freq[t[i]]++;
        int l = 0, r = 0, minLen = INT_MAX, sIndex = -1, cnt = 0;
        while(r < n){
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};