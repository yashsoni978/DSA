class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        int sr = entrance[0], sc = entrance[1];
        q.push({sr, sc});
        vis[sr][sc] = 1;
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,-1,0,1};
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int row = it.first; 
                int col = it.second;
                if((row == 0 || row == n-1 || col == 0 || col == m-1) && !(row == sr && col == sc)) return steps;
                for(int i=0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && maze[nrow][ncol] == '.'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
