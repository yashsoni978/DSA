class Solution {
private:
    void solve(int idx, string& s1, string &s2, bool &res){
        int n = s1.length();
        if(idx == n){
            if(s2.find(s1) != string :: npos) res = true;
            return;
        }
        for(int i=idx; i < n; i++){
            swap(s1[i], s1[idx]);
            solve(idx+1, s1, s2, res);
            swap(s1[i], s1[idx]);
            if(res == true) return;
        }
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        bool res = false;
        solve(0, s1, s2, res);
        return res;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        string sortedS1 = s1;
        sort(sortedS1.begin(), sortedS1.end());
        for(int i=0; i<=(m-n); i++){
            string temp = s2.substr(i, n);
            sort(temp.begin(),temp.end());
            if(temp == sortedS1) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        vector<int>freqS1(26,0);
        vector<int>freqS2(26,0);
        for(int i=0; i<n; i++) freqS1[s1[i] - 'a']++;
        int i = 0, j = 0;
        while(j < m){
            freqS2[s2[j] - 'a']++;
            while(j-i+1 > n){
                freqS2[s2[i] - 'a']--;
                i++;
            }
            if(freqS1 == freqS2) return true;
            j++;
        }
        return false;
    }
};