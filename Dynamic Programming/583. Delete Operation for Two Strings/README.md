<h2>583. Delete Operation for Two Strings</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two strings <code>word1</code> and <code>word2</code>, return the <strong>minimum number of steps</strong> required to make <code>word1</code> and <code>word2</code> the same.</p>

<p>In one step, you can delete exactly one character from either string.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
word1 = "sea"
word2 = "eat"

<strong>Output:</strong>
2

<strong>Explanation:</strong>

Delete 's' from "sea":
"ea"

Delete 't' from "eat":
"ea"

Both strings are now equal.

Minimum operations = 2
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
word1 = "leetcode"
word2 = "etco"

<strong>Output:</strong>
4
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ word1.length, word2.length ≤ 500</code></li>
  <li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>This problem can be converted into an <strong>Longest Common Subsequence (LCS)</strong> problem.</p>

<p>The characters that we <strong>keep</strong> must form a common subsequence of both strings.</p>

<p>To minimize deletions, we want to keep the <strong>longest common subsequence</strong>.</p>

<p>Suppose:</p>

<pre>
word1 = "sea"
word2 = "eat"
</pre>

<p>The LCS is:</p>

<pre>
"ea"
</pre>

<p>Length of word1 = 3</p>

<p>Length of word2 = 3</p>

<p>We keep 2 characters in both strings.</p>

<pre>
deletions from word1 = 3 - 2 = 1
deletions from word2 = 3 - 2 = 1

total = 2
</pre>

<p>Therefore:</p>

<pre>
answer = n + m - 2 × LCS(word1, word2)
</pre>

<p><strong>Approach:</strong></p>

<p>First calculate the LCS of <code>word1</code> and <code>word2</code> using Dynamic Programming.</p>

<p>Define:</p>

<pre>
dp[i][j] = LCS length of the first i characters of word1
           and the first j characters of word2
</pre>

<p>If the current characters match:</p>

<pre>
word1[i-1] == word2[j-1]

dp[i][j] = 1 + dp[i-1][j-1]
</pre>

<p>If they do not match:</p>

<pre>
dp[i][j] = max(dp[i-1][j], dp[i][j-1])
</pre>

<p>After calculating the LCS:</p>

<pre>
L = dp[n][m]

answer = n + m - 2 * L
</pre>

<p><strong>Why subtract twice?</strong></p>

<p>The common subsequence is already present in both strings, so we don't delete those characters.</p>

<p>Therefore, we delete:</p>

<pre>
(n - L) characters from word1

(m - L) characters from word2
</pre>

<p>Total:</p>

<pre>
(n - L) + (m - L)

= n + m - 2L
</pre>

<p><strong>Example:</strong></p>

<pre>
word1 = "leetcode"
word2 = "etco"

LCS = "etco"
LCS length = 4

n = 8
m = 4

answer = 8 + 4 - 2 × 4
       = 12 - 8
       = 4
</pre>

<p><strong>Alternative Direct DP:</strong></p>

<p>This problem can also be solved directly using DP where:</p>

<pre>
dp[i][j] = minimum deletions required to make
           word1[0...i-1] and word2[0...j-1] equal
</pre>

<p>If the characters match:</p>

<pre>
dp[i][j] = dp[i-1][j-1]
</pre>

<p>If they do not match, we can delete either character:</p>

<pre>
dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])
</pre>

<p>However, recognizing the <strong>LCS connection</strong> is usually the cleaner approach.</p>

<p><strong>Time Complexity:</strong> <code>O(n × m)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n × m)</code></p>

<p>Space can be optimized to <code>O(min(n, m))</code> using a 1D DP array.</p>
