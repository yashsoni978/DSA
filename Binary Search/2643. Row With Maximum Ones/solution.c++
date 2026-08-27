class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int maxCnt = 0, ind = 0;
        for(int i=0; i<n; i++){
            int cntRows = 0;
            for(int j=0; j<m; j++){
                cntRows += mat[i][j];
            }
            if(cntRows > maxCnt){
                maxCnt = cntRows;
                ind = i;
            }
        }
        return {ind, maxCnt};
    }
};

