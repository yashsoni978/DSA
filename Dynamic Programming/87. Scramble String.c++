class Solution {
private:
    int solve(string s1, string s2, unordered_map<string,bool>& mp){
        if(s1 == s2) return true;
        if(s1.length() != s2.length()) return false;
        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end()) return mp[key];
        bool res = false;
        int n = s1.length();
        for(int i=1; i<n; i++){
            bool swapped = solve(s1.substr(0,i), s2.substr(n-i, i), mp) && solve(s1.substr(i, n-i), s2.substr(0, n-i), mp);
            if(swapped){
                res = true;
                break;
            }
            bool notSwapped = solve(s1.substr(0,i), s2.substr(0, i), mp) && solve(s1.substr(i, n-i), s2.substr(i, n-i), mp);
            if(notSwapped){
                res = true;
                break;
            }
        }
        return mp[key] = res;
    }
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>mp;
        mp.clear();
        return solve(s1, s2, mp);
    }
};