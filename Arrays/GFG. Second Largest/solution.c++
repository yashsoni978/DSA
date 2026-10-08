class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int largest = arr[n-1];
        int sLargest = -1;
        for(int i=n-2; i>=0; i--){
            if(arr[i] != largest){
                sLargest = arr[i];
                break;
            }
        }
        return sLargest; 
    }
};

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        for(int i=0; i<n; i++) largest = max(largest, arr[i]);
        int sLargest = -1;
        for(int i=0; i<n; i++){
            if(arr[i] > sLargest && arr[i] != largest) sLargest = arr[i];
        }
        return sLargest;
    }
};

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0], sLargest = -1;
        for(int i=1; i<n; i++){
            if(arr[i] > largest){
                sLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] < largest && arr[i] > sLargest) sLargest = arr[i];
        }
        return sLargest;
    }
};