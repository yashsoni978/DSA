/* Brute
Idea:
- Generate every substring.
- Count frequency of each character in that substring.
- Beauty = Maximum Frequency - Minimum Frequency
  (consider only characters with frequency > 0)
- Add beauty of every substring.

TC:
Substrings : O(n²)
Frequency Count : O(n)
Find Max & Min : O(26)

Overall : O(n³)

(If frequency is recalculated by scanning the substring every time,
it becomes O(n⁴).)

SC: O(26) = O(1)
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                vector<int>freq(26,0);
                for(int k=i; k<=j; k++) freq[s[k] - 'a']++;
                int mx = 0, mn = INT_MAX;
                for(int x : freq){
                    if(x == 0) continue;
                    mx = max(mx, x);
                    mn = min(mn, x);
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};

/* Optimal
Idea:
- Fix the starting index.
- Extend the ending index one character at a time.
- Update frequency instead of recalculating it.
- For every extension, compute:
    Beauty = Max Frequency - Min Frequency.

Why?
- Frequency array is reused for all substrings
  starting from the same index.

TC:
Outer Loop : O(n)
Inner Loop : O(n)
Find Max & Min : O(26)

Overall : O(n² × 26) ≈ O(n²)

SC:
O(26) = O(1)
*/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            for(int j=i; j<n; j++){
                freq[s[j] - 'a']++;
                int mx = 0, mn = INT_MAX;
                for(int x : freq){
                    if(x == 0) continue;
                    mx = max(mx, x);
                    mn = min(mn, x);
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};