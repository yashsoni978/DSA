// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string>st;
        for(char ch : exp){
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                string curr = "(" + op1 + ch + op2 + ")";
                st.push(curr); 
            }
        }
        return st.top();
    }
};