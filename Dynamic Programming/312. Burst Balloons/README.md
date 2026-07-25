<h2>312. Burst Balloons</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given <code>n</code> balloons, represented by an integer array <code>nums</code>. Each balloon is painted with a number.</p>

<p>You are asked to burst all the balloons. If you burst the <code>i<sup>th</sup></code> balloon, you gain:</p>

<pre>
nums[left] × nums[i] × nums[right]
</pre>

<p>coins, where <code>left</code> and <code>right</code> are the adjacent balloons of <code>i</code> that have <strong>not yet been burst</strong>. After bursting balloon <code>i</code>, the left and right balloons become adjacent.</p>

<p>Assume there is an imaginary balloon with value <code>1</code> on both ends of the array. These balloons cannot be burst.</p>

<p>Return the <strong>maximum coins</strong> you can collect by bursting all the balloons wisely.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [3,1,5,8]

<strong>Output:</strong>
167

<strong>Explanation:</strong>

One optimal order is

[3,1,5,8]
→ burst 1 (15 coins)
→ burst 5 (120 coins)
→ burst 3 (24 coins)
→ burst 8 (8 coins)

Total coins = 167.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,5]

<strong>Output:</strong>
10

<strong>Explanation:</strong>

Burst balloon 1 first,
then balloon 5.

Total coins = 10.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 300</code></li>
  <li><code>0 ≤ nums[i] ≤ 100</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Interval Dynamic Programming</strong> by adding virtual balloons of value <code>1</code> at both ends and defining <code>dp[i][j]</code> as the maximum coins obtainable by bursting all balloons between indices <code>i</code> and <code>j</code>, considering each balloon as the <strong>last</strong> one to burst, achieving <code>O(n³)</code> time and <code>O(n²)</code> space?</p>
