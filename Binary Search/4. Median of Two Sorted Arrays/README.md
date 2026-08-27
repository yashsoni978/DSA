<h2>4. Median of Two Sorted Arrays</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given two sorted arrays <code>nums1</code> and <code>nums2</code>, find the <strong>median</strong> of the combined sorted array.</p>

<p>The required time complexity is <strong>O(log(m + n))</strong>. :contentReference[oaicite:0]{index=0}</p>

<h3>Example 1</h3>

<pre>
Input: nums1 = [1,3], nums2 = [2]

Output: 2.00000
</pre>

<h3>Example 2</h3>

<pre>
Input: nums1 = [1,2], nums2 = [3,4]

Output: 2.50000
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on the smaller array</strong>.</li>
<li>Partition both arrays such that the left half contains half of all elements.</li>
<li>Let <code>cut1</code> be the partition in <code>nums1</code>.</li>
<li>Calculate <code>cut2</code> so that the total number of elements on the left is correct.</li>
<li>For a valid partition, every element on the left must be less than or equal to every element on the right.</li>
<li>Check the boundary values around both partitions.</li>
<li>If <code>left1 &gt; right2</code>, move the partition in <code>nums1</code> left.</li>
<li>If <code>left2 &gt; right1</code>, move the partition in <code>nums1</code> right.</li>
<li>When the partition is valid, calculate the median from the boundary elements.</li>
</ul>

<h3>Partition Concept</h3>

<pre>
nums1: [ ........ left1 | right1 ........ ]
nums2: [ ........ left2 | right2 ........ ]

             LEFT | RIGHT
</pre>

<p>The correct partition satisfies:</p>

<pre>
left1 &lt;= right2
left2 &lt;= right1
</pre>

<p>This means every element in the left half is less than or equal to every element in the right half.</p>

<h3>Finding the Median</h3>

<p>If the total number of elements is odd:</p>

<pre>
median = max(left1, left2)
</pre>

<p>If the total number of elements is even:</p>

<pre>
median = (max(left1, left2) + min(right1, right2)) / 2
</pre>

<h3>Why Binary Search Works</h3>

<p>We only need to find the correct partition position. Since the arrays are sorted, moving the partition left or right tells us exactly how to correct an invalid partition.</p>

<pre>
left1 &gt; right2
      ↓
Move partition left

left2 &gt; right1
      ↓
Move partition right
</pre>

<p>Binary search reduces the search space by half at every step.</p>

<h3>Important Concept</h3>

<p>We are <strong>not merging the two arrays</strong>.</p>

<p>Instead, we find a partition where:</p>

<pre>
Number of elements on LEFT
        =
Number of elements needed for the median
</pre>

<p>Then the median can be determined using only the four boundary values around the partition.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log(min(m, n)))</code></p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Partitioning / Two Sorted Arrays</p>

<p><strong>Key Idea:</strong> Binary search the partition of the smaller array and determine the corresponding partition in the larger array. Find a partition where all left-side elements are smaller than or equal to all right-side elements, then calculate the median using the boundary values.</p>
