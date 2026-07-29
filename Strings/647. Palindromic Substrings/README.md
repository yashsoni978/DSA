<h2>647. Palindromic Substrings</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code>, return the <strong>number of palindromic substrings</strong> in it.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<p>A substring is a contiguous sequence of characters within the string.</p>

<p>Substrings with different start or end indices are counted as different substrings, even if they consist of the same characters.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "abc"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The palindromic substrings are:

"a"
"b"
"c"

Total = 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "aaa"

<strong>Output:</strong>
6

<strong>Explanation:</strong>

The palindromic substrings are:

"a"
"a"
"a"
"aa"
"aa"
"aaa"

Total = 6.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 1000</code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n²)</code> time and <code>O(1)</code> extra space by expanding around every possible center (both odd- and even-length palindromes)? Can you further optimize it to <code>O(n)</code> time using <strong>Manacher's Algorithm</strong>?</p>
