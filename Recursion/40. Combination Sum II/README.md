<h2>40. Combination Sum II</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array of candidates and a target, find all unique combinations whose sum equals <code>target</code>. Each element can be used <strong>at most once</strong>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
candidates = [10,1,2,7,6,1,5], target = 8

<strong>Output:</strong>
[[1,1,6],[1,2,5],[1,7],[2,6]] </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use <strong>Backtracking + Sorting</strong>.</p>

<ul>
<li>Sort the array so duplicate values are adjacent.</li>
<li>At each position, choose the current element and recurse with <code>i + 1</code>.</li>
<li>Skip duplicates at the <strong>same recursion level</strong> using <code>i &gt; index &amp;&amp; candidates[i] == candidates[i-1]</code>.</li>
<li>If <code>candidates[i] &gt; target</code>, stop because the array is sorted.</li>
<li>Backtrack by removing the chosen element.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>Unlike Combination Sum I, each element can be used only once, so recursion moves to <code>i + 1</code>. Sorting allows us to skip duplicate combinations.</p>

<pre>
Combination Sum I  → same index (reuse allowed)
Combination Sum II → i + 1      (use once)
</pre>

<p><strong>Time Complexity:</strong> Exponential</p>
<p><strong>Space Complexity:</strong> <code>O(n)</code> recursion depth (excluding output)</p>
