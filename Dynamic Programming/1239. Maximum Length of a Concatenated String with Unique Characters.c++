class Solution {
private:
    bool hasDuplicate(string &s1, string &s2){
        vector<int>arr(26,0);
        for(char &ch : s1){
            if(arr[ch - 'a'] > 0) return true;
            arr[ch - 'a']++;
        }
        for(char &ch : s2){
            if(arr[ch - 'a'] > 0) return true;
        }
        return false;
    }
    int solve(int i, vector<string>& arr, string temp, int n, unordered_map<string,int>& mp){
        if(i >= n) return temp.length();
        if(mp.find(temp) != mp.end()) return mp[temp];
        int exclude = 0, include = 0;
        if(hasDuplicate(arr[i], temp)){
            exclude = solve(i+1, arr, temp, n, mp);
        }
        else{
            exclude = solve(i+1, arr, temp, n, mp);
            include = solve(i+1, arr, temp + arr[i], n, mp);
        }
        return mp[temp] = max(include, exclude);
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        unordered_map<string,int>mp;
        mp.clear();
        return solve(0, arr, temp, n, mp);
    }
};

