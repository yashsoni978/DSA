<h2>1092. Shortest Common Supersequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given two strings <code>str1</code> and <code>str2</code>, return the <strong>shortest string</strong> that has both <code>str1</code> and <code>str2</code> as subsequences.</p>

<p>If there are multiple valid shortest common supersequences, return <strong>any one</strong> of them.</p>

<p>A <strong>subsequence</strong> of a string is obtained by deleting zero or more characters without changing the order of the remaining characters.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
str1 = "abac"
str2 = "cab"

<strong>Output:</strong>
"cabac"

<strong>Explanation:</strong>

Both strings are subsequences of "cabac":

"abac" → a b a c
"cab"  → c a b

The length is minimum.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
str1 = "aaaaaaaa"
str2 = "aaaaaaaa"

<strong>Output:</strong>
"aaaaaaaa"

<strong>Explanation:</strong>

Both strings are already identical,
so the shortest common supersequence
is the string itself.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ str1.length, str2.length ≤ 1000</code></li>
  <li><code>str1</code> and <code>str2</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem by first computing the <strong>Longest Common Subsequence (LCS)</strong>, then reconstructing the answer by merging the unmatched characters from both strings around the LCS, achieving <code>O(n × m)</code> time?</p>
