<h2>992. Subarrays with K Different Integers</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the number of subarrays containing exactly <code>k</code> distinct integers.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,1,2,3]
k = 2

<strong>Output:</strong>
7
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Generate every subarray and count its distinct elements using a set or frequency map.</p>

<p>This takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window + At Most</strong> technique.</p>

<pre>
Exactly(k) = AtMost(k) - AtMost(k - 1)
</pre>

<p>Create a helper function that counts subarrays containing <strong>at most <code>k</code> distinct integers</strong>.</p>

<ol>
  <li>Expand the window using <code>right</code>.</li>
  <li>Store frequencies using a hash map.</li>
  <li>If distinct elements exceed <code>k</code>, move <code>left</code> forward.</li>
  <li>Add <code>right - left + 1</code> to the answer.</li>
</ol>

<p><strong>Key Observation:</strong></p>

<p>For every <code>right</code>, once the window has at most <code>k</code> distinct integers, all subarrays ending at <code>right</code> and starting from <code>left</code> to <code>right</code> are valid.</p>

<pre>
Number of valid subarrays = right - left + 1
</pre>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
