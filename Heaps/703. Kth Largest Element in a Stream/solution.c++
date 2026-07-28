/*/* Brute
Idea:
- Store all elements in a vector.
- For every add(val):
    - Insert val.
    - Sort the entire vector in descending order.
    - Return the kth element.

TC:
Constructor : O(n log n)
add()       : O(n log n)

SC: O(n)
*/

class KthLargest {
public:
    vector<int>nums;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        this -> nums = nums;   
        sort(this -> nums.begin(), this -> nums.end(), greater<int>());
    }
    
    int add(int val) {
        nums.push_back(val);
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/* Optimal (Min Heap)
Idea:
- Maintain a min heap of size k.
- Heap always stores the k largest elements.
- Heap top is the kth largest element.
- During construction and add(), if heap size exceeds k,
  remove the smallest element.

Why Min Heap?
- We only need the k largest elements.
- The smallest among these k elements is exactly the kth largest overall.

TC:
Constructor : O(n log k)
add()       : O(log k)

SC: O(k)
*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>minH;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int num : nums){
            minH.push(num);
            if(minH.size() > k) minH.pop();
        }
    }
    
    int add(int val) {
        minH.push(val);
        if(minH.size() > k) minH.pop();
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */