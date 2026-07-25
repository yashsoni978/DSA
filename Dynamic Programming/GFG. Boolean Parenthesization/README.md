<h2>Boolean Parenthesization</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given a boolean expression <code>s</code> consisting of the following symbols:</p>

<ul>
  <li><code>'T'</code> → represents <strong>true</strong>.</li>
  <li><code>'F'</code> → represents <strong>false</strong>.</li>
  <li><code>'&amp;'</code> → Boolean <strong>AND</strong>.</li>
  <li><code>'|'</code> → Boolean <strong>OR</strong>.</li>
  <li><code>'^'</code> → Boolean <strong>XOR</strong>.</li>
</ul>

<p>Return the <strong>number of ways</strong> to parenthesize the expression such that it evaluates to <strong>true</strong>.</p>

<p><strong>Note:</strong> The answer is guaranteed to fit in a 32-bit signed integer.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "T|T&amp;F^T"

<strong>Output:</strong>
4

<strong>Explanation:</strong>

The expression evaluates to true
in the following ways:

((T|T)&(F^T))
(T|(T&(F^T)))
(((T|T)&F)^T)
(T|((T&F)^T))

Hence the answer is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "T^F|F"

<strong>Output:</strong>
2

<strong>Explanation:</strong>

The valid parenthesizations are

((T^F)|F)
(T^(F|F))

Both evaluate to true.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ |s| ≤ 100</code></li>
  <li>The expression contains only <code>'T'</code>, <code>'F'</code>, <code>'&amp;'</code>, <code>'|'</code>, and <code>'^'</code>.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n³)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n²)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Interval Dynamic Programming</strong> by defining <code>dp[i][j][0]</code> and <code>dp[i][j][1]</code> as the number of ways the substring from <code>i</code> to <code>j</code> evaluates to <strong>false</strong> and <strong>true</strong>, respectively, and combining results based on the boolean operator at each partition?</p>
