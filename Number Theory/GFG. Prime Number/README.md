<h2>Prime Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
A prime number has exactly two divisors: 1 and itself.

We only need to check divisors up to √N.
If any number from 2 to √N divides n,
then n is not prime.
</pre>

<h3>Approach</h3>

<ol>
  <li>If <code>n &lt; 2</code>, return false.</li>
  <li>Loop from <code>i = 2</code> while <code>i * i &lt;= n</code>.</li>
  <li>If <code>n % i == 0</code>, return false.</li>
  <li>If no divisor is found, return true.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(√N)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Mathematics / Prime Check / Square Root Optimization</p>

<p><strong>Key Idea:</strong> Check divisibility only up to √N.</p>
