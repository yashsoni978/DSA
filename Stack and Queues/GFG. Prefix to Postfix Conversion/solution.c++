class Solution {
  public:
    string preToPost(string &s) {
        // code here
        stack<string>st;
        for(int i=s.size()-1; i>=0; i--){
            char ch = s[i];
            if(isalnum(ch)) st.push(string(1,ch));
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                string curr = op1 + op2 + ch;
                st.push(curr);
            }
        }
        return st.top();
    }
};