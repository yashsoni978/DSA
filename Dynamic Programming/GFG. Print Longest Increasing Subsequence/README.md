<h2>Print Longest Increasing Subsequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array of integers <code>arr[]</code>, return the <strong>Longest Increasing Subsequence (LIS)</strong> of the given array.</p>

<p>A <strong>Longest Increasing Subsequence (LIS)</strong> is the longest subsequence in which every element is <strong>strictly greater</strong> than its previous element.</p>

<p><strong>Note:</strong> If multiple LIS of the same maximum length exist, return the one that appears first based on the <strong>lexicographical order of their indices</strong> (i.e., the earliest combination of positions in the original array).</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [10, 20, 3, 40]

<strong>Output:</strong>
[10, 20, 40]

<strong>Explanation:</strong>

[10, 20, 40] is the longest
increasing subsequence while
preserving the original order.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [10, 22, 9, 33, 21, 50, 41, 60, 80]

<strong>Output:</strong>
[10, 22, 33, 50, 60, 80]

<strong>Explanation:</strong>

Two LIS of length 6 are:

[10, 22, 33, 50, 60, 80]
[10, 22, 33, 41, 60, 80]

The first one is returned because
it has the lexicographically
smallest sequence of indices.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 5 × 10<sup>3</sup></code></li>
  <li><code>0 ≤ arr[i] ≤ 10<sup>9</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n²)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n)</code></p>

<p><strong>Follow-up:</strong> Can you reconstruct the actual Longest Increasing Subsequence while maintaining the lexicographically smallest sequence of indices, and further optimize the LIS length computation to <code>O(n log n)</code> using Binary Search?</p>
