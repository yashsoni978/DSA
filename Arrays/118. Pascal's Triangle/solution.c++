class Solution {
public:
    long long nCr(int n, int r) {
        long long res = 1;

        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }

        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;

            for (int j = 0; j <= i; j++) {
                row.push_back(nCr(i, j));
            }

            ans.push_back(row);
        }

        return ans;
    }
};
// TC: O(N^3) approximately
// SC: O(N^2)
// N = number of rows

class Solution {
private:
    vector<int>generateRow(int row){
        long long ans = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int col=1; col<row; col++){
            ans *= (row - col);
            ans /= col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1; i<=numRows; i++) ans.push_back(generateRow(i));
        return ans;
    }
};