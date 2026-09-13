class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int duprow = row, dupcol = col;
        while(row >= 0 && col >= 0){//upperDiag
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(col >= 0){//left
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row < n && col >= 0){//lower diag
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        solve(0, n, board, ans);
        return ans;
    }
};
//n!*n
//n^2(board) + n(rss)

class Solution {
private:
    void solve(int col, int n, vector<int>& leftRow, vector<int>& lowerDiag, vector<int>& upperDiag, vector<string>& board, vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n-1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n-1 + col - row] = 1;
                solve(col + 1, n, leftRow, lowerDiag, upperDiag, board, ans);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n-1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        vector<int>leftRow(n,0), lowerDiag(2*n-1,0), upperDiag(2*n-1,0);
        solve(0, n, leftRow, lowerDiag, upperDiag, board, ans);
        return ans;
    }
};

/*//n! * n 
//n^2 (board) + n (Rss) + 3n(helper arrays)*/