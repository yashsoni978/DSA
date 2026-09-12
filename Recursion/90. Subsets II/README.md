<h2>90. Subsets II</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an integer array <code>nums</code> that may contain duplicates, return all possible subsets without duplicate subsets.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums = [1,2,2]

<strong>Output:</strong>
[[],[1],[1,2],[1,2,2],[2],[2,2]] </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. Sort the array first so that duplicate elements are adjacent. At each recursion level, skip a duplicate element if it is the same as the previous element.</p>

<p><strong>Key Observation:</strong></p>
<p>Duplicates are skipped only at the <strong>same recursion level</strong>. This prevents duplicate subsets while still allowing multiple copies of the same value in a subset.</p>

<p><strong>Time Complexity:</strong> <code>O(2<sup>n</sup>)</code> excluding output copying.</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code> recursion stack, excluding the output.</p>
