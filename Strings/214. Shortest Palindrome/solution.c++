/* Brute
Idea:
- Find the longest prefix that is already a palindrome.
- Starting from the entire string, keep reducing the prefix length
  until it becomes a palindrome.
- Reverse the remaining suffix and add it in front.

TC:
Checking each prefix : O(n)
Palindrome Check     : O(n)

Overall : O(n²)

SC:
O(n) (for reversed string)
*/

class Solution {
private:
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int end = n - 1;
        while(end >= 0){
            if(isPalindrome(s, 0, end)) break;
            end--;
        }
        string suffix = s.substr(end+1);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};

/* Optimal (KMP)

Idea:
- Reverse the string.
- Build:
      s + "#" + reverse(s)
- Compute the LPS array.
- The last LPS value gives the length of the
  longest palindromic prefix.
- Reverse the remaining suffix and add it
  in front.

Why?
- LPS finds the longest prefix of s that also
  matches a suffix of reverse(s).
- Such a prefix is exactly the longest
  palindromic prefix.

TC:
Building LPS : O(n)

Overall : O(n)

SC:
O(n)
*/

class Solution {
private:
    vector<int> buildLPS(string pat){
        int m = pat.size();
        vector<int>lps(m,0);
        int len = 0, i = 1;
        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0) len = lps[len - 1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        vector<int>lps = buildLPS(temp);
        int longest = lps.back();
        string suffix = s.substr(longest);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};