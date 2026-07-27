/*Brute Force Approach
Idea

Generate all possible sum combinations:

For every element in a
Pair it with every element in b
Store all sums
Sort them in descending order
Return the first k sums.

Since there are n² combinations, this is inefficient.

Algorithm
Create an empty vector.
Generate every possible sum a[i] + b[j].
Store all sums.
Sort in descending order.
Return the first k sums.*/

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        vector<int>sums;
        int n = a.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) sums.push_back(a[i] + b[j]);
        }
        sort(sums.begin(), sums.end(), greater<int>());
        vector<int>ans;
        for(int i=0; i<k; i++) ans.push_back(sums[i]);
        return ans;
    }
};

/*Time Complexity
Generate sums = O(n²)
Sort = O(n² log(n²))

Overall:

O(n² log n)

Space Complexity

O(n²)*/

/*Optimal Approach (Sorting + Max Heap)
Idea

After sorting both arrays in descending order:

The largest possible sum is

a[0] + b[0]

The next largest sums can only come from its neighbors:

(i+1, j)
(i, j+1)
Use a Max Heap to always process the current largest sum.
Use a set to avoid pushing the same index pair multiple times.
Algorithm
Sort both arrays in descending order.
Push (a[0]+b[0], 0, 0) into a max heap.
Mark (0,0) as visited.
Repeat k times:
Pop the maximum sum.
Add it to the answer.
Push:
(i+1, j)
(i, j+1)
if not visited.
Return the answer.*/

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        priority_queue<vector<int>>maxH;
        set<pair<int,int>>vis;
        maxH.push({a[0] + b[0], 0, 0});
        vis.insert({0,0});
        vector<int>ans;
        while(k--){
            auto curr = maxH.top();
            maxH.pop();
            int sum = curr[0], i = curr[1], j = curr[2];
            ans.push_back(sum);
            if(i + 1 < n && !vis.count({i+1, j})){
                maxH.push({a[i+1] + b[j], i+1, j});
                vis.insert({i+1, j});
            }
            if(j + 1 < n && !vis.count({i, j+1})){
                maxH.push({a[i] + b[j+1], i, j+1});
                vis.insert({i, j+1});
            }
        }
        return ans;
    }
};

/*Why do we only push (i+1, j) and (i, j+1)?

Suppose the arrays are sorted in descending order.

      b0   b1   b2
a0    ✓
a1
a2

The current largest sum comes from (i, j).

The only possible next larger candidates are:

Move down → (i+1, j)
Move right → (i, j+1)

Moving both down and right (i+1, j+1) produces an even smaller sum and will eventually be reached through one of these neighbors.

The visited set prevents duplicate index pairs from being inserted.

Time Complexity
Sorting arrays = O(n log n)
Heap operations for k results:
Each pop and up to 2 pushes = O(log k) (heap size is O(k))

Overall:

O(n log n + k log k)

Space Complexity
Heap = O(k)
Visited set = O(k)

Overall:

O(k)*/