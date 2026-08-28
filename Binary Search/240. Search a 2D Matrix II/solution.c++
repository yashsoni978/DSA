class Solution {
private:
    int binarySearch(vector<int>& arr, int target){
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            int ind = binarySearch(matrix[i], target);
            if(ind != -1) return true;
        }
        return false;
    }
};

//n log m

/*Approach: Staircase Search

Start from the top-right corner of the matrix.

- If matrix[row][col] == target → return true.
- If matrix[row][col] > target → move left (col--).
  Everything below is also greater, so that column can be eliminated.
- If matrix[row][col] < target → move down (row++).
  Everything to the left is also smaller, so that row can be eliminated.

Since every move eliminates one row or one column:

TC: O(n + m)
SC: O(1)

Key Idea:
Top-right → Too Big = LEFT | Too Small = DOWN*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m-1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};


