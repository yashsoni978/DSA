<h2>Nearly Sorted</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>arr[]</code>, where every element is at most <code>k</code> positions away from its correct position in the sorted order, restore the array to its fully sorted order.</p>

<p>You must rearrange the elements <strong>in place</strong> without using any built-in <code>sort()</code> method.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr = [2,3,1,4]
k = 2

<strong>Output:</strong>
[1,2,3,4]

<strong>Explanation:</strong>

Each element is at most 2 positions away
from its correct position.

1 moves from index 2 → 0
2 moves from index 0 → 1
3 moves from index 1 → 2
4 remains at index 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr = [7,9,14]
k = 1

<strong>Output:</strong>
[7,9,14]

<strong>Explanation:</strong>

The array is already sorted,
so no rearrangement is needed.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 10<sup>6</sup></code></li>
  <li><code>0 ≤ k &lt; arr.size()</code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>6</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using a <strong>Min Heap</strong> of size <code>k + 1</code>, achieving <code>O(n log k)</code> time complexity and <code>O(k)</code> extra space without using any built-in sorting algorithm?</p>
