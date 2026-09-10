// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>st;
        for(int i=pre_exp.size() - 1; i>=0; i--){
            char ch = pre_exp[i];
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string curr = "(" + op1 + ch + op2 + ")";
                st.push(curr);
            }
        }
        return st.top();
    }
};
//2n and n