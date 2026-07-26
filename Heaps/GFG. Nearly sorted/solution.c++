class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            int mini = i;
            for(int j=i+1; j<n; j++){
                if(arr[j] < arr[mini]) mini = j;
            }
            swap(arr[i],arr[mini]);
        }
    }
};

/*Time Complexity
O(n²)
Space Complexity
O(1)*/

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        int i = 0;
        for(; i<=k && i < n; i++) pq.push(arr[i]);
        int idx = 0;
        while(i < n){
            arr[idx++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
            i++;
        }
        while(!pq.empty()){
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};

/*Observation

Since every element is at most k positions away from its correct position:

The smallest element among the first k+1 elements must be the first element in the sorted array.
After placing it, the next smallest must lie within the next k+1 elements.

This suggests using a Min Heap of size k+1.

Algorithm
Insert the first k+1 elements into a min heap.
For every remaining element:
Extract the minimum and place it into the array.
Insert the current element into the heap.
After processing all elements, pop the remaining heap elements into the array.

Time Complexity
Building heap of size k+1: O(k log k)
Remaining n-(k+1) elements:
One pop + one push each = O(log k)
Final heap removal: O(k log k)

Overall:

O(n log k)
Space Complexity
O(k)
Why does the heap size remain k+1?

Because each element can only be misplaced by at most k positions.

Therefore, when deciding the next smallest element, we only need to consider the current element and the next k elements—a total of k+1 elements. The minimum among these must be the next element in the sorted order, so maintaining a min heap of size k+1 is sufficient.*/