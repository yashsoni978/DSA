/* Brute

Idea:
- Try matching the pattern from every possible index.
- Compare characters one by one.
- If all characters match, store the starting index.

TC:
O((n-m+1) × m) ≈ O(nm)

SC:
O(1)
*/

class Solution {
  public:

    vector<int> search(string &pat, string &txt) {

        vector<int> ans;

        int n = txt.size();
        int m = pat.size();

        for(int i = 0; i <= n-m; i++){

            int j = 0;

            while(j < m && txt[i+j] == pat[j])
                j++;

            if(j == m)
                ans.push_back(i);
        }

        return ans;
    }
};

/* Optimal (KMP)

Idea:
- Build the LPS array for the pattern.
- Compare text and pattern using two pointers.
- On mismatch, use the LPS array instead of restarting.
- Whenever the whole pattern matches,
  store the starting index and continue searching.

TC:
Building LPS : O(m)
Searching    : O(n)

Overall : O(n+m)

SC:
O(m)
*/

class Solution {
  private:
    vector<int> buildLPS(string &pat){

        int m = pat.size();

        vector<int> lps(m,0);

        int len = 0;
        int i = 1;

        while(i < m){

            if(pat[i] == pat[len]){

                len++;
                lps[i] = len;
                i++;
            }
            else{

                if(len != 0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector<int> ans;

        int n = txt.size();
        int m = pat.size();

        vector<int> lps = buildLPS(pat);

        int i = 0;
        int j = 0;

        while(i < n){

            if(txt[i] == pat[j]){

                i++;
                j++;
            }

            if(j == m){

                ans.push_back(i-j);

                j = lps[j-1];
            }
            else if(i < n && txt[i] != pat[j]){

                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
        }

        return ans;
    }
};