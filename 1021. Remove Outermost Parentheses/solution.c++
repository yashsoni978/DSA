/* Optimal
Idea:
- Maintain the current nesting depth.
- For '(':
    - If depth > 0, include it.
    - Then increase depth.
- For ')':
    - First decrease depth.
    - If depth > 0, include it.
- This automatically skips the outermost parentheses of every primitive.

TC: O(n)
SC: O(n)
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        for(char ch : s){
            if(ch == '('){
                if(depth > 0) ans += ch;
                depth++;
            }
            else{
                depth--;
                if(depth > 0) ans += ch;
            }
        }
        return ans;
    }
};