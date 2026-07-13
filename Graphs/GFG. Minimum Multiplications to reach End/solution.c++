class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int>dist(1000,1e9);
        dist[start] = 0;
        int mod = 1000;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto it : arr){
                int num = (it * node) % mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num, dist[num]});
                }
            }
        }
        return -1;
    }
};

/*Time Complexity: O(1000 × N), where N is the size of arr; each of the 1000 modulo states is processed once and explores all multipliers.

Space Complexity: O(1000) for the distance array and BFS queue, as there are at most 1000 reachable modulo states.*/