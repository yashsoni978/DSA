class Solution {
private:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans, int target){
        if(node == target){
            ans.push_back(path);
            return;
        }
        for(auto it : graph[node]){
            path.push_back(it);
            dfs(it, graph, path, ans, target);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        int src = 0, target = n-1;
        path.push_back(src);
        dfs(src, graph, path, ans, target);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        queue<vector<int>>q;
        int src = 0, target = n-1;
        q.push({src});
        while(!q.empty()){
            vector<int>path = q.front();
            q.pop();
            int node = path.back();
            if(node == target){
                ans.push_back(path);
                continue;
            }
            for(auto it : graph[node]){
                vector<int> newPath = path;
                newPath.push_back(it);
                q.push(newPath);
            }
        }
        return ans;
    }
};