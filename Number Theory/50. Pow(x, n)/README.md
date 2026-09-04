<h2>50. Pow(x, n)</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Instead of multiplying x n times, use Binary Exponentiation.

If n is even:
x^n = (x^(n/2))²

If n is odd:
x^n = x × (x^(n/2))²

For negative n:
x^n = 1 / x^(-n)
</pre>

<h3>Approach</h3>

<ol>
  <li>Handle negative exponent by taking <code>1/x</code>.</li>
  <li>While <code>n &gt; 0</code>, check whether the current bit is 1.</li>
  <li>If it is 1, multiply the answer by <code>x</code>.</li>
  <li>Square <code>x</code> and divide <code>n</code> by 2.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(log |N|)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Mathematics / Binary Exponentiation / Fast Power</p>

<p><strong>Key Idea:</strong> Square the base and halve the exponent at every step.</p>
