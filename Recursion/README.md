<h2>60. Permutation Sequence</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Given two integers <code>n</code> and <code>k</code>, return the <strong>k-th permutation sequence</strong> of the numbers <code>1</code> to <code>n</code>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
n = 3, k = 3

<strong>Output:</strong>
"213" </pre>

<p><strong>Approach:</strong></p>
<p>Use the <strong>factorial number system</strong>. There are <code>(n-1)!</code> permutations for each possible first digit. Use <code>k</code> to determine which block the answer belongs to, select that digit, and repeat for the remaining positions.</p>

<p><strong>Key Observation:</strong></p>
<p>Instead of generating all <code>n!</code> permutations, directly determine the required digit at each position using factorial blocks.</p>

<p><strong>Time Complexity:</strong> <code>O(n²)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
