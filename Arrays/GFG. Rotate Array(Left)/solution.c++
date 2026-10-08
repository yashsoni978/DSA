class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        vector<int>temp;
        int n = arr.size();
        d %= n;
        for(int i=0; i<d; i++) temp.push_back(arr[i]);//d
        for(int i=d; i<n; i++) arr[i-d] = arr[i];//d
        for(int i=n-d; i<n; i++) arr[i] = temp[i - (n - d)];//n-d
    }
};

//d

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d %= n;
        reverse(arr.begin(), arr.begin() + d);//d
        reverse(arr.begin() + d, arr.end());//n-d
        reverse(arr.begin(), arr.end());//d
    }
};
//sc :- 1