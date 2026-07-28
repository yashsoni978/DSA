<h2>1903. Largest Odd Number in String</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>You are given a string <code>num</code> representing a large integer.</p>

<p>Return the <strong>largest-valued odd integer</strong> (as a string) that is a <strong>non-empty substring</strong> of <code>num</code>.</p>

<p>If no odd integer exists, return an empty string <code>""</code>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
num = "52"

<strong>Output:</strong>
"5"

<strong>Explanation:</strong>

The substrings are:

"5", "2", "52"

Among them, the largest odd integer is "5".
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
num = "4206"

<strong>Output:</strong>
""

<strong>Explanation:</strong>

Every digit is even,
so no odd-valued substring exists.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
num = "35427"

<strong>Output:</strong>
"35427"

<strong>Explanation:</strong>

The last digit is odd,
so the entire string represents
the largest possible odd substring.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ num.length ≤ 10<sup>5</sup></code></li>
  <li><code>num</code> consists only of digits <code>'0'</code> to <code>'9'</code>.</li>
  <li><code>num</code> may contain leading zeros.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in a single pass by scanning from the end of the string to find the rightmost odd digit, then returning the prefix ending at that position, achieving <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
