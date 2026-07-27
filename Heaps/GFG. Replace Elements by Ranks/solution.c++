/*Brute Force Approach
Idea

For every element, count how many elements should come before it in the sorted order.

For duplicate elements:

If values are equal, the one appearing earlier in the original array gets the smaller rank.

The count obtained is exactly the rank.

Algorithm
For every index i
Initialize rank = 0.
Traverse every index j.
Increase rank if:
arr[j] < arr[i], or
arr[j] == arr[i] and j < i.
Store the rank.
Copy the ranks back into the original array.*/

class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int rank = 0;
            for(int j=0; j<n; j++){
                if(arr[j] < arr[i] || (arr[j] == arr[i] && j < i)) rank++;
            }
            ans[i] = rank;
        }
        arr = ans;
    }
};

/*Time Complexity
O(n²)
Space Complexity
O(n)*/

/*Heap Approach
Idea
Push every element along with its original index into a Min Heap.
The heap automatically gives elements in sorted order.
Pop elements one by one.
The order in which they are popped is their rank.
Store the rank at the original index.

For duplicates:

Store (value, originalIndex) in the heap.
The heap compares the value first.
If values are equal, it compares the original index.
Thus, the earlier occurrence gets the smaller rank automatically.
Algorithm

Create a Min Heap of pairs:

{value, originalIndex}
Push all elements.
Initialize rank = 0.
While heap is not empty:
Pop the smallest pair.
Assign rank to its original index.
Increment rank.
Copy ranks back into the original array.*/

class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minH;
        for(int i=0; i<n; i++) minH.push({arr[i],i});
        vector<int>rank(n);
        int r = 0;
        while(!minH.empty()){
            auto [val, idx] = minH.top();
            minH.pop();
            rank[idx] = r++;
        }
        arr = rank;
    }
};

/*Time Complexity
Heap insertions: O(n log n)
Heap removals: O(n log n)

Overall:

O(n log n)

Space Complexity

O(n)*/