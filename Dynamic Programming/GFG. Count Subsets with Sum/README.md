<h2>Count Subsets with Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>arr[]</code> of <strong>non-negative integers</strong> and an integer <code>target</code>, return the <strong>number of subsets</strong> whose elements sum exactly to <code>target</code>.</p>

<p>The <strong>empty subset</strong> is also considered a valid subset.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [5, 2, 3, 10, 6, 8]
target = 10

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The valid subsets are:

{5, 2, 3}
{2, 8}
{10}
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [2, 5, 1, 4, 3]
target = 10

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The valid subsets are:

{2, 1, 4, 3}
{5, 1, 4}
{2, 5, 3}
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [5, 7, 8]
target = 3

<strong>Output:</strong>
0

<strong>Explanation:</strong>

No subset has a sum equal to 3.
</pre>

<p><strong>Example 4:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [35, 2, 8, 22]
target = 0

<strong>Output:</strong>
1

<strong>Explanation:</strong>

The empty subset is the only subset
whose sum equals 0.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 10<sup>3</sup></code></li>
  <li><code>0 ≤ arr[i] ≤ 10<sup>3</sup></code></li>
  <li><code>0 ≤ target ≤ 10<sup>3</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × target)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(target)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> while correctly handling elements with value <code>0</code>, which can double the number of valid subsets?</p>
