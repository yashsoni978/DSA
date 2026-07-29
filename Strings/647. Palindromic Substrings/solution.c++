/* Brute
Idea:
- Generate every possible substring.
- Check if each substring is a palindrome.
- Count every palindrome found.

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
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j)) cnt++;
            }
        }
        return cnt;
    }
};

/* Optimal (Expand Around Center)

Idea:
- Every palindrome has a center.
- Expand around every character (odd length).
- Expand around every gap (even length).
- Every successful expansion gives one palindrome.

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
    int cnt = 0;
    void expand(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            cnt++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        for(int i=0; i<s.size(); i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return cnt;
    }
};