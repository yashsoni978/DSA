class Solution {
private:
    bool solve(int ind, int cnt, string &s){
        int n = s.size();
        if(cnt < 0) return false;
        if(ind == n) return (cnt == 0);
        if(s[ind] == '(') return solve(ind+1, cnt+1, s);
        if(s[ind] == ')') return solve(ind+1, cnt-1, s);
        return solve(ind+1, cnt+1, s) || solve(ind+1, cnt-1, s) || solve(ind+1, cnt, s);
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        return solve(0, 0, s);
    }
};

//3^n and n

class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;
                high++;
            }

            if (high < 0) {
                return false;
            }

            low = max(0, low);
        }

        return low == 0;
    }
};
