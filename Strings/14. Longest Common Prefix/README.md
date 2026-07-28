<h2>14. Longest Common Prefix</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Write a function to find the <strong>longest common prefix</strong> string amongst an array of strings.</p>

<p>If there is no common prefix, return an empty string <code>""</code>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
strs = ["flower","flow","flight"]

<strong>Output:</strong>
"fl"

<strong>Explanation:</strong>

The common prefixes are:

"f"
"fl"

The next characters differ,
so the longest common prefix is "fl".
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
strs = ["dog","racecar","car"]

<strong>Output:</strong>
""

<strong>Explanation:</strong>

The strings do not share
any common starting characters,
so the answer is an empty string.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ strs.length ≤ 200</code></li>
  <li><code>0 ≤ strs[i].length ≤ 200</code></li>
  <li><code>strs[i]</code> consists of only lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this by using the first string as a reference and comparing characters column by column across all strings, achieving <code>O(n × m)</code> time complexity, where <code>n</code> is the number of strings and <code>m</code> is the length of the shortest string?</p>
