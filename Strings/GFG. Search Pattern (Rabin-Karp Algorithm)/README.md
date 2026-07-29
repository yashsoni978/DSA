<h2>Search Pattern (Rabin-Karp Algorithm)</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given two strings:</p>

<ul>
  <li>A <code>text</code> string in which you want to search.</li>
  <li>A <code>pattern</code> string that you are looking for within the text.</li>
</ul>

<p>Return all <strong>0-based indices</strong> where the <code>pattern</code> occurs as a substring in the <code>text</code>.</p>

<p>If the pattern does not occur in the text, return an empty list.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
text = "geeksforgeeks"
pattern = "geek"

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
text = "aabaacaadaabaaba"
pattern = "aaba"

<strong>Output:</strong>
[0, 9, 12]

<strong>Explanation:</strong>

The pattern occurs three times
in the text,
starting at indices 0, 9, and 12.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ text.length ≤ 10<sup>6</sup></code></li>
  <li><code>1 ≤ pattern.length ≤ text.length</code></li>
  <li>Both <code>text</code> and <code>pattern</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this using the <strong>Rabin–Karp Algorithm</strong> by computing a rolling hash for the pattern and each window of the text, comparing hashes before verifying characters, achieving an average-case time complexity of <code>O(n + m)</code> and <code>O(1)</code> extra space (excluding the output list)?</p>
