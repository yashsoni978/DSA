class Solution {
private:
    void dijikstra(int src, vector<vector<pair<int,int>>>& adj, vector<vector<long long>>& costMatrix){
        vector<long long>dist(26, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int node = it.second;
            if(dis > dist[node]) continue;
            for(auto nei : adj[node]){
                int adjNode = nei.first;
                int wt = nei.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=0; i<26; i++) costMatrix[src][i] = dist[i];
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>>adj(26);
        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }
        vector<vector<long long>>costMatrix(26, vector<long long>(26,LLONG_MAX));
        vector<bool>vis(26,false);
        for(char ch : source){
            int node = ch - 'a';
            if(!vis[node]){//optimisation
                dijikstra(node, adj, costMatrix);
                vis[node] = true;
            }
        }
        long long ans = 0;
        for(int i=0; i<source.length(); i++){
            if(target[i] == source[i]) continue; // abcd -> acbe so a->a dont add anything to cost
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if(costMatrix[s][t] == LLONG_MAX) return -1;
            ans += costMatrix[s][t];
        }
        return ans;
    }
};

class Solution {
private:
    void floydWarshall(vector<vector<long long>>& costMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int i=0; i<26; i++) costMatrix[i][i] = 0;
        for(int i=0; i<original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            costMatrix[u][v] = min(costMatrix[u][v], (long long)cost[i]);
        }
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(costMatrix[i][k] < LLONG_MAX && costMatrix[k][j] < LLONG_MAX){
                        costMatrix[i][j] = min(costMatrix[i][j] , costMatrix[i][k] + costMatrix[k][j]);
                    }
                }
            }
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>costMatrix(26, vector<long long>(26, LLONG_MAX));
        floydWarshall(costMatrix, original, changed, cost);
        long long ans = 0;
        for(int i=0; i<source.length(); i++){
            if(source[i] == target[i]) continue;
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if(costMatrix[s][t] == LLONG_MAX) return -1;
            ans += costMatrix[s][t];
        }
        return ans;
    }
};
