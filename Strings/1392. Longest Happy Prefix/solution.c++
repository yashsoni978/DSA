/* Brute

Idea:
- Check every possible prefix from longest to shortest.
- Compare it with the corresponding suffix.
- Return the first matching prefix.

TC:
O(n²)

SC:
O(n)
*/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        for(int len=n-1; len>=1; len--){
            bool match = true;
            for(int i=0; i<len; i++){
                if(s[i] != s[n-len+i]){
                    match = false;
                    break;
                }
            }
            if(match) return s.substr(0, len);
        }
        return "";
    }
};

/* Optimal (KMP)

Idea:
- Build the LPS array for the entire string.
- The last value of the LPS array gives the
  length of the longest prefix which is also
  a suffix (excluding the whole string).
- Return that prefix.

TC:
Building LPS : O(n)

Overall : O(n)

SC:
O(n)
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
    string longestPrefix(string s) {
        vector<int>lps = buildLPS(s);
        int len = lps.back();
        return s.substr(0, len);
    }
};