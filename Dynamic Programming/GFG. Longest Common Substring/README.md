<h2>Longest Common Substring</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two strings <code>s1</code> and <code>s2</code>, determine the length of the <strong>longest substring</strong> that appears in both strings.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p><strong>Note:</strong> Comparison is <strong>case-sensitive</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s1 = "ABCDGH"
s2 = "ACDGHR"

<strong>Output:</strong>
4

<strong>Explanation:</strong>

The longest common substring is:

"CDGH"

Length = 4
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s1 = "abc"
s2 = "acb"

<strong>Output:</strong>
1

<strong>Explanation:</strong>

The longest common substrings are:

"a", "b", and "c"

Each has length 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s1 = "YZ"
s2 = "yz"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

Comparison is case-sensitive.

'Y' ≠ 'y'
'Z' ≠ 'z'

Hence, no common substring exists.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s1.size(), s2.size() ≤ 10<sup>3</sup></code></li>
  <li>Both strings consist only of uppercase and lowercase English letters.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × m)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(m)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by tracking only consecutive matching characters and optimizing the space complexity to <code>O(m)</code> using rolling arrays?</p>
