<h2>214. Shortest Palindrome</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given a string <code>s</code>. You can convert it into a palindrome by adding characters <strong>only in front</strong> of it.</p>

<p>Return the <strong>shortest palindrome</strong> you can form.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "aacecaaa"

<strong>Output:</strong>
"aaacecaaa"

<strong>Explanation:</strong>

The longest palindromic prefix is
"aacecaa".

Adding the reverse of the remaining suffix
("a") to the front gives:

"aaacecaaa".
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "abcd"

<strong>Output:</strong>
"dcbabcd"

<strong>Explanation:</strong>

The longest palindromic prefix is
"a".

Reverse the remaining suffix "bcd"
to obtain "dcb",
and prepend it to the original string.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ s.length ≤ 5 × 10<sup>4</sup></code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n)</code> time by finding the <strong>longest palindromic prefix</strong> using the <strong>KMP (LPS)</strong> algorithm on the string <code>s + "#" + reverse(s)</code>, then prepending the reverse of the remaining suffix?</p>
