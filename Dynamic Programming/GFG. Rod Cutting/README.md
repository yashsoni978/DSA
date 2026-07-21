<h2>Rod Cutting</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a rod of length <code>n</code> inches and an array <code>price[]</code>, where <code>price[i]</code> denotes the value of a rod piece of length <code>i + 1</code>.</p>

<p>Your task is to determine the <strong>maximum obtainable value</strong> by cutting the rod into one or more pieces and selling them.</p>

<p><strong>Note:</strong> The rod can be cut into any number of pieces, including no cut at all. Each piece length can be used multiple times as long as their total length equals <code>n</code>. Here, <code>n = price.size()</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
price[] = [1, 5, 8, 9, 10, 17, 17, 20]

<strong>Output:</strong>
22

<strong>Explanation:</strong>

Cut the rod into pieces of lengths:

2 and 6

Value = 5 + 17 = 22

This is the maximum obtainable value.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
price[] = [3, 5, 8, 9, 10, 17, 17, 20]

<strong>Output:</strong>
24

<strong>Explanation:</strong>

Cut the rod into eight pieces
of length 1.

Value = 8 × 3 = 24

This yields the maximum profit.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
price[] = [3]

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The rod has length 1, so the only
possible piece has value 3.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ price.size() ≤ 10<sup>3</sup></code></li>
  <li><code>1 ≤ price[i] ≤ 10<sup>6</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n²)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem by modeling it as an <strong>Unbounded Knapsack</strong>, where rod lengths act as weights and prices act as values, while optimizing the space complexity to <code>O(n)</code>?</p>
