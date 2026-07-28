/* Optimal
Idea:
- Sort the array of strings.
- After sorting, only compare the first and last strings.
- Their common prefix is the common prefix of the entire array.
- Compare characters until they differ.

Why?
- After sorting, the first and last strings are the most different lexicographically.
- If they share a prefix, every string between them also shares it.

TC:
Sorting : O(n log n × m)
Comparing : O(m)

Overall: O(n log n × m)

SC: O(1) (Ignoring sorting space)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs.front();
        string last = strs.back();
        string ans = "";
        for(int i=0; i<min(first.size(), last.size()); i++){
            if(first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }
};