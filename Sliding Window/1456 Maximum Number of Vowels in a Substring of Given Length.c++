class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxCnt = 0;
        for(int i=0; i<=n-k; i++){
            int cnt = 0;
            for(int j=i; j<i+k; j++){
                if(isVowel(s[j])) cnt++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, cntVowels = 0, maxVowels = 0;
        while(r < n){
            if(isVowel(s[r])) cntVowels++;
            if(r-l+1 == k){
                maxVowels = max(maxVowels, cntVowels);
                if(isVowel(s[l])) cntVowels--;
                l++;
            }
            r++;
        }
        return maxVowels;
    }
};