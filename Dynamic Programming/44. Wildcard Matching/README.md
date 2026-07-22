<h2>44. Wildcard Matching</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given an input string <code>s</code> and a pattern <code>p</code>, implement wildcard pattern matching with support for the special characters <code>'?'</code> and <code>'*'</code>.</p>

<ul>
  <li><code>'?'</code> matches <strong>any single character</strong>.</li>
  <li><code>'*'</code> matches <strong>any sequence of characters</strong> (including the empty sequence).</li>
</ul>

<p>The matching should cover the <strong>entire input string</strong>, not just a substring.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "aa"
p = "a"

<strong>Output:</strong>
false

<strong>Explanation:</strong>

The pattern "a" matches only one character,
but the string contains two characters.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "aa"
p = "*"

<strong>Output:</strong>
true

<strong>Explanation:</strong>

'*' can match any sequence of characters,
including the entire string "aa".
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "cb"
p = "?a"

<strong>Output:</strong>
false

<strong>Explanation:</strong>

'?' matches 'c', but 'a' does not
match 'b', so the pattern fails.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ s.length, p.length ≤ 2000</code></li>
  <li><code>s</code> contains only lowercase English letters.</li>
  <li><code>p</code> contains only lowercase English letters, <code>'?'</code>, and <code>'*'</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n × m)</code> time while optimizing the space complexity to <code>O(m)</code>, carefully handling the transitions for <code>'?'</code> and <code>'*'</code>?</p>
