<h2>198. House Robber</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, represented by an integer array <code>nums</code>.</p>

<p>The only constraint stopping you from robbing each of them is that <strong>adjacent houses have security systems connected</strong>. If two adjacent houses are robbed on the same night, the police will automatically be alerted.</p>

<p>Return the <strong>maximum amount of money</strong> you can rob tonight without alerting the police.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,3,1]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

Rob house 1 (money = 1)
Rob house 3 (money = 3)

Total amount = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [2,7,9,3,1]

<strong>Output:</strong>
12

<strong>Explanation:</strong>

Rob house 1 (money = 2)
Rob house 3 (money = 9)
Rob house 5 (money = 1)

Total amount = 12.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 100</code></li>
  <li><code>0 ≤ nums[i] ≤ 400</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with <code>O(n)</code> time and optimize the space complexity to <code>O(1)</code>?</p>
