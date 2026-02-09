//we have to keep LCS intact
//no of insertions = s1.size() - len(LCS);
//no of deletions = s2.size() - len(LCS);
//s1.size() + s2.size() - 2*lcs(s1,s2);
class Solution {
  private:
    int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int>prev(m+1,0);
        for(int j=0; j<=m; j++) prev[j] = 0;
        for(int ind1=1; ind1<=n; ind1++){
            vector<int>curr(m+1,0);
            for(int ind2=1; ind2<=m; ind2++){
                if(text1[ind1 - 1] == text2[ind2 - 1]) curr[ind2] = 1 + prev[ind2-1];
                else curr[ind2] = max(prev[ind2], curr[ind2-1]); 
            }
            prev = curr;
        }
        return prev[m];
    }
  public:
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        return s1.size() + s2.size() - 2 * lcs(s1,s2);
    }
};