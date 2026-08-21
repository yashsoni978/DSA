/*Build a Max Heap from the array.
The largest element is now at index 0.
Swap it with the last element.
Reduce the heap size.
Restore the Max Heap using heapify.
Repeat until the array is sorted.*/

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  private:
    void heapify(vector<int>& arr, int n, int i){
        int largest = i;
        int left = 2*i+1, right = 2*i+2;
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=n/2-1; i>=0; i--) heapify(arr, n, i);
        for(int i=n-1; i>0; i--){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};