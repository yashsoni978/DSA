/* Optimal (Greedy)
Idea:
- Store Roman symbols along with their values in descending order.
- Traverse the values from largest to smallest.
- While the current value is less than or equal to num:
    - Append its Roman symbol.
    - Subtract its value from num.
- Continue until num becomes 0.

Why?
- Always choosing the largest possible Roman value produces the correct Roman numeral.
- The subtractive cases (IV, IX, XL, XC, CD, CM) are included in the table, so they are handled automatically.

TC: O(1)
(Maximum 13 Roman symbols are checked)

SC: O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        string ans = "";
        for(auto &[value, symbol] : roman){
            while(num >= value){
                ans += symbol;
                num -= value;
            }
        }
        return ans;
    }
};