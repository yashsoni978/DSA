class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>temp;
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) temp.push_back(mat[i][j]);
        }
        sort(temp.begin(), temp.end());
        return temp[(n*m)/2];
    }
};

// n*m + n*m*log(n*m)

/*Approach: Binary Search on Answer

- Binary search on the possible median value (min element → max element).
- For each mid, count how many elements in the matrix are <= mid.
- Since each row is sorted, use upper_bound in every row.
- Required count = (n * m) / 2.

- If count <= required:
    Median must be greater → low = mid + 1
- Else:
    Median can be smaller → high = mid - 1

- When low > high, low is the median.

Key Idea:
Binary Search on VALUE + upper_bound to count elements <= mid.*/

class Solution {
  private:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0, high = arr.size() - 1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int count(vector<vector<int>> &mat, int n, int m, int x){
        int cnt = 0;
        for(int i=0; i<n; i++) cnt += upperBound(mat[i], x);
        return cnt;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int low = INT_MAX, high = INT_MIN;
        for(int i=0; i<n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        int req = (n*m)/2;
        while(low <= high){
            int mid = (low + high)/2;
            if(count(mat, n, m, mid) <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};


/*TC: O(log(maxValue - minValue) × n log m)

For every binary-search value, we perform upper_bound on all n rows.
Each upper_bound takes O(log m).

SC: O(1)

Only variables are used; no extra array or data structure is created.*/