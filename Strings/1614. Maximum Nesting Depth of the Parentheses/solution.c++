/* Optimal
Idea:
- Traverse the string once.
- Increase current depth when '(' is encountered.
- Update the maximum depth.
- Decrease current depth when ')' is encountered.
- Ignore all other characters.

Why?
- The current depth represents the number of open parentheses.
- The maximum value reached is the answer.

TC: O(n)

SC: O(1)
*/

/*💡 Why does this work?

Think of currDepth as the number of currently open parentheses.

Example:

((()))

Traverse it:

(  -> depth = 1
(( -> depth = 2
(((-> depth = 3   ← Maximum

(()-> depth = 2
() -> depth = 1
   -> depth = 0

The highest value that currDepth reaches during traversal is exactly the maximum nesting depth.*/

class Solution {
public:
    int maxDepth(string s) {
        int currDepth = 0, maxDepth = 0;
        for(char ch : s){
            if(ch == '('){
                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            }
            else if(ch == ')'){
                currDepth--;
                maxDepth = max(maxDepth, currDepth);
            }
        }
        return maxDepth;
    }
};