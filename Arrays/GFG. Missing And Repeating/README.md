<h2>Missing And Repeating</h2>
<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>
<hr>

<p>Given an unsorted array <code>arr[]</code> of size <code>n</code>, containing elements from <code>1</code> to <code>n</code>, one number is missing and another number occurs twice. Find the <strong>repeating</strong> and <strong>missing</strong> numbers.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong>
arr = [2, 2]

<strong>Output:</strong>
[2, 1]

<strong>Explanation:</strong>
2 occurs twice, so it is the repeating number.
1 is missing from the range [1, 2]. </pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong>
arr = [1, 3, 3]

<strong>Output:</strong>
[3, 2]

<strong>Explanation:</strong>
3 occurs twice, so it is the repeating number.
2 is missing. </pre>

<p><strong>Approach:</strong></p>

<p>Use the mathematical properties of <strong>sum</strong> and <strong>sum of squares</strong>.</p>

<p>Let:</p>

<pre>
x = repeating number
y = missing number
</pre>

<p>The expected sum of numbers from <code>1</code> to <code>n</code> is:</p>

<pre>
S = n × (n + 1) / 2
</pre>

<p>Let the actual sum of the array be <code>Sn</code>. Then:</p>

<pre>
Sn - S = x - y
</pre>

<p>Similarly, the expected sum of squares is:</p>

<pre>
Sq = n × (n + 1) × (2n + 1) / 6
</pre>

<p>Let the actual sum of squares be <code>Sqn</code>. Then:</p>

<pre>
Sqn - Sq = x² - y²
</pre>

<p>Using:</p>

<pre>
x² - y² = (x - y)(x + y)
</pre>

<p>we can calculate <code>x + y</code>. Once we know <code>x - y</code> and <code>x + y</code>, we can find both numbers.</p>

<p><strong>Key Observation:</strong></p>

<p>Using the difference of sums gives us <code>x - y</code>, while the difference of squared sums gives us <code>x² - y²</code>. Combining these two equations allows us to determine the repeating and missing numbers without using extra space.</p>

<p><strong>Important:</strong></p>

<p>Use <code>long long</code> for sums and squared sums because the values can become large.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
