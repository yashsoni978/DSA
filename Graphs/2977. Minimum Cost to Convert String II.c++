class Solution {
public:
    typedef long long ll;
    typedef pair<ll, string>P;
    ll BIG_VALUE = 1e10;
    unordered_map<string, vector<pair<string, ll>>>adj;
    unordered_map<string, unordered_map<string,ll>>dijikstraMemo;//for avoiding call for that path which dijikstra has already calculated
    vector<ll>dpMemo;
    string sourceStr;
    string targetStr;
    set<int>validLengths;//store only valid substring lengths
    ll dijikstra(string &start, string &end){
        if(dijikstraMemo[start].count(end)) return dijikstraMemo[start][end];
        priority_queue<P, vector<P>, greater<P>>pq;
        unordered_map<string,ll>result;
        result[start] = 0;
        pq.push({0, start});
        while(!pq.empty()){
            ll currCost = pq.top().first;
            string node = pq.top().second;
            pq.pop();
            if(node == end) break;//found ans
            for(auto &it : adj[node]){
                string adjNode = it.first;
                ll edgeCost = it.second;
                if(!result.count(adjNode) || currCost + edgeCost < result[adjNode]){//if adjNode was not in res do this
                    result[adjNode] = currCost + edgeCost;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        ll finalCost = result.count(end) ? result[end] : BIG_VALUE; //if end found
        return dijikstraMemo[start][end] = finalCost;
    }
    ll solve(int idx){
        if(idx >= sourceStr.length()) return 0;
        if(dpMemo[idx] != -1) return dpMemo[idx];
        ll minCost = BIG_VALUE;
        if(sourceStr[idx] == targetStr[idx]) minCost = solve(idx+1);
        for(auto &len : validLengths){
            if(idx + len > sourceStr.length()) break;
            string srcSub = sourceStr.substr(idx, len);
            string tgtSub = targetStr.substr(idx, len);
            if(!adj.count(srcSub)) continue; // not present move ahead
            ll minPathCost = dijikstra(srcSub, tgtSub);
            if(minPathCost == BIG_VALUE) continue;
            minCost = min(minCost, minPathCost + solve(idx + len));
        }
        return dpMemo[idx] = minCost;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourceStr = source;
        targetStr = target;
        dpMemo.assign(10001,-1);
        for(int i=0; i<original.size(); i++) adj[original[i]].push_back({changed[i], cost[i]});
        for(auto &s : original) validLengths.insert(s.length());
        ll result = solve(0);
        return result == BIG_VALUE ? -1 : result;
    }
};