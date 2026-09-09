class Solution {
public:
    int prec(char ch) {
        if(ch == '^') return 3;
        if(ch == '*' || ch == '/') return 2;
        if(ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPrefix(string &s) {

        reverse(s.begin(), s.end());

        for(char &c : s) {
            if(c == '(') c = ')';
            else if(c == ')') c = '(';
        }

        stack<char> st;
        string postfix;

        for(char ch : s) {

            if(isalnum(ch))
                postfix += ch;

            else if(ch == '(')
                st.push(ch);

            else if(ch == ')') {

                while(!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }

                if(!st.empty()) st.pop();
            }

            else {

                if(ch == '^') {
                    while(!st.empty() &&
                          prec(st.top()) >= prec(ch)) {
                        postfix += st.top();
                        st.pop();
                    }
                }
                else {
                    while(!st.empty() &&
                          prec(st.top()) > prec(ch)) {
                        postfix += st.top();
                        st.pop();
                    }
                }

                st.push(ch);
            }
        }

        while(!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};