<h2>Sieve of Eratosthenes</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a positive integer <code>n</code>, find and return all prime numbers less than or equal to <code>n</code> using the <strong>Sieve of Eratosthenes</strong> algorithm.</p>

<h3>Example 1</h3>

<pre>
Input: n = 10

Output: [2,3,5,7]

Explanation: The prime numbers less than or equal to 10
are 2, 3, 5, and 7.
</pre>

<h3>Example 2</h3>

<pre>
Input: n = 35

Output: [2,3,5,7,11,13,17,19,23,29,31]

Explanation: The prime numbers less than or equal to 35
are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, and 31.
</pre>

<h3>Approach</h3>

<ul>
<li>Create a boolean array <code>isPrime</code> of size <code>n + 1</code> and initially assume every number from <code>2</code> to <code>n</code> is prime.</li>
<li>Start with <code>2</code>, the first prime number.</li>
<li>If the current number is marked as prime, mark all of its multiples as non-prime.</li>
<li>Start marking multiples from <code>i * i</code> because smaller multiples would already have been marked by smaller prime numbers.</li>
<li>Continue this process while <code>i * i &lt;= n</code>.</li>
<li>Finally, traverse the boolean array and add every number still marked as prime to the result.</li>
</ul>

<h3>Why Start From <code>i * i</code>?</h3>

<p>For a prime number <code>i</code>, all multiples smaller than <code>i * i</code> have already been marked by smaller prime factors.</p>

<p>For example, when <code>i = 5</code>, we start from <code>25</code>:</p>

<pre>
5 × 2 = 10  → already marked by 2
5 × 3 = 15  → already marked by 3
5 × 4 = 20  → already marked by 2
5 × 5 = 25  → needs to be marked
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log log n)</code></p>
<p><strong>Space:</strong> <code>O(n)</code></p>

<hr>

<p><strong>Pattern:</strong> Math / Prime Numbers / Sieve</p>

<p><strong>Key Idea:</strong> Assume all numbers are prime initially, then repeatedly mark multiples of each prime as non-prime. The numbers that remain marked as prime are the required primes.</p>
