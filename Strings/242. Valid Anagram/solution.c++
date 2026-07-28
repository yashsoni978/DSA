/* Brute
Idea:
- If lengths are different, return false.
- For every character in s:
    - Search for it in t.
    - If found, mark it as used.
    - If not found, return false.
- If every character is matched, return true.

TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        for(char c : s){
            bool found = false;
            for(int i=0; i<t.size(); i++){
                if(t[i] == c){
                    found = true;
                    t[i] = '#';
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};

/* Optimal (Frequency Count)
Idea:
- If lengths are different, return false.
- Count frequency of every character in s.
- Decrease frequency using characters of t.
- If any frequency becomes negative, return false.
- Otherwise, strings are anagrams.

Why?
- Anagrams have exactly the same frequency of every character.

TC: O(n)
SC: O(1)
(26 lowercase English letters)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int>freq(26,0);
        for(char c : s) freq[c - 'a']++;
        for(char c : t){
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0) return false;
        }
        return true;
    }
};