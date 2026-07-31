<h2>Search Pattern</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given two strings, a text string <code>txt</code> and a pattern string <code>pat</code>, both consisting of lowercase English alphabets.</p>

<p>Return all <strong>0-based indices</strong> where the pattern <code>pat</code> occurs as a substring in <code>txt</code>.</p>

<p>If the pattern does not occur in the text, return an empty list.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
txt = "geeksforgeeks"
pat = "geek"

<strong>Output:</strong>
[0, 8]

<strong>Explanation:</strong>

The pattern "geek"
appears twice in the text,
starting at indices 0 and 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
txt = "abesdu"
pat = "edu"

<strong>Output:</strong>
[]

<strong>Explanation:</strong>

The pattern "edu"
does not occur anywhere
in the text.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
txt = "aabaacaadaabaaba"
pat = "aaba"

<strong>Output:</strong>
[0, 9, 12]

<strong>Explanation:</strong>

The pattern occurs three times
in the text,
starting at indices
0, 9, and 12.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ txt.length ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ pat.length ≤ txt.length</code></li>
  <li>Both <code>txt</code> and <code>pat</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n + m)</code> time using the <strong>KMP (Knuth–Morris–Pratt)</strong> algorithm by preprocessing the pattern into an <strong>LPS (Longest Prefix Suffix)</strong> array and then scanning the text in a single pass?</p>
