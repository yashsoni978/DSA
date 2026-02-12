class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            for(int j=i; j<n; j++){
                freq[s[j] - 'a']++;
                int distinct = 0, maxFreq = 0, minFreq = INT_MAX;
                for(int k=0; k<26; k++){
                    if(freq[k] > 0){
                        distinct++;
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }
                if(maxFreq == minFreq) maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            int distinct = 0, maxFreq = 0;
            for(int j=i; j<n; j++){
                int idx = s[j] - 'a';
                if(freq[idx] == 0) distinct++;
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);
                int len = j-i+1;
                if(maxFreq * distinct == len) ans = max(ans, len);
            }
        }
        return ans;
    }
};