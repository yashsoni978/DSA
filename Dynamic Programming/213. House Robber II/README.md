<h2>213. House Robber II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are a professional robber planning to rob houses arranged in a <strong>circle</strong>. Each house has a certain amount of money stashed, represented by an integer array <code>nums</code>.</p>

<p>Unlike the original House Robber problem, the <strong>first and last houses are adjacent</strong>. This means you cannot rob both of them on the same night.</p>

<p>Return the <strong>maximum amount of money</strong> you can rob tonight without alerting the police.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [2,3,2]

<strong>Output:</strong>
3

<strong>Explanation:</strong>

You cannot rob house 1 and house 3 together because they are adjacent.

The maximum amount you can rob is by robbing house 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,3,1]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

Rob house 2 (money = 2) and house 4 (money = 1), or
rob house 1 (money = 1) and house 3 (money = 3).

The maximum amount robbed is 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,3]

<strong>Output:</strong>
3
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 100</code></li>
  <li><code>0 ≤ nums[i] ≤ 1000</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem in <code>O(n)</code> time and <code>O(1)</code> extra space by reducing it to two instances of the original <strong>House Robber</strong> problem?</p>
