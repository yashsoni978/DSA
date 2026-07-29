<h2>8. String to Integer (atoi)</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Implement the <code>myAtoi(string s)</code> function, which converts a string to a 32-bit signed integer.</p>

<p>The algorithm for <code>myAtoi</code> is as follows:</p>

<ol>
  <li>Ignore any leading whitespace.</li>
  <li>Check if the next character is <code>'+'</code> or <code>'-'</code> to determine the sign.</li>
  <li>Read digits until a non-digit character is encountered or the string ends.</li>
  <li>If no digits are read, return <code>0</code>.</li>
  <li>If the integer is outside the 32-bit signed integer range <code>[-2<sup>31</sup>, 2<sup>31</sup> - 1]</code>, clamp it to the nearest limit.</li>
</ol>

<p>Return the resulting integer.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "42"

<strong>Output:</strong>
42

<strong>Explanation:</strong>

The string contains only digits,
so the result is 42.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "   -042"

<strong>Output:</strong>
-42

<strong>Explanation:</strong>

Leading spaces are ignored.

The '-' sign makes
the result negative.

Leading zeros are ignored.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "1337c0d3"

<strong>Output:</strong>
1337

<strong>Explanation:</strong>

Digits are read until
the character 'c' is encountered.

The remaining characters
are ignored.
</pre>

<p><strong>Example 4:</strong></p>

<pre>
<strong>Input:</strong>
s = "0-1"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

Parsing stops after reading '0'
because '-' is not a valid digit.
</pre>

<p><strong>Example 5:</strong></p>

<pre>
<strong>Input:</strong>
s = "words and 987"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The first non-space character
is not a sign or a digit,
so no valid conversion exists.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ s.length ≤ 200</code></li>
  <li><code>s</code> consists of English letters, digits <code>(0-9)</code>, spaces <code>' '</code>, <code>'+'</code>, <code>'-'</code>, and <code>'.'</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in a single pass by scanning the string once, handling leading spaces, sign, digit parsing, and integer overflow/underflow checks while maintaining <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
