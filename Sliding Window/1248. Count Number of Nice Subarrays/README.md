<h2>1248. Count Number of Nice Subarrays</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the number of contiguous subarrays containing exactly <code>k</code> odd numbers.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,1,2,1,1]
k = 3

<strong>Output:</strong>
2

<strong>Explanation:</strong>
The valid subarrays are:

[1,1,2,1]
[1,2,1,1]
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Generate every subarray, count its odd numbers, and increment the answer when the count equals <code>k</code>.</p>

<p>This takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique with the <strong>At Most</strong> trick.</p>

<pre>
Exactly(k) = AtMost(k) - AtMost(k - 1)
</pre>

<p>Convert each number conceptually into:</p>

<pre>
Odd  → 1
Even → 0
</pre>

<p>For <code>AtMost(k)</code>, maintain a window containing at most <code>k</code> odd numbers. For every <code>right</code>, add:</p>

<pre>
right - left + 1
</pre>

<p>because all subarrays ending at <code>right</code> are valid.</p>

<p><strong>Key Observation:</strong></p>

<p>Counting subarrays with <strong>exactly k</strong> odd numbers directly is difficult, so calculate the difference between subarrays with at most <code>k</code> and at most <code>k-1</code> odd numbers.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
