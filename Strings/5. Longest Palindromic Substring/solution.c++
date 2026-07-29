/* Brute
Idea:
- Generate every possible substring.
- Check if each substring is a palindrome.
- Keep track of the longest palindrome found.

TC:
Substrings : O(n²)
Palindrome Check : O(n)

Overall : O(n³)

SC: O(1)
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
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

/* Optimal (Expand Around Center)

Idea:
- Every palindrome has a center.
- Expand from every character (odd length).
- Expand from every gap between two characters (even length).
- Keep updating the longest palindrome.

Why?
- Instead of checking every substring,
  we expand only while characters match.

TC:
O(n²)

SC:
O(1)
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;
        auto expand = [&](int l, int r){
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLen = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        };
        for(int i=0; i<n; i++){
            expand(i, i);
            expand(i, i+1);
        }
        return s.substr(start, maxLen);
    }
};
