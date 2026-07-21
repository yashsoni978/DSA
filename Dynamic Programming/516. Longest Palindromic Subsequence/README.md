<h2>516. Longest Palindromic Subsequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code>, return the length of the <strong>longest palindromic subsequence</strong> in the string.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no characters without changing the relative order of the remaining characters.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "bbbab"

<strong>Output:</strong>
4

<strong>Explanation:</strong>

One longest palindromic subsequence is:

"bbbb"

Length = 4
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "cbbd"

<strong>Output:</strong>
2

<strong>Explanation:</strong>

One longest palindromic subsequence is:

"bb"

Length = 2
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 1000</code></li>
  <li><code>s</code> consists only of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n²)</code> time and optimize the space complexity to <code>O(n)</code>? (Hint: It can also be solved by finding the <strong>Longest Common Subsequence (LCS)</strong> between the string and its reverse.)</p>
