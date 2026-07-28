/* Optimal (Two Hash Maps)
Idea:
- Each character in s must map to exactly one character in t.
- Each character in t must also map to exactly one character in s.
- Use two hash maps:
    s -> t
    t -> s
- If an existing mapping conflicts, return false.
- Otherwise, create the mapping.

Why?
- Ensures one-to-one mapping (bijection).
- Prevents two different characters from mapping to the same character.

TC: O(n)
SC: O(1)
(At most 256 characters for ASCII)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        for(int i=0; i<s.size(); i++){
            char c1 = s[i], c2 = t[i];
            if(mp1.count(c1) && mp1[c1] != c2) return false;
            if(mp2.count(c2) && mp2[c2] != c1) return false;
            mp1[c1] = c2;
            mp2[c2] = c1;
        }
        return true;
    }
};