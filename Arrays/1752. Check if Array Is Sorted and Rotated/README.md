<h2>1752. Check if Array Is Sorted and Rotated</h2>
<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given an array <b>nums</b>, return <b>true</b> if the array was originally
sorted in non-decreasing order and then rotated some number of positions.
Otherwise, return <b>false</b>.
</p>

<p>
A sorted array can be rotated by moving some elements from the beginning
to the end.
</p>

<h3>Example 1</h3>

<pre>
Input: nums = [3,4,5,1,2]
Output: true
</pre>

<p>
The original sorted array is <b>[1,2,3,4,5]</b>. Rotating it gives
<b>[3,4,5,1,2]</b>.
</p>

<h3>Example 2</h3>

<pre>
Input: nums = [2,1,3,4]
Output: false
</pre>

<p>
The array cannot be obtained by rotating a sorted array.
</p>

<h3>Example 3</h3>

<pre>
Input: nums = [1,2,3]
Output: true
</pre>

<p>
The array is already sorted, so it is considered sorted and rotated by
zero positions.
</p>

<h3>Approach</h3>

<p>
For a sorted and rotated array, there can be at most <b>one position</b>
where the current element is greater than the next element.
</p>

<p>
We check every adjacent pair, including the last element with the first
element using circular comparison.
</p>

<ul>
    <li>If <b>nums[i] &gt; nums[(i+1) % n]</b>, count a violation.</li>
    <li>If the number of violations is more than <b>1</b>, return <b>false</b>.</li>
    <li>Otherwise, return <b>true</b>.</li>
</ul>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
</pre>

<h3>Key Point</h3>

<p>
A sorted and rotated array has at most <b>one decreasing point</b>.
The modulo expression <b>(i + 1) % n</b> allows us to compare the last
element with the first element as well.
</p>
