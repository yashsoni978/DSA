<h2>5. Longest Palindromic Substring</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code>, return the <strong>longest palindromic substring</strong> in <code>s</code>.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<p>If there are multiple longest palindromic substrings, return any one of them.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "babad"

<strong>Output:</strong>
"bab"

<strong>Explanation:</strong>

"bab" is a palindrome.

"aba" is also a valid answer
since it has the same maximum length.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "cbbd"

<strong>Output:</strong>
"bb"

<strong>Explanation:</strong>

The longest palindrome
present in the string is "bb".
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "a"

<strong>Output:</strong>
"a"

<strong>Explanation:</strong>

A single character
is always a palindrome.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 1000</code></li>
  <li><code>s</code> consists of only English letters and digits.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n²)</code> time and <code>O(1)</code> extra space using the <strong>Expand Around Center</strong> technique? Can you further optimize it to <code>O(n)</code> time using <strong>Manacher's Algorithm</strong>?</p>
