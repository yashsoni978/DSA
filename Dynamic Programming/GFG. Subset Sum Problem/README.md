<h2>Subset Sum Problem</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array of <strong>positive integers</strong> <code>arr[]</code> and an integer <code>sum</code>, determine whether there exists a <strong>subset</strong> of the array whose elements add up exactly to <code>sum</code>.</p>

<p>Return <code>true</code> if such a subset exists; otherwise, return <code>false</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [3, 34, 4, 12, 5, 2]
sum = 9

<strong>Output:</strong>
true

<strong>Explanation:</strong>

One possible subset is:

4 + 3 + 2 = 9
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [3, 34, 4, 12, 5, 2]
sum = 30

<strong>Output:</strong>
false

<strong>Explanation:</strong>

There is no subset whose sum equals 30.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [1, 2, 3]
sum = 6

<strong>Output:</strong>
true

<strong>Explanation:</strong>

The entire array forms the required subset:

1 + 2 + 3 = 6
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 200</code></li>
  <li><code>1 ≤ arr[i] ≤ 200</code></li>
  <li><code>1 ≤ sum ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × sum)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(sum)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> and further optimize the space complexity from <code>O(n × sum)</code> to <code>O(sum)</code>?</p>
