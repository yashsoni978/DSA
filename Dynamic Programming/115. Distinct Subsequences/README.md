<h2>115. Distinct Subsequences</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given two strings <code>s</code> and <code>t</code>, return the <strong>number of distinct subsequences</strong> of <code>s</code> which equals <code>t</code>.</p>

<p>A <strong>subsequence</strong> of a string is obtained by deleting zero or more characters without changing the relative order of the remaining characters.</p>

<p>The answer is guaranteed to fit within a 32-bit signed integer.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "rabbbit"
t = "rabbit"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

There are three distinct ways to delete
one of the three 'b' characters from
"rabbbit" to obtain "rabbit".
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "babgbag"
t = "bag"

<strong>Output:</strong>
5

<strong>Explanation:</strong>

There are five distinct subsequences
of "babgbag" that equal "bag".
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length, t.length ≤ 1000</code></li>
  <li><code>s</code> and <code>t</code> consist of English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n × m)</code> time while optimizing the space complexity to <code>O(m)</code> using rolling arrays?</p>
