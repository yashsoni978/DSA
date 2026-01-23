class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_set<char>vowels = {'a', 'e', 'i', 'o', 'u'};
        long long cnt = 0;
        for(int i=0; i<n; i++){
            unordered_map<char, int>vowelCnt;
            int consonants = 0;
            for(int j=i; j<n; j++){
                char ch = word[j];
                if(vowels.count(ch)) vowelCnt[ch]++;
                else consonants++;
                if(vowelCnt.size() == 5 && consonants == k) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
    }
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char,int>mp;
        vector<int>nextConsIdx(n);
        int lastConsIdx = n;
        for(int i = n-1; i>=0; i--){
            nextConsIdx[i] = lastConsIdx;
            if(!isVowel(word[i])) lastConsIdx = i;
        }
        int i = 0, j = 0;
        long long cnt = 0;
        int cons = 0;
        while(j < n){
            char ch = word[j];
            if(isVowel(ch)) mp[ch]++;
            else cons++;
            while(cons > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }
                else cons--;
                i++;
            }
            while(i < n && mp.size() == 5 && cons == k){
                int idx = nextConsIdx[j];
                cnt += (idx - j);
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }
                else cons--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};