class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            vector<int>hash(26,0);
            int maxF = 0;
            for(int j=i; j<n; j++){
                hash[s[j] - 'A']++;
                maxF = max(maxF, hash[s[j] - 'A']);
                int changes = (j-i+1) - maxF;
                if(changes <= k) maxLen = max(maxLen, j-i+1);
                else break;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxF = 0;
        vector<int>hash(26,0);
        int n = s.size();
        while(r < n){
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            while((r-l+1) - maxF > k){
                hash[s[l] - 'A']--;
                maxF = 0;
                for(int i=0; i<26; i++) maxF = max(maxF, hash[i]);
                l++;
            }
            if((r-l+1) - maxF <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

//O(N) + O(N) * 26

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxF = 0;
        vector<int>hash(26,0);
        int n = s.size();
        while(r < n){
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            while((r-l+1) - maxF > k){
                hash[s[l] - 'A']--;
                l++;
            }
            if((r-l+1) - maxF <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

//O(N) + O(N)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxF = 0;
        vector<int>hash(26,0);
        int n = s.size();
        while(r < n){
            hash[s[r] - 'A']++;
            maxF = max(maxF, hash[s[r] - 'A']);
            if((r-l+1) - maxF > k){
                hash[s[l] - 'A']--;
                l++;
            }
            if((r-l+1) - maxF <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};

//O(N)