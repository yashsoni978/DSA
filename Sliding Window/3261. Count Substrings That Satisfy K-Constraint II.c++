class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long>res;
        for(auto &q : queries){
            int l = q[0], r = q[1];
            long long cnt = 0;
            for(int i=l; i<=r; i++){
                int cnt0 = 0, cnt1 = 0;
                for(int j=i; j<=r; j++){
                    if(s[j] == '0') cnt0++;
                    else if(s[j] == '1') cnt1++;
                    if(cnt0 <= k || cnt1 <= k) cnt++;
                    else break;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int>leftMost(n,0),rightMost(n,0);
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        while(j < n){
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k){
                mp[s[i]]--;
                i++;
            }
            leftMost[j] = i;
            j++;
        }
        mp.clear();
        i = n-1, j = n-1;
        while(j >= 0){
            mp[s[j]]++;
            while(mp['0'] > k && mp['1'] > k){
                mp[s[i]]--;
                i--;
            }
            rightMost[j] = i;
            j--;
        }
        vector<int>tempValidSubstr(n,0);
        for(int j=0; j<n; j++) tempValidSubstr[j] = j - leftMost[j] + 1;
        vector<long long>cumSum(n,0);
        cumSum[0] = tempValidSubstr[0];
        for(int i=1; i<n; i++) cumSum[i] = cumSum[i-1] + tempValidSubstr[i];
        vector<long long>res;
        for(vector<int>& query : queries){
            int low = query[0], high = query[1];
            int validRightIdx = min(high, rightMost[low]);
            long long length = validRightIdx - low + 1;
            long long tempRes = length * (length + 1) / 2;
            tempRes += cumSum[high] - cumSum[validRightIdx];
            res.push_back(tempRes);
        }
        return res;
    }
};