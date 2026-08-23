<h2>1283. Find the Smallest Divisor Given a Threshold</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code> and an integer <code>threshold</code>, find the <strong>smallest positive divisor</strong> such that the sum of all the divided values is less than or equal to <code>threshold</code>.</p>

<p>Each division result is rounded <strong>up</strong> to the nearest integer.</p>

<pre>
7 / 3 = 3
10 / 2 = 5
</pre>

<p>The goal is to find the smallest possible divisor. </p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,2,5,9], threshold = 6

Output: 5
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [44,22,33,11,1], threshold = 5

Output: 44
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible divisor is <code>1</code>.</li>
<li>The maximum useful divisor is <code>max(nums)</code>.</li>
<li>For a candidate divisor <code>d</code>, calculate the sum of <code>ceil(nums[i] / d)</code>.</li>
<li>If the sum is less than or equal to <code>threshold</code>, the divisor is valid.</li>
<li>Since we need the <strong>smallest</strong> valid divisor, search for a smaller divisor.</li>
<li>If the sum is greater than <code>threshold</code>, the divisor is too small, so search for a larger divisor.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>As the divisor increases, the value of each division decreases or stays the same.</p>

<pre>
Divisor increases
       ↓
Division sum decreases
</pre>

<p>Therefore, the possible answers have a monotonic pattern:</p>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
             Smallest valid divisor
</pre>

<p>Once a divisor produces a sum less than or equal to <code>threshold</code>, every larger divisor will also be valid. This allows us to use <strong>Binary Search on Answer</strong>. </p>

<h3>Calculating the Division Sum</h3>

<p>For each number <code>x</code> and divisor <code>d</code>:</p>

<pre>
ceil(x / d)
</pre>

<p>Using integer arithmetic:</p>

<pre>
(x + d - 1) / d
</pre>

<p>We add these values for every element in <code>nums</code> and compare the total with <code>threshold</code>.</p>

<h3>Binary Search Logic</h3>

<pre>
if (sum &lt;= threshold):
    high = mid - 1
else:
    low = mid + 1
</pre>

<p>If <code>mid</code> is valid, move left because we want a smaller divisor.</p>

<p>If <code>mid</code> is invalid, move right because we need a larger divisor to reduce the sum.</p>

<h3>Why Does <code>low</code> Become the Answer?</h3>

<p>At the end of binary search, all divisors smaller than <code>low</code> are invalid, while <code>low</code> is the first valid divisor.</p>

<pre>
Invalid divisors | Valid divisors
-----------------|--------------------&gt;
                 ↑
                low

          Answer = low
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log M)</code></p>

<p>where <code>n</code> is the number of elements and <code>M = max(nums)</code>.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Monotonic Search</p>

<p><strong>Key Idea:</strong> Binary search for the smallest divisor. For every candidate divisor, calculate the sum of <code>ceil(nums[i] / divisor)</code>. If the sum is within the threshold, search left; otherwise, search right.</p>
