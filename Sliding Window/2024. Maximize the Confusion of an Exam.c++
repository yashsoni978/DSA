class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int ans = 0;
        for(int i=0; i<n; i++){
            int tCnt = 0, fCnt = 0;
            for(int j=i; j<n; j++){
                if(answerKey[j] == 'T') tCnt++;
                else fCnt++;
                if(min(tCnt, fCnt) <= k) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0, r = 0, res = 0;
        int cntF = 0;
        while(r < n){
            if(answerKey[r] == 'F') cntF++;
            if(cntF > k){
                if(answerKey[l] == 'F') cntF--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        int cntT = 0;
        l = 0, r = 0;
        while(r < n){
            if(answerKey[r] == 'T') cntT++;
            if(cntT > k){
                if(answerKey[l] == 'T') cntT--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int i = 0, j = 0, maxLen = 0;
        int cntT = 0, cntF = 0;
        while(j < n){
            if(answerKey[j] == 'T') cntT++;
            else cntF++;
            if(min(cntT, cntF) > k){
                if(answerKey[i] == 'T') cntT--;
                else cntF--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};

//Same as upper
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = k;
        
        unordered_map<char, int> mp;

        int i = 0;
        for (int j = 0; j < answerKey.length(); j++) {

            mp[answerKey[j]]++;
            
            while (min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }
            
            result = max(result, j - i + 1);
        }
        
        return result;
    }
};