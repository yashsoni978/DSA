<h2>Maximum Sum Combination</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given two integer arrays <code>a[]</code> and <code>b[]</code> of equal size.</p>

<p>A <strong>sum combination</strong> is formed by adding one element from <code>a[]</code> and one element from <code>b[]</code>. Each index pair <code>(i, j)</code> can be used at most once.</p>

<p>Return the <strong>top k maximum sum combinations</strong>, sorted in <strong>non-increasing order</strong>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
a = [3,2]
b = [1,4]
k = 2

<strong>Output:</strong>
[7,6]

<strong>Explanation:</strong>

Possible sums are:

3 + 1 = 4
3 + 4 = 7
2 + 1 = 3
2 + 4 = 6

The top 2 maximum sums are:

7 and 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
a = [1,4,2,3]
b = [2,5,1,6]
k = 3

<strong>Output:</strong>
[10,9,9]

<strong>Explanation:</strong>

The largest sum combinations are:

4 + 6 = 10
3 + 6 = 9
4 + 5 = 9

Hence, the top 3 sums are:

[10,9,9]
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ a.size() = b.size() ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ k ≤ a.size()</code></li>
  <li><code>1 ≤ a[i], b[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this efficiently by first sorting both arrays in descending order, then using a <strong>Max Heap</strong> along with a <strong>Hash Set</strong> to avoid revisiting index pairs, achieving <code>O(n log n + k log k)</code> time complexity?</p>
