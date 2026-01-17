class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            int maxF = 0;
            for(int j=i; j<n; j++){
                freq[s[j] - 'A']++;
                maxF = max(maxF, freq[s[j] - 'A']);
                int changes = (j-i+1) - maxF;
                if(changes <= k) maxLen = max(maxLen, j-i+1);
                else break;
            }
        }
        return maxLen;
    }
};

//Recalculation of maxF tc : 0(N * 26);
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, maxLen = 0;
        vector<int>freq(26,0);
        while(r < n){
            freq[s[r] - 'A']++;
            int maxF = 0;
            for(int i=0; i<26; i++) maxF = max(maxF, freq[i]);
            int changes = (r-l+1) - maxF;
            if(changes > k){
                freq[s[l] - 'A']--;
                l++;
                maxF = 0;
                for(int i=0; i<26; i++) maxF = max(maxF, freq[i]);
                changes = (r-l+1) - maxF;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

//No recalculation of maxF tc : 0(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, maxLen = 0;
        vector<int>freq(26,0);
        while(r < n){
            freq[s[r] - 'A']++;
            int maxF = 0;
            for(int i=0; i<26; i++) maxF = max(maxF, freq[i]);
            int changes = (r-l+1) - maxF;
            if(changes > k){
                freq[s[l] - 'A']--;
                l++;
                changes = (r-l+1) - maxF;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};