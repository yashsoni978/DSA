<h2>300. Longest Increasing Subsequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code>, return the length of the <strong>longest strictly increasing subsequence</strong>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [10,9,2,5,3,7,101,18]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

The longest increasing subsequence is
[2,3,7,101].

Its length is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [0,1,0,3,2,3]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

One of the longest increasing subsequences is
[0,1,2,3].

Its length is 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
nums = [7,7,7,7,7,7,7]

<strong>Output:</strong>
1

<strong>Explanation:</strong>

Since all elements are equal,
any single element forms
an increasing subsequence.

Hence the answer is 1.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 2500</code></li>
  <li><code>-10<sup>4</sup> ≤ nums[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem in <code>O(n log n)</code> time using the <strong>Patience Sorting</strong> (Binary Search) technique, in addition to the classic <code>O(n²)</code> Dynamic Programming approach?</p>
