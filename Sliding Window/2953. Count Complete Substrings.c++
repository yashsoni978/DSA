class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int res = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            for(int j=i; j<n; j++){
                if(j > i && abs(word[j] - word[j-1]) > 2) break;
                freq[word[j] - 'a']++;
                int len = (j-i+1);
                if(len % k != 0) continue;
                bool isComplete = true;
                for(int c=0; c<26; c++){
                    if(freq[c] != 0 && freq[c] != k){
                        isComplete = false;
                        break;
                    }
                }
                if(isComplete) res++;
            }
        }
        return res;
    }
};

class Solution {
private:
    int solve(int start, int end, string &word, int k){
        int res = 0;
        for(int uniqueChars = 1; uniqueChars <= 26 && uniqueChars * k <= end - start + 1; uniqueChars++){
            vector<int>cnt(26,0);
            int goodChars = 0;
            int i = start, windowLength = uniqueChars * k;
            for(int j = start; j <= end; j++){
                char ch = word[j];
                cnt[ch - 'a']++;
                if(cnt[ch - 'a'] == k) goodChars++;
                else if(cnt[ch - 'a'] == k+1) goodChars--;
                if(j - i + 1 > windowLength){
                    if(cnt[word[i] - 'a'] == k) goodChars--;
                    else if(cnt[word[i] - 'a'] == k+1) goodChars++;
                    cnt[word[i] - 'a']--;
                    i++;
                }
                if(goodChars == uniqueChars) res++;
            }
        }
        return res;
    }
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int res = 0, last = 0;
        for(int i=1; i<= n; i++){
            if(i == n || abs(word[i] - word[i-1]) > 2){
                res += solve(last, i-1, word, k);
                last = i; 
            }
        }
        return res;
    }
};