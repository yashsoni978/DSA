class Solution {
  public:
    string postToPre(string s) {
        // code here
        stack<string>st;
        for(char ch : s){
            if(isalnum(ch)) st.push(string(1, ch));
            else{
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                string curr = ch + op1 + op2;
                st.push(curr);
            }
        }
        return st.top();
    }
};