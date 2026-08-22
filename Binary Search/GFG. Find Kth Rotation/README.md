<h2>Find Kth Rotation</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given an increasing sorted array <code>arr[]</code> of distinct integers that has been <strong>right-rotated</strong> <code>k</code> times, find the value of <code>k</code>.</p>

<p>The number of rotations is equal to the <strong>index of the minimum element</strong> in the rotated array.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [5,1,2,3,4]

Output: 1

Explanation:
Original sorted array:
[1,2,3,4,5]

After 1 right rotation:
[5,1,2,3,4]

The minimum element 1 is at index 1.

Therefore, k = 1.
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [1,2,3,4,5]

Output: 0

Explanation:
The array is already sorted and has not been rotated.

The minimum element 1 is at index 0.

Therefore, k = 0.
</pre>

<h3>Example 3</h3>

<pre>
Input: arr = [6,9,12,15,2,4]

Output: 4

Explanation:
The minimum element 2 is at index 4.

Therefore, the array was right-rotated 4 times.
</pre>

<h3>Key Observation</h3>

<p>For a sorted array:</p>

<pre>
[1,2,3,4,5]
