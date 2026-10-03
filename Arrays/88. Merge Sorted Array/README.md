<h2>88. Merge Sorted Array</h2>
<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>
<hr>

<p>Given two sorted integer arrays <code>nums1</code> and <code>nums2</code>, merge <code>nums2</code> into <code>nums1</code> so that <code>nums1</code> becomes a single sorted array.</p>

<p>The first array has enough extra space at the end to hold all elements of the second array.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

<strong>Output:</strong>
[1,2,2,3,5,6] </pre>

<p><strong>Approach:</strong></p>

<p>Use the <strong>two-pointer technique</strong> and merge the arrays from the <strong>back</strong>.</p>

<p>Maintain three pointers:</p>

<ul>
<li><code>i = m - 1</code> → last valid element of <code>nums1</code>.</li>
<li><code>j = n - 1</code> → last element of <code>nums2</code>.</li>
<li><code>k = m + n - 1</code> → last position of <code>nums1</code>.</li>
</ul>

<p>Compare <code>nums1[i]</code> and <code>nums2[j]</code>. Place the larger element at <code>nums1[k]</code> and move the corresponding pointer.</p>

<p>Continue until all elements of <code>nums2</code> have been placed.</p>

<p><strong>Key Observation:</strong></p>

<p>We merge from the end because <code>nums1</code> already contains its valid elements at the beginning and has empty positions at the end. Starting from the back prevents overwriting elements that have not yet been processed.</p>

<p><strong>Time Complexity:</strong> <code>O(m + n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
