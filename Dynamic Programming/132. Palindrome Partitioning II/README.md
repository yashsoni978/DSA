<h2>132. Palindrome Partitioning II</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given a string <code>s</code>, partition <code>s</code> such that every substring of the partition is a <strong>palindrome</strong>.</p>

<p>Return the <strong>minimum number of cuts</strong> needed to partition the string into palindromic substrings.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "aab"

<strong>Output:</strong>
1

<strong>Explanation:</strong>

The palindrome partition is

["aa", "b"]

Only one cut is required.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "a"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The string itself is a
palindrome, so no cut
is needed.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "ab"

<strong>Output:</strong>
1

<strong>Explanation:</strong>

The only valid partition is

["a", "b"]

Hence one cut is required.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 2000</code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by precomputing whether every substring is a palindrome and then computing the minimum cuts for every starting index, achieving <code>O(n²)</code> time and <code>O(n²)</code> space?</p>
