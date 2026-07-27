/*Brute Force Approach
Idea

For each of the k projects:

Look at every project.
Among the projects whose required capital is less than or equal to the current capital, choose the one with the maximum profit.
Mark it as completed.
Increase the current capital.

Since we scan all projects for every selection, this is inefficient.

Algorithm
Maintain a visited array.
Repeat at most k times:
Scan every project.
Among affordable and unvisited projects, choose the one with maximum profit.
If none is affordable, stop.
Add its profit to the capital.
Mark it visited.
Return the final capital.*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<bool>used(n, false);
        for(int i=0; i<k; i++){
            int best = -1;
            for(int j=0; j<n; j++){
                if(!used[j] && capital[j] <= w && (best == -1 || profits[j] > profits[best])) best = j;
            }
            if(best == -1) break;
            w += profits[best];
            used[best] = true;
        }
        return w;
    }
};


/*Time Complexity
For every project selection, scan all projects.

O(k × n)

Space Complexity
Visited array

O(n)*/

/*Optimal Approach (Sorting + Max Heap)
Idea

At any point:

We can only choose projects whose

capital <= currentCapital
Among those projects, we should always pick the one with the maximum profit.

To achieve this efficiently:

Sort projects by required capital.
Use a Max Heap to store the profits of all currently affordable projects.
Repeatedly:
Add newly affordable projects to the heap.
Pick the most profitable one.
Algorithm
Store (capital, profit) pairs.
Sort by capital.
Maintain a pointer i.
Repeat k times:
Push every project whose capital requirement is ≤ current capital into the max heap.
If the heap is empty, stop.
Pop the maximum profit.
Add it to current capital.
Return the capital.*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>projects;
        for(int i=0; i<n; i++) projects.push_back({capital[i], profits[i]});
        sort(projects.begin(), projects.end());
        priority_queue<int>maxH;
        int i = 0;
        while(k--){
            while(i < n && projects[i].first <= w){
                maxH.push(projects[i].second);
                i++;
            }
            if(maxH.empty()) break;
            w += maxH.top();
            maxH.pop();
        }
        return w;
    }
};

/*Time Complexity

Let:

n = number of projects
Sorting = O(n log n)
Every project enters the heap once = O(n log n)
At most k heap removals = O(k log n)

Overall:

O(n log n + k log n)

Space Complexity
Projects array = O(n)
Max Heap = O(n)

Overall:

O(n)

Why does the heap approach work?

At every step:

New projects become available only when your capital increases.
By sorting projects by required capital, we can efficiently add all newly affordable projects.
Among all affordable projects, choosing the highest profit is always optimal because it maximizes your capital immediately, which can only increase (never decrease) the set of projects you can afford later.*/