<h2>69. Sqrt(x)</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given a non-negative integer <code>x</code>, return the square root of <code>x</code> rounded down to the nearest integer.</p>

<p>The returned integer should be the <strong>floor value</strong> of the square root.</p>

<p>You are not allowed to use built-in exponentiation functions such as <code>pow(x, 0.5)</code> or <code>x ** 0.5</code>.</p>

<h3>Example 1</h3>

<pre>
Input: x = 4

Output: 2

Explanation:
sqrt(4) = 2
</pre>

<h3>Example 2</h3>

<pre>
Input: x = 8

Output: 2

Explanation:
sqrt(8) = 2.828...
After rounding down, the answer is 2.
</pre>

<h3>Example 3</h3>

<pre>
Input: x = 0

Output: 0
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search</strong> on the possible answer.</li>
<li>The square root of <code>x</code> must lie between <code>0</code> and <code>x</code>.</li>
<li>Maintain <code>low = 0</code> and <code>high = x</code>.</li>
<li>Calculate <code>mid = low + (high - low) / 2</code>.</li>
<li>If <code>mid * mid == x</code>, then <code>mid</code> is the exact square root.</li>
<li>If <code>mid * mid &lt; x</code>, <code>mid</code> can be a possible answer, but a larger value might also work. Move right.</li>
<li>If <code>mid * mid &gt; x</code>, <code>mid</code> is too large, so move left.</li>
<li>Keep track of the largest value whose square is less than or equal to <code>x</code>.</li>
</ul>

<h3>Important Idea</h3>

<pre>
We need the largest number mid such that:

mid * mid <= x
</pre>

<p>This is essentially a <strong>Binary Search for the answer</strong>.</p>

<h3>Binary Search Logic</h3>

<pre>
if (mid * mid <= x) {
    ans = mid;
    low = mid + 1;
}
else {
    high = mid - 1;
}
</pre>

<p>Whenever <code>mid * mid &lt;= x</code>, <code>mid</code> is a valid candidate.</p>

<p>But because we need the <strong>largest</strong> valid candidate, we continue searching to the right.</p>

<h3>Full Dry Run</h3>

<pre>
x = 8

low = 0
high = 8
ans = 0
</pre>

<p><strong>Iteration 1:</strong></p>

<pre>
mid = 4

4 * 4 = 16

16 > 8

4 is too large.

high = 3
</pre>

<p><strong>Iteration 2:</strong></p>

<pre>
low = 0
high = 3

mid = 1

1 * 1 = 1

1 <= 8

1 is a valid answer.

ans = 1
low = 2
</pre>

<p><strong>Iteration 3:</strong></p>

<pre>
low = 2
high = 3

mid = 2

2 * 2 = 4

4 <= 8

2 is a valid answer.

ans = 2
low = 3
</pre>

<p><strong>Iteration 4:</strong></p>

<pre>
low = 3
high = 3

mid = 3

3 * 3 = 9

9 > 8

3 is too large.

high = 2
</pre>

<p>Now:</p>

<pre>
low = 3
high = 2

Search ends.

ans = 2
</pre>

<p>Therefore:</p>

<pre>
Output = 2
</pre>

<h3>Why Do We Search Right When <code>mid * mid &lt;= x</code>?</h3>

<p>Suppose:</p>

<pre>
x = 20
mid = 4

4 * 4 = 16 <= 20
</pre>

<p>So <code>4</code> is valid.</p>

<p>But:</p>

<pre>
5 * 5 = 25 > 20
</pre>

<p>Therefore, the answer is <code>4</code>.</p>

<p>We cannot stop immediately after finding <code>4</code> because there might be a larger valid value.</p>

<p>So:</p>

<pre>
ans = mid
low = mid + 1
</pre>

<h3>Overflow Consideration</h3>

<p>For larger values of <code>x</code>, calculating:</p>

<pre>
mid * mid
</pre>

<p>using an <code>int</code> can overflow.</p>

<p>Therefore, use <code>long long</code> for the multiplication:</p>

<pre>
1LL * mid * mid
</pre>

<p>or perform the comparison as:</p>

<pre>
mid <= x / mid
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log x)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer</p>

<p><strong>Key Idea:</strong> Find the largest integer <code>mid</code> satisfying <code>mid² &lt;= x</code>. When <code>mid² &lt;= x</code>, store <code>mid</code> and search right for a potentially larger answer; otherwise search left.</p>
