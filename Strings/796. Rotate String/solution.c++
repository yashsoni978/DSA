/* Brute
Idea:
- Rotate the string left by one position repeatedly.
- After each rotation, compare it with goal.
- If they become equal, return true.
- If all rotations are checked, return false.

TC: O(n²)
SC: O(1)
*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        for(int i=0; i<n; i++){
            char first = s[0];
            s.erase(s.begin());
            s.push_back(first);
            if(s == goal) return true;
        }
        return false;
    }
};

/* Optimal
Idea:
- If lengths are different, return false.
- Concatenate the string with itself.
- If goal is a rotation of s, it must appear as a substring of s+s.

Why?
- Every possible rotation of s is present inside s+s.

TC: O(n)
SC: O(n)
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string temp = s + s;
        return temp.find(goal) != string :: npos;
    }
};