/*There is no K parameter, so we determine the number of unique characters ourselves.
We use:
unordered_map<char, int> to assign each character an index.
unordered_map<int, char> to convert indices back to characters after topological sorting.*/

class Solution {
  private:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<char>st;
        for(auto &word : words){
            for(char &ch : word) st.insert(ch);
        }
        unordered_map<char,int>mp;
        unordered_map<int,char>rev;
        int idx = 0;
        for(char ch : st){
            mp[ch] = idx;
            rev[idx] = ch;
            idx++;
        }
        int K = idx;
        vector<vector<int>>adj(K);
        for(int i=0; i<words.size() - 1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            bool found = false;
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    adj[mp[s1[j]]].push_back(mp[s2[j]]);
                    found = true;
                    break;
                }
            }
            if(!found && s1.size() > s2.size()) return "";//s1 = abcd and s2 = ab
        }
        vector<int>topo = topoSort(K, adj);
        if(topo.size() != K) return "";
        string ans = "";
        for(auto it : topo) ans += rev[it];
        return ans;
    }
};