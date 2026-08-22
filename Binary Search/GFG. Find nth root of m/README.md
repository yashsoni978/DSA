<h2>Find nth Root of m</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two numbers <code>n</code> and <code>m</code>, find the <strong>nth root of m</strong>.</p>

<p>If the nth root is not an integer, return <code>-1</code>.</p>

<p>In other words, find an integer <code>x</code> such that:</p>

<pre>
x^n = m
</pre>

<p>If such an integer does not exist, return <code>-1</code>.</p>

<h3>Example 1</h3>

<pre>
Input: n = 3, m = 8

Output: 2

Explanation:
2^3 = 8
Therefore, the 3rd root of 8 is 2.
</pre>

<h3>Example 2</h3>

<pre>
Input: n = 3, m = 9

Output: -1

Explanation:
There is no integer x such that:

x^3 = 9

Therefore, return -1.
</pre>

<h3>Example 3</h3>

<pre>
Input: n = 4, m = 16

Output: 2

Explanation:
2^4 = 16
Therefore, the 4th root of 16 is 2.
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search</strong> on the possible answer.</li>
<li>The answer can be between <code>1</code> and <code>m</code>.</li>
<li>For every <code>mid</code>, calculate <code>mid^n</code>.</li>
<li>If <code>mid^n == m</code>, then <code>mid</code> is the required nth root.</li>
<li>If <code>mid^n &lt; m</code>, the current value is too small, so search on the right.</li>
<li>If <code>mid^n &gt; m</code>, the current value is too large, so search on the left.</li>
<li>If binary search finishes without finding an exact power, return <code>-1</code>.</li>
</ul>

<h3>Important Idea</h3>

<pre>
We are looking for:

mid^n = m
</pre>

<p>Since the function:</p>

<pre>
f(x) = x^n
</pre>

<p>is increasing for positive integers, we can apply Binary Search.</p>

<h3>Example</h3>

<pre>
n = 3
m = 8

Search range:

low = 1
high = 8
</pre>

<p>First:</p>

<pre>
mid = 4

4^3 = 64

64 > 8

Therefore, 4 is too large.

high = 3
</pre>

<p>Next:</p>

<pre>
low = 1
high = 3

mid = 2

2^3 = 8

8 == 8

Therefore:

Answer = 2
</pre>

<h3>Full Dry Run</h3>

<pre>
n = 3
m = 9

low = 1
high = 9
</pre>

<p><strong>Iteration 1:</strong></p>

<pre>
mid = 5

5^3 = 125

125 > 9

high = 4
</pre>

<p><strong>Iteration 2:</strong></p>

<pre>
low = 1
high = 4

mid = 2

2^3 = 8

8 < 9

low = 3
</pre>

<p><strong>Iteration 3:</strong></p>

<pre>
low = 3
high = 4

mid = 3

3^3 = 27

27 > 9

high = 2
</pre>

<p>Now:</p>

<pre>
low = 3
high = 2
</pre>

<p>The search ends without finding an integer whose cube is <code>9</code>.</p>

<pre>
Answer = -1
</pre>

<h3>Power Calculation</h3>

<p>We need to calculate <code>mid^n</code>. Instead of using <code>pow()</code>, we can calculate it manually.</p>

<pre>
long long power = 1;

for(int i = 0; i < n; i++) {
    power *= mid;

    if(power > m)
        break;
}
</pre>

<p>The early <code>break</code> is useful because once the power becomes greater than <code>m</code>, we already know that <code>mid</code> is too large.</p>

<h3>Important: Avoid Overflow</h3>

<p>When calculating:</p>

<pre>
power *= mid;
</pre>

<p>the value can become very large. Since we only care whether the power is less than, equal to, or greater than <code>m</code>, we can stop as soon as it exceeds <code>m</code>.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log m)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer</p>

<p><strong>Key Idea:</strong> Binary search for an integer <code>x</code> such that <code>x^n = m</code>. If <code>x^n &lt; m</code>, search right; if <code>x^n &gt; m</code>, search left; return <code>-1</code> if no exact integer root exists.</p>
