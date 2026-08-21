class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        vector<bool>seen(256,false);
        string ans;
        for(char ch : s){
            if(!seen[ch]){
                ans += ch;
                seen[ch] = true;
            }
        }
        return ans;
    }
};