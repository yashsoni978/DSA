<h2>494. Target Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an integer array <code>nums</code> and an integer <code>target</code>.</p>

<p>You want to build an expression by assigning either a <code>'+'</code> or <code>'-'</code> sign before each integer in <code>nums</code>, then concatenate all the integers.</p>

<p>Return the <strong>number of different expressions</strong> that evaluate to <code>target</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,1,1,1,1]
target = 3

<strong>Output:</strong>
5

<strong>Explanation:</strong>

There are five possible expressions:

-1 +1 +1 +1 +1 = 3
+1 -1 +1 +1 +1 = 3
+1 +1 -1 +1 +1 = 3
+1 +1 +1 -1 +1 = 3
+1 +1 +1 +1 -1 = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1]
target = 1

<strong>Output:</strong>
1

<strong>Explanation:</strong>

The only valid expression is:

+1 = 1
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 20</code></li>
  <li><code>0 ≤ nums[i] ≤ 1000</code></li>
  <li><code>0 ≤ sum(nums[i]) ≤ 1000</code></li>
  <li><code>-1000 ≤ target ≤ 1000</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you transform this problem into a <strong>Count Subsets with Sum</strong> problem using the relation <code>subsetSum = (totalSum - target) / 2</code> (or equivalently <code>(totalSum + target) / 2</code>), and solve it using <strong>Dynamic Programming</strong> in <code>O(n × subsetSum)</code> time with <code>O(subsetSum)</code> space?</p>
