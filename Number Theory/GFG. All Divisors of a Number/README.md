<h2>All Divisors of a Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
If i divides n, then n / i is also a divisor.

So we only need to check i up to √n.
For every divisor i, store both i and n/i.
Finally, sort the divisors.
</pre>

<h3>Approach</h3>

<ol>
  <li>Loop from <code>i = 1</code> to <code>i * i &lt;= n</code>.</li>
  <li>If <code>n % i == 0</code>, add <code>i</code>.</li>
  <li>If <code>i != n/i</code>, also add <code>n/i</code>.</li>
  <li>Sort the collected divisors in ascending order.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(√N + D log D)

SC: O(D)

D = number of divisors
</pre>

<hr>

<p><strong>Pattern:</strong> Mathematics / Divisors / Square Root Optimization</p>

<p><strong>Key Idea:</strong> Check only up to √N and collect divisor pairs.</p>
