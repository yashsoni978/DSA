<h2>K-th Element of Two Sorted Arrays</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two sorted arrays <code>a</code> and <code>b</code>, find the element that would appear at the <strong>k-th position</strong> in their combined sorted array.</p>

<h3>Example 1</h3>

<pre>
Input: a = [2,3,6,7,9], b = [1,4,8,10], k = 5

Output: 6
</pre>

<h3>Example 2</h3>

<pre>
Input: a = [1,4,8,10,12], b = [5,7,11,15,17], k = 6

Output: 10
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on the smaller array</strong>.</li>
<li>Partition both arrays so that exactly <code>k</code> elements are present on the left side.</li>
<li>Let <code>cut1</code> be the number of elements selected from the first array.</li>
<li>Then <code>cut2 = k - cut1</code> elements are selected from the second array.</li>
<li>Check whether the partition is valid by comparing the boundary elements.</li>
<li>If <code>left1 &gt; right2</code>, move the partition in the first array left.</li>
<li>If <code>left2 &gt; right1</code>, move the partition in the first array right.</li>
<li>When the partition is valid, the k-th element is <code>max(left1, left2)</code>.</li>
</ul>

<h3>Partition Concept</h3>

<pre>
Array A: [ .... left1 | right1 .... ]
Array B: [ .... left2 | right2 .... ]

             k elements
        &lt;----------------&gt;
</pre>

<p>For a valid partition:</p>

<pre>
left1 &lt;= right2
left2 &lt;= right1
</pre>

<p>Once this condition is satisfied, the largest element on the left side is the <strong>k-th element</strong>.</p>

<h3>Why Binary Search Works</h3>

<p>Since both arrays are sorted, if the partition is invalid, we know which direction to move it.</p>

<pre>
left1 &gt; right2
      ↓
Move partition left

left2 &gt; right1
      ↓
Move partition right
</pre>

<p>This allows us to eliminate half of the possible partitions at every step.</p>

<h3>Important Concept</h3>

<p>We do <strong>not merge the two arrays</strong>.</p>

<p>Instead, we find a partition containing exactly <code>k</code> elements on the left and determine the largest element among those left-side elements.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log(min(n, m)))</code></p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Partitioning / Two Sorted Arrays</p>

<p><strong>Key Idea:</strong> Binary search the partition of the smaller array. Choose the corresponding partition in the other array so that exactly <code>k</code> elements are on the left. Once the partition is valid, <code>max(left1, left2)</code> is the k-th element.</p>
