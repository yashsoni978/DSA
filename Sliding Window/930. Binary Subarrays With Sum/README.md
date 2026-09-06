<h2>930. Binary Subarrays With Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a binary array <code>nums</code> and an integer <code>goal</code>, return the number of non-empty subarrays whose sum equals <code>goal</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,0,1,0,1]
goal = 2

<strong>Output:</strong>
4
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Generate every subarray and calculate its sum. If the sum equals <code>goal</code>, increment the answer.</p>

<p>This takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique with:</p>

<pre>
count(sum ≤ goal) - count(sum ≤ goal - 1)
</pre>

<p>For a binary array, we can find the number of subarrays with sum at most a given value using a sliding window.</p>

<p><strong>Key Observation:</strong></p>

<p>The number of subarrays with sum exactly <code>goal</code> is:</p>

<pre>
exactly(goal) = atMost(goal) - atMost(goal - 1)
</pre>

<p>Maintain a window whose sum is at most the required value. For every <code>right</code>, after making the window valid, add:</p>

<pre>
right - left + 1
</pre>

<p>because every subarray ending at <code>right</code> and starting from <code>left</code> to <code>right</code> is valid.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
