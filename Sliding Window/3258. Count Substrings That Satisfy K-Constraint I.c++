class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int cnt0 = 0, cnt1 = 0;
            for(int j=i; j<n; j++){
                if(s[j] == '0') cnt0++;
                else if(s[j] == '1') cnt1++;
                if(cnt0 <= k || cnt1 <= k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, cnt = 0, cnt0 = 0, cnt1 = 0;
        while(r < n){
            if(s[r] == '0') cnt0++;
            else if(s[r] == '1') cnt1++;
            while(cnt0 > k && cnt1 > k){
                if(s[l] == '0') cnt0--;
                else if(s[l] == '1') cnt1--;
                l++;
            } 
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};