/* Brute
Idea:
- Try matching the pattern from every possible starting index.
- Compare characters one by one.
- If all characters match, store the index.

TC:
O((n-m+1) × m) ≈ O(nm)

SC:
O(1)
*/

class Solution {
  public:
    vector<int> rabinKarp(string &text, string &pattern) {
        // code here
        int n = text.size();
        int m = pattern.size();
        vector<int>ans;
        for(int i=0; i<=n-m; i++){
            int j = 0;
            while(j < m && text[i + j] == pattern[j]) j++;
            if(j == m) ans.push_back(i);
        }
        return ans;
    }
};


/* Optimal (Rabin-Karp)

Idea:
- Calculate the hash of the pattern.
- Calculate the hash of the first window of the text.
- Slide the window one character at a time.
- Update the hash in O(1).
- If hashes match, verify the substring to avoid collisions.

Why?
- Instead of comparing all characters for every window,
  compare hash values first.
- Character comparison happens only when hashes match.

TC:
Average : O(n + m)
Worst   : O(nm) (hash collisions)

SC:
O(1)
*/


class Solution {
  public:
    vector<int> rabinKarp(string &txt, string &pat) {
        // code here
        vector<int>ans;
        int n = txt.size(), m = pat.size();
        long long txtHash = 0, patHash = 0, power = 1;
        const int base = 26;
        const int MOD = 1e9 + 7;
        for(int i=0; i<m-1; i++) power = (power * base) % MOD;
        for(int i=0; i<m; i++){
            patHash = (patHash * base + (pat[i] - 'a')) % MOD;
            txtHash = (txtHash * base + (txt[i] - 'a')) % MOD;
        }
        for(int i=0; i<=n-m; i++){
            if(patHash == txtHash){
                bool match = true;
                for(int j=0; j<m; j++){
                    if(txt[i+j] != pat[j]){
                        match = false;
                        break;
                    }
                }
                if(match) ans.push_back(i);
            }
            if(i < n-m){
                txtHash = (txtHash - (txt[i] - 'a') * power % MOD + MOD) % MOD;
                txtHash = (txtHash * base + (txt[i+m] - 'a')) % MOD;
            }
        }
        return ans;
    }
};