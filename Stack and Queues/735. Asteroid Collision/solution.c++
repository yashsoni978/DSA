class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int ast : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && ast < 0){//top is moving right & ast is moving left
                if(st.top() < abs(ast)){
                    st.pop();
                    continue;//lets say 5 and -10 , 5 will be destroyed but dont push -10 as some more ele can be destroyed using -10
                }
                else if(st.top() == abs(ast)){//both explode
                    st.pop();
                    destroyed = true;
                    break;
                }
                else{//ast is bigger
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) st.push(ast);
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

//n and n