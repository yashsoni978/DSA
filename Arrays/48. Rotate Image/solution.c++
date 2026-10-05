class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>ans(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) ans[j][n-1-i] = matrix[i][j];
        }
        matrix = ans;
    }
};
//n^2 and n^2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<m; j++) swap(matrix[i][j], matrix[j][i]);
        }
        for(int i=0; i<n; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};

//n/2 * n/2 + n * n/2