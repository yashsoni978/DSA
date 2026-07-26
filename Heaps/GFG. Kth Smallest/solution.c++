class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>maxH;
        for(int x : arr){
            maxH.push(x);
            if(maxH.size() > k) maxH.pop();
        }
        return maxH.top();
    }
};

/*Time Complexity: O(n log k), because each of the n elements may be inserted into the heap and each insertion/deletion takes O(log k).

Space Complexity: O(k), as the min heap stores at most k elements.*/