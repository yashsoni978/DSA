//same as lc 214 here we have to give ans
/*Why return s.size() - lps.back()?

- lps.back() gives the length of the Longest Palindromic Prefix.
- This prefix is already a palindrome, so we don't need to add anything for it.
- Only the remaining suffix needs to be reversed and added to the front.

Therefore,

Characters to Add
= Total Length − Longest Palindromic Prefix Length

return s.size() - lps.back();

Example:
s = "abc"

Longest Palindromic Prefix = "a" (length = 1)

Remaining Suffix = "bc"

Characters to Add = 3 − 1 = 2*/

class Solution {
public:

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
                else
                    i++;
            }
        }

        return lps;
    }

    int minChar(string &s){

        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        vector<int> lps = buildLPS(temp);

        return s.size() - lps.back();
    }
};