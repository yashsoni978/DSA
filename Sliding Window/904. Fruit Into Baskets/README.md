<h2>904. Fruit Into Baskets</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an integer array <code>fruits</code>, where <code>fruits[i]</code> represents the type of fruit on the <code>i</code>-th tree.</p>

<p>You can collect fruits from a contiguous range of trees, but you can only have <strong>two types of fruits</strong> in your baskets. Return the maximum number of fruits you can collect.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
fruits = [1,2,1,2,3]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
The longest valid subarray is:

[1,2,1,2]

It contains only two types of fruits.
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Check every possible subarray and count the number of distinct fruit types.</p>

<p>This takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique with a frequency map.</p>

<ol>
  <li>Expand the window using <code>right</code>.</li>
  <li>Store the frequency of each fruit type.</li>
  <li>If the window contains more than <code>2</code> fruit types, move <code>left</code> forward.</li>
  <li>Update the maximum window length.</li>
</ol>

<p><strong>Key Observation:</strong></p>

<p>The problem is equivalent to finding the <strong>longest subarray containing at most two distinct values</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
