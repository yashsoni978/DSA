<h2>Median in a Row-Wise Sorted Matrix</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a row-wise sorted matrix of size <code>n × m</code>, where both <code>n</code> and <code>m</code> are odd, find the <strong>median</strong> of all the elements.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible value is the smallest matrix element and the maximum possible value is the largest matrix element.</li>
<li>For every <code>mid</code>, count how many elements in the matrix are <strong>less than or equal to</strong> <code>mid</code>.</li>
<li>Since every row is sorted, use <strong>upper_bound</strong> in each row to count these elements efficiently.</li>
<li>If the count is less than or equal to <code>(n × m) / 2</code>, the median must be larger, so move <code>low</code> right.</li>
<li>Otherwise, the median can be <code>mid</code> or smaller, so move <code>high</code> left.</li>
<li>When the binary search ends, <code>low</code> is the median.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The matrix is sorted row-wise, so for any value <code>x</code>, we can efficiently determine how many elements are less than or equal to <code>x</code>.</p>

<pre>
count &lt;= x

count too small → median is larger
count sufficient → median is x or smaller
</pre>

<p>The median is the element having exactly half of the matrix elements on its left.</p>

<h3>Counting Elements</h3>

<p>For each row, use <code>upper_bound(row.begin(), row.end(), mid)</code>.</p>

<p>This gives the number of elements in that row that are less than or equal to <code>mid</code>.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n × log(m) × log(maxValue - minValue))</code></p>

<p>For every binary-search value, we perform an <code>upper_bound</code> on all <code>n</code> rows.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Upper Bound</p>

<p><strong>Key Idea:</strong> Binary search over the possible values and use <code>upper_bound</code> on every sorted row to count how many elements are less than or equal to the current value.</p>
