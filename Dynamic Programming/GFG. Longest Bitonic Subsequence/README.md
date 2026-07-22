<h2>Longest Bitonic Subsequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array of positive integers <code>nums[]</code>, find the <strong>maximum length</strong> of a <strong>Bitonic Subsequence</strong>.</p>

<p>A <strong>Bitonic Subsequence</strong> is a subsequence that is first <strong>strictly increasing</strong> and then <strong>strictly decreasing</strong>.</p>

<p><strong>Note:</strong></p>

<ul>
  <li>A sequence that is only strictly increasing is <strong>not</strong> considered bitonic.</li>
  <li>A sequence that is only strictly decreasing is <strong>not</strong> considered bitonic.</li>
  <li>Both the increasing and decreasing parts must contain at least one element.</li>
</ul>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 5
nums[] = [1, 2, 5, 3, 2]

<strong>Output:</strong>
5

<strong>Explanation:</strong>

The subsequence

[1, 2, 5]

is strictly increasing and

[5, 3, 2]

is strictly decreasing.

Hence the maximum bitonic
subsequence length is 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 8
nums[] = [1, 11, 2, 10, 4, 5, 2, 1]

<strong>Output:</strong>
6

<strong>Explanation:</strong>

One longest bitonic subsequence is

[1, 2, 10, 4, 2, 1]

whose length is 6.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
n = 3
nums[] = [10, 20, 30]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

There is no decreasing part.

Hence no valid bitonic
subsequence exists.
</pre>

<p><strong>Example 4:</strong></p>

<pre>
<strong>Input:</strong>
n = 3
nums[] = [10, 10, 10]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

No strictly increasing or
strictly decreasing sequence
can be formed.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 10<sup>3</sup></code></li>
  <li><code>1 ≤ nums[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n²)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem by computing the <strong>Longest Increasing Subsequence (LIS)</strong> ending at every index and the <strong>Longest Decreasing Subsequence (LDS)</strong> starting from every index, then combining them as <code>LIS[i] + LDS[i] - 1</code> while ensuring both parts have length greater than 1?</p>
