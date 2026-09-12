class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int>knowMe(n), IKnow(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && mat[i][j] == 1){
                    knowMe[j]++;
                    IKnow[i]++;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(knowMe[i] == n-1 && IKnow[i] == 0) return i;
        }
        return -1;
    }
};

//n^2 + n and 2n

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int top = 0, down = n-1;
        while(top < down){
            if(mat[top][down] == 1) top++;
            else if(mat[down][top] == 1) down--;
            else{
                top++;
                down--;
            }
        }
        if(top > down) return -1;
        for(int i=0; i<n; i++){
            if(i == top) continue;
            if(mat[top][i] == 1 || mat[i][top] == 0) return -1;
        }
        return top;
    }
};

//2n and 1