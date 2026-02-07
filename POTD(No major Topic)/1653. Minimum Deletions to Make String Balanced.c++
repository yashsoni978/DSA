class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int ans = INT_MAX;
        for(int i=0; i<=n; i++){
            int leftB = 0, rightA = 0;
            for(int j=0; j<i; j++){
                if(s[j] == 'b') leftB++;
            }
            for(int j=i; j<n; j++){
                if(s[j] == 'a') rightA++;
            }
            ans = min(ans, leftB + rightA);
        }
        return ans;
    }
};

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>prefixB(n,0),suffixA(n,0);
        prefixB[0] = 0;
        for(int i=1; i<n; i++) prefixB[i] = prefixB[i-1] + (s[i-1] == 'b');
        suffixA[n-1] = 0;
        for(int i=n-2; i>=0; i--) suffixA[i] = suffixA[i+1] + (s[i+1] == 'a');
        int ans = INT_MAX;
        for(int i=0; i<n; i++) ans = min(ans, prefixB[i] + suffixA[i]);
        return ans; 
    }
};

class Solution {
public:
    int minimumDeletions(string s) {
        int aRemain = 0;
        for(char ch : s){
            if(ch == 'a') aRemain++;
        }
        int ans = aRemain, bCnt = 0;
        for(char ch : s){
            if(ch == 'a') aRemain--;
            else bCnt++;
            ans = min(ans, aRemain + bCnt);
        }  
        return ans;
    }
};