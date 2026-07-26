class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

/*Time Complexity: O(n log n), as the entire array is sorted in descending order.

Space Complexity: O(1) (ignoring the recursion stack used by std::sort). The recursion stack is O(log n) on average.*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minH;
        for(int x : nums){
            minH.push(x);
            if(minH.size() > k) minH.pop();
        }
        return minH.top();
    }
};

/*Time Complexity: O(n log k), because each of the n elements may be inserted into the heap and each insertion/deletion takes O(log k).

Space Complexity: O(k), as the min heap stores at most k elements.*/
