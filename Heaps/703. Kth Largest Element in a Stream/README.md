<h2>703. Kth Largest Element in a Stream</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Design a class to find the <strong>k<sup>th</sup> largest</strong> element in a stream of integers.</p>

<p>Implement the <code>KthLargest</code> class:</p>

<ul>
  <li><code>KthLargest(int k, int[] nums)</code> Initializes the object with the integer <code>k</code> and the stream of integers <code>nums</code>.</li>
  <li><code>int add(int val)</code> Appends the integer <code>val</code> to the stream and returns the <strong>k<sup>th</sup> largest</strong> element in the stream.</li>
</ul>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>

["KthLargest","add","add","add","add","add"]

[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]

<strong>Output:</strong>

[null,4,5,5,8,8]

<strong>Explanation:</strong>

KthLargest kthLargest = new KthLargest(3, [4,5,8,2]);

kthLargest.add(3);   // Stream: [2,3,4,5,8]     → 3rd largest = 4
kthLargest.add(5);   // Stream: [2,3,4,5,5,8]   → 3rd largest = 5
kthLargest.add(10);  // Stream: [2,3,4,5,5,8,10] → 3rd largest = 5
kthLargest.add(9);   // Stream: [2,3,4,5,5,8,9,10] → 3rd largest = 8
kthLargest.add(4);   // Stream: [2,3,4,4,5,5,8,9,10] → 3rd largest = 8
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ k ≤ 10<sup>4</sup></code></li>
  <li><code>0 ≤ nums.length ≤ 10<sup>4</sup></code></li>
  <li><code>-10<sup>4</sup> ≤ nums[i], val ≤ 10<sup>4</sup></code></li>
  <li>At most <code>10<sup>4</sup></code> calls will be made to <code>add</code>.</li>
  <li>It is guaranteed that there will be at least <code>k</code> elements in the stream when <code>add</code> is called.</li>
</ul>

<p><strong>Follow-up:</strong> Can you maintain a <strong>Min Heap</strong> of size <code>k</code>, so that each insertion takes <code>O(log k)</code> time and retrieving the <code>k<sup>th</sup> largest</code> element takes <code>O(1)</code> time?</p>
