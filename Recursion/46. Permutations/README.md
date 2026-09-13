<h2>46. Permutations</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array of distinct integers, return all possible permutations.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums = [1,2,3]

<strong>Output:</strong>
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. At each position, choose one of the unused elements, add it to the current permutation, and recursively build the remaining positions. After returning, remove the element to try another choice.</p>

<p><strong>Key Observation:</strong></p>
<p>Unlike subsets, the <strong>order matters</strong>. Every element must be used exactly once, and there are <code>n!</code> possible permutations.</p>

<p><strong>Time Complexity:</strong> <code>O(n × n!)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code> recursion/visited space, excluding the output.</p>
