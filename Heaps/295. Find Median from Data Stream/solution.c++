/*Brute Force Approach
Idea

Maintain all numbers in a vector. Whenever findMedian() is called:

Sort the vector.
Return the middle element (or average of two middle elements).
Algorithm
addNum(num)
Push num into the vector.
findMedian()
Sort the vector.
If size is odd, return middle element.
Otherwise return average of two middle elements.*/

class MedianFinder {
public:
    vector<int>arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if(n % 2) return arr[n/2];
        return (arr[n/2] + arr[n/2-1]) / 2.0;
    }
};

/*Time Complexity
addNum() → O(1)
findMedian() → O(n log n)
Space Complexity
O(n)*/

/*Optimal Approach (Two Heaps)
Idea

Maintain two heaps:

Max Heap (left)
Stores the smaller half of numbers.
Top is the largest among the smaller half.
Min Heap (right)
Stores the larger half.
Top is the smallest among the larger half.
Maintain Two Conditions
Every element in left ≤ every element in right.
Heap sizes differ by at most 1.

Then:

If total elements are odd, median is the top of the larger heap.
If even, median is the average of both heap tops.
Algorithm
addNum(num)
If left is empty or num <= left.top()
Insert into left.
Else
Insert into right.

Now rebalance:

If left.size() > right.size() + 1
Move left.top() to right.
If right.size() > left.size() + 1
Move right.top() to left.
findMedian()
Equal sizes:
(left.top() + right.top()) / 2
Otherwise:
Top of the larger heap.*/

class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) return (left.top() + right.top()) / 2.0;
        if(left.size() > right.size()) return left.top();
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 /*Time Complexity
addNum()
Heap insertion: O(log n)
Rebalancing (at most one move): O(log n)
Overall: O(log n)
findMedian()
Just accessing heap tops.
O(1)
Space Complexity
Two heaps together store all elements.

Overall: O(n)*/