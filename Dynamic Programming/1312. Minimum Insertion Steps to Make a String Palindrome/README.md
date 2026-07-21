<h2>1312. Minimum Insertion Steps to Make a String Palindrome</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given a string <code>s</code>, return the <strong>minimum number of insertions</strong> needed to make <code>s</code> a palindrome.</p>

<p>You may insert a character at <strong>any position</strong> in the string.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "zzazz"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The string is already a palindrome,
so no insertions are required.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "mbadm"

<strong>Output:</strong>
2

<strong>Explanation:</strong>

One possible palindrome is:

"mbdadbm"

or

"mdbabdm"

Minimum insertions required = 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "leetcode"

<strong>Output:</strong>
5

<strong>Explanation:</strong>

At least five insertions are needed
to transform the string into a palindrome.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 500</code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using the relation <code>Minimum Insertions = n − LPS</code>, where <strong>LPS (Longest Palindromic Subsequence)</strong> is computed as the <strong>Longest Common Subsequence (LCS)</strong> between the string and its reverse, achieving <code>O(n²)</code> time and <code>O(n)</code> space?</p>
