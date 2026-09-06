<h2>55. Jump Game</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code>, where <code>nums[i]</code> represents the maximum jump length from index <code>i</code>, determine if you can reach the last index.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
nums = [2,3,1,1,4]

<strong>Output:</strong>
true
</pre>

<p><strong>Greedy Approach:</strong></p>

<p>Keep track of the <strong>farthest index</strong> that can be reached.</p>

<p>For every index, update the farthest reachable position. If the current index is beyond the farthest position, reaching it is impossible.</p>

<p><strong>Key Observation:</strong></p>

<p>Always maintain the <strong>maximum reachable index</strong>. If it reaches or passes the last index, the answer is <code>true</code>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
