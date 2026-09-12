<h2>39. Combination Sum</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array of distinct integers and a target, find all unique combinations where the chosen numbers sum to <code>target</code>. The same number can be used <strong>unlimited times</strong>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
candidates = [2,3,6,7], target = 7

<strong>Output:</strong>
[[2,2,3],[7]] </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. At every index, choose the current element or move to the next element.</p>

<ul>
<li>If <code>target == 0</code>, store the current combination.</li>
<li>If <code>target &lt; 0</code>, stop that path.</li>
<li>When choosing <code>candidates[i]</code>, call recursively with <code>target - candidates[i]</code>.</li>
<li>Do <strong>not</strong> increase the index after choosing an element because it can be reused.</li>
<li>After recursion, remove the element to backtrack.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>Because every candidate can be used multiple times, after choosing <code>candidates[i]</code> we recurse from the <strong>same index</strong>.</p>

<pre>
choose → recurse → undo
             ↓
        same index
</pre>

<p><strong>Time Complexity:</strong> Exponential</p>
<p><strong>Space Complexity:</strong> <code>O(target)</code> recursion depth (excluding output)</p>
