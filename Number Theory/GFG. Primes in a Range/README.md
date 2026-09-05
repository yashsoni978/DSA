<h2>Primes in a Range</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
We need to find all primes between l and r.

Instead of checking every number individually,
use the Sieve of Eratosthenes to find all primes
up to r efficiently.
</pre>

<h3>Approach</h3>

<ol>
  <li>Create a boolean array <code>isPrime</code> of size <code>r + 1</code>.</li>
  <li>Mark all numbers as prime initially.</li>
  <li>Starting from 2, mark all multiples of each prime as non-prime.</li>
  <li>Traverse from <code>l</code> to <code>r</code> and add the numbers still marked prime.</li>
  <li>Handle <code>1</code> separately since 1 is not prime.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(R log log R)

SC: O(R)
</pre>

<hr>

<p><strong>Pattern:</strong> Mathematics / Prime Numbers / Sieve of Eratosthenes</p>

<p><strong>Key Idea:</strong> Precompute all primes up to R using the Sieve, then collect primes in [L, R].</p>
