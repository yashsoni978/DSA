<h2>1143. Longest Common Subsequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two strings <code>text1</code> and <code>text2</code>, return the length of their <strong>Longest Common Subsequence (LCS)</strong>.</p>

<p>A <strong>subsequence</strong> of a string is a new string generated from the original string by deleting some (or no) characters without changing the relative order of the remaining characters.</p>

<p>A <strong>common subsequence</strong> of two strings is a subsequence that appears in both strings.</p>

<p>If there is no common subsequence, return <code>0</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
text1 = "abcde"
text2 = "ace"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The longest common subsequence is:

"ace"

Length = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
text1 = "abc"
text2 = "abc"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The entire string is common.

LCS = "abc"
Length = 3
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
text1 = "abc"
text2 = "def"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

There is no common subsequence
between the two strings.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ text1.length, text2.length ≤ 1000</code></li>
  <li><code>text1</code> and <code>text2</code> consist only of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n × m)</code> time and optimize the space complexity from <code>O(n × m)</code> to <code>O(m)</code> using rolling arrays?</p>
