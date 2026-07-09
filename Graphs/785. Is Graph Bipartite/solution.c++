class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (auto it : graph[node]) {
                    if (color[it] == -1) {
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

/*Complexity
Time: O(V + E)
Space: O(V) (color array + queue)*/

class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it] == -1){
                if(dfs(it, !col, color, graph) == false) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V,-1);
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};