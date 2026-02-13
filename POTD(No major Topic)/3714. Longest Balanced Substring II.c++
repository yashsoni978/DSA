class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(3,0);
            int distinct = 0, maxFreq = 0;
            for(int j=i; j<n; j++){
                int idx = s[j] - 'a';
                if(freq[idx] == 0) distinct++;
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);
                int len = j-i+1;
                if(maxFreq * distinct == len) maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

class Solution {
private:
    int helper(string&s, char ch1, char ch2){
        int n = s.length();
        unordered_map<int,int>diffMap;
        int maxL = 0, cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(s[i] != ch1 && s[i] != ch2){
                diffMap.clear();
                cnt1 = 0;
                cnt2 = 0;
                continue;
            }
            if(s[i] == ch1) cnt1++;
            if(s[i] == ch2) cnt2++;
            if(cnt1 == cnt2) maxL = max(maxL, cnt1 + cnt2);
            int diff = cnt1 - cnt2;
            if(diffMap.count(diff)) maxL = max(maxL, i - diffMap[diff]);
            else diffMap[diff] = i;
        }
        return maxL;
    }
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxL = 0;
        //case = 1
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                maxL = max(maxL, cnt);
                cnt = 1;
            }
        }
        maxL = max(maxL, cnt);
        //case = 2
        maxL = max(maxL, helper(s, 'a', 'c'));
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'b', 'c'));
        //case = 3
        int cntA = 0, cntB = 0, cntC = 0;
        unordered_map<string,int>diffMap;
        for(int i=0; i<n; i++){
            if(s[i] == 'a') cntA++;
            if(s[i] == 'b') cntB++;
            if(s[i] == 'c') cntC++;
            if(cntA == cntB && cntA == cntC) maxL = max(maxL, cntA + cntB + cntC);
            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;
            string key = to_string(diffAB) + " " + to_string(diffAC);
            if(diffMap.count(key)) maxL = max(maxL, i - diffMap[key]);
            else diffMap[key] = i;
        }
        return maxL;
    }
};