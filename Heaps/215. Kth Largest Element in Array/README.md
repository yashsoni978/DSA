<h2>215. Kth Largest Element in an Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the <strong>k<sup>th</sup> largest</strong> element in the array.</p>

<p>Note that it is the <strong>k<sup>th</sup> largest element in the sorted order</strong>, not the <code>k<sup>th</sup> distinct</code> element.</p>

<p>You must solve it in <strong>O(n)</strong> average time complexity.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [3,2,1,5,6,4]
k = 2

<strong>Output:</strong>
5

<strong>Explanation:</strong>

Sorted in descending order:

[6,5,4,3,2,1]

The 2nd largest element is 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [3,2,3,1,2,4,5,5,6]
k = 4

<strong>Output:</strong>
4

<strong>Explanation:</strong>

Sorted in descending order:

[6,5,5,4,3,3,2,2,1]

The 4th largest element is 4.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ k ≤ nums.length ≤ 10<sup>5</sup></code></li>
  <li><code>-10<sup>4</sup> ≤ nums[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem without fully sorting the array, using algorithms like <strong>Quick Select</strong> (average <code>O(n)</code>) or a <strong>Min Heap</strong> of size <code>k</code> (<code>O(n log k)</code>)?</p>
