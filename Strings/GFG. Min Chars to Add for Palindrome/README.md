<h2>Min Chars to Add for Palindrome</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given a string <code>s</code>, find the <strong>minimum number of characters</strong> that must be added <strong>at the front</strong> of the string to make it a palindrome.</p>

<p>A <strong>palindrome</strong> is a string that reads the same forward and backward.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "abc"

<strong>Output:</strong>
2

<strong>Explanation:</strong>

Add 'c' and 'b'
to the front of the string.

Result:

"cbabc"

which is a palindrome.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "aacecaaaa"

<strong>Output:</strong>
2

<strong>Explanation:</strong>

Add two 'a' characters
to the front.

Result:

"aaaacecaaaa"

which is a palindrome.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 10<sup>6</sup></code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n)</code> time by finding the <strong>longest palindromic prefix</strong> using the <strong>KMP (LPS)</strong> algorithm on the string <code>s + "$" + reverse(s)</code>? The answer is then <code>n - LPS[last]</code>.</p>
