<h2>45. Jump Game II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given a <code>0</code>-indexed array of integers <code>nums</code> of length <code>n</code>.</p>

<p>You are initially positioned at <code>nums[0]</code>.</p>

<p>Each element <code>nums[i]</code> represents the <strong>maximum length of a forward jump</strong> from index <code>i</code>.</p>

<p>In other words, if you are at index <code>i</code>, you can jump to any index <code>i + j</code> where:</p>

<ul>
  <li><code>0 &lt;= j &lt;= nums[i]</code></li>
  <li><code>i + j &lt; n</code></li>
</ul>

<p>Return the <strong>minimum number of jumps</strong> required to reach the last index of <code>nums</code>.</p>

<p>You can assume that you can always reach the last index.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2.
Jump from index 0 to index 1, then jump from index 1 to the last index.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,3,0,1,4]
<strong>Output:</strong> 2
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
  <li>It's guaranteed that you can reach <code>nums[n - 1]</code>.</li>
</ul>
