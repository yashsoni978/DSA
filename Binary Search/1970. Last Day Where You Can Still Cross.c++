class Solution {
private:
    bool canCross(int day, vector<vector<int>>& cells, int row, int col){
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,-1,0,1};
        vector<vector<int>>grid(row, vector<int>(col,0));
        for(int i=0; i<day; i++) grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(row, vector<bool>(col, false));

        //start from top row
        for(int c=0; c<col; c++){
            if(grid[0][c] == 0){
                q.push({0,c});
                vis[0][c] = true;
            }
        }
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(r == row - 1) return true;
            for(int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < row && ncol < col && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int totalDays = cells.size();
        int lastDay = 0;
        for(int day=1; day<=totalDays; day++){
            if(canCross(day, cells, row, col)) lastDay = day;
            else break;
        }
        return lastDay;
    }
};

class Solution {
private:
    bool canCross(int day, vector<vector<int>>& cells, int row, int col){
        vector<vector<int>>grid(row, vector<int>(col,0));
        for(int i=0; i<day; i++) grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(row, vector<bool>(col,false));
        for(int c=0; c<col; c++){
            if(grid[0][c] == 0){
                q.push({0,c});
                vis[0][c] = true;
            }
        }
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,-1,0,1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(r == row - 1) return true;
            for(int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && !vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int totalDays = cells.size();
        int lastDay = 0;
        int l = 1, r = row * col;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(canCross(mid, cells, row, col)){
                lastDay = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return lastDay;
    }
};