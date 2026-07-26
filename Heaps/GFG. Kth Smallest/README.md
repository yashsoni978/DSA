<h2>Kth Smallest</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>arr[]</code> and an integer <code>k</code>, find and return the <strong>k<sup>th</sup> smallest</strong> element in the array.</p>

<p>The <strong>k<sup>th</sup> smallest element</strong> is determined based on the array's sorted order.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10]
k = 4

<strong>Output:</strong>
5

<strong>Explanation:</strong>

Sorted array:

[2,3,4,5,6,10,10,33,48,53]

The 4th smallest element is 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr = [7,10,4,3,20,15]
k = 3

<strong>Output:</strong>
7

<strong>Explanation:</strong>

Sorted array:

[3,4,7,10,15,20]

The 3rd smallest element is 7.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ k ≤ arr.size()</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem without fully sorting the array by using <strong>Quick Select</strong> (average <code>O(n)</code>) or a <strong>Max Heap</strong> of size <code>k</code> (<code>O(n log k)</code>)?</p>
