class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse(n), nse(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            long long width = nse[i] - pse[i] - 1;
            long long area = 1LL * heights[i] * width;
            ans = max(ans, area);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<int>height(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};
//rows*cols and cols