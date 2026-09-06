/* Instead of giving a child a large cookie that could satisfy someone with a higher greed factor, you give them the smallest cookie possible that still meets their specific greed requirement

By sorting both the children's greed factors and the cookie sizes in ascending order, you can iterate through them using a two-pointer approach. This allows you to "match" the smallest available cookie to the child with the smallest greed requirement, saving larger cookies for children who actually need them 
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();
        int l = 0, r = 0;
        while(l < m && r < n){
            if(g[r] <= s[l]) r++;
            l++;
        }
        return r;
    }
};

//m + nlogn + mlogm
