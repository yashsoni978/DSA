/* Optimal
Idea:
- Traverse the string from right to left.
- Find the first odd digit.
- Return the substring from index 0 to that digit.
- If no odd digit exists, return "".

Why?
- Any suffix after the last odd digit makes the number even.
- Keeping the longest prefix ending at the last odd digit gives the largest odd number.

TC: O(n)
SC: O(1) (Ignoring the returned string)
*/

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1; i>=0; i--){
            if((num[i] - '0') % 2 == 1) return num.substr(0, i+1);  
        }
        return "";
    }
};