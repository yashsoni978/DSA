class Solution {
private:
    void solve(string &s, int k, int i, int j, int minutes, vector<int>& freq, int &res){
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k){
            res = min(res, minutes);
            return;
        }
        if(i > j) return;
        vector<int>tempFromLeft = freq;
        tempFromLeft[s[i] - 'a'] += 1;
        solve(s, k, i+1, j, minutes+1, tempFromLeft, res);

        vector<int>tempFromRight = freq;
        tempFromRight[s[j] - 'a'] += 1;
        solve(s, k, i, j-1, minutes+1, tempFromRight, res);
    }
public:
    int takeCharacters(string s, int k) {
        vector<int>freq(3,0);
        int i = 0, j = s.length() - 1;
        int minutes = 0;
        int res = INT_MAX;
        solve(s, k, i, j, minutes, freq, res);
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int cntA = 0, cntB = 0, cntC = 0;
        for(char &ch : s){
            if(ch == 'a') cntA++;
            else if(ch == 'b') cntB++;
            else cntC++;
        }
        if(cntA < k || cntB < k || cntC < k) return -1;
        int i=0, j=0, notDeletedWindowSize = 0;
        while(j < n){
            if(s[j] == 'a') cntA--;
            else if(s[j] == 'b') cntB--;
            else cntC--;
            while(i <= j && cntA < k || cntB < k || cntC < k){
                if(s[i] == 'a') cntA++;
                else if(s[i] == 'b') cntB++;
                else cntC++;
                i++;
            }
            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }
        return n - notDeletedWindowSize;
    }
};