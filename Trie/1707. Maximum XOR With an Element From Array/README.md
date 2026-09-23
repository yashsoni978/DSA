<h2>1707. Maximum XOR With an Element From Array</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Given an integer array <code>nums</code> and an array of queries <code>queries</code>, where <code>queries[i] = [xi, mi]</code>, find the maximum value of <code>xi XOR num</code> for every query, where <code>num</code> is an element of <code>nums</code> satisfying <code>num &lt;= mi</code>.</p>

<p>If no element in <code>nums</code> satisfies the condition, return <code>-1</code> for that query.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums = [0,1,2,3,4]
queries = [[3,1],[1,3],[5,6]]

<strong>Output:</strong>
[3,3,7] </pre>

<p><strong>Explanation:</strong></p>

<p>For <code>[3,1]</code>, valid numbers are <code>[0,1]</code>. The maximum is <code>3 XOR 0 = 3</code>.</p>

<p>For <code>[1,3]</code>, valid numbers are <code>[0,1,2,3]</code>. The maximum is <code>1 XOR 2 = 3</code>.</p>

<p>For <code>[5,6]</code>, all numbers are valid. The maximum is <code>5 XOR 2 = 7</code>.</p>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Binary Trie</strong> combined with <strong>offline queries</strong>.</p>

<p>Sort <code>nums</code> and sort the queries according to their limit <code>mi</code>. Process queries from the smallest limit to the largest.</p>

<p>While processing a query, insert into the Trie every number from <code>nums</code> that is less than or equal to its limit.</p>

<p>Once all valid numbers have been inserted, find the maximum XOR with <code>xi</code> using the Binary Trie.</p>

<p>To maximize XOR, for every bit from the most significant bit to the least significant bit, prefer the <strong>opposite bit</strong> whenever it exists in the Trie.</p>

<p><strong>Key Observation:</strong></p>

<p>The condition <code>num &lt;= mi</code> makes a direct Trie solution difficult because the set of allowed numbers changes for every query. Sorting queries by <code>mi</code> allows us to incrementally add valid numbers to the Trie without removing anything.</p>

<p><strong>Time Complexity:</strong> <code>O(N log N + Q log Q + 32 × (N + Q))</code></p>

<p><strong>Space Complexity:</strong> <code>O(32 × N + Q)</code></p>
