/*Brute Force Approach
Idea

Store all elements of the matrix into a single array and then sort the array.

Algorithm
Traverse every row of the matrix.
Push every element into a vector.
Sort the vector.
Return the sorted vector.*/

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int>ans;
        for(auto &row : mat){
            for(int x : row) ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*Time Complexity
Copy elements = O(N × M)
Sorting = O((N × M) log(N × M))

Overall: O((N × M) log(N × M))

Space Complexity
O(N × M)*/

/*Optimal Approach (Min Heap)
Idea

Every row is already sorted.

Instead of sorting everything again, keep only the smallest unprocessed element of each row inside a Min Heap.

Whenever we remove the smallest element from the heap, insert the next element from the same row.

This is exactly the same idea as Merge K Sorted Linked Lists.

Algorithm
Create a min heap storing:
value
row index
column index
Insert the first element of every row.
While heap is not empty:
Pop the smallest element.
Add it to answer.
If the popped element has a next element in the same row, push it into the heap.
Return the answer.*/

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        vector<int>ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>minH;
        int n = mat.size();
        for(int i=0; i<n; i++) minH.push({mat[i][0],i,0});
        while(!minH.empty()){
            auto curr = minH.top();
            minH.pop();
            int val = curr[0], row = curr[1], col = curr[2];
            ans.push_back(val);
            if(col + 1 < mat[row].size()) minH.push({mat[row][col+1], row, col + 1});
        }
        return ans;
    }
};

/*Time Complexity

Let:

K = number of rows
M = number of columns
Total elements = K × M
Initial heap creation = O(K log K)
Each of the K × M elements is pushed and popped once = O(log K)

Overall: O(K × M × log K)

Space Complexity
Heap stores at most K elements.
Answer array stores K × M elements.

Auxiliary Space: O(K) (excluding output array)

Why is the heap size only K?

At any moment, the heap contains only one current element from each row.

Initially, we insert the first element of every row.
When we pop an element from a row, we immediately insert the next element from that same row.
Therefore, there is never more than one element per row in the heap.*/