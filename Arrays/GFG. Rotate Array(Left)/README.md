<h2>Rotate Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given an array <code>arr[]</code>, rotate the array to the left
(counter-clockwise direction) by <code>d</code> steps.
The rotation must be performed <b>in-place</b>.
</p>

<p>
The array is considered circular, so if <code>d</code> is greater than the
array size, the rotations repeat.
</p>

<h3>Example</h3>

<pre>
Input:  arr[] = [1, 2, 3, 4, 5], d = 2

Output: [3, 4, 5, 1, 2]
</pre>

<pre>
Input:  arr[] = [7, 3, 9, 1], d = 9

Output: [3, 9, 1, 7]
</pre>

<h3>Approach</h3>

<p>
We can use the <b>Reversal Algorithm</b> to rotate the array in-place.
</p>

<ol>
<li>First, reduce <code>d</code> using <code>d = d % n</code>.</li>
<li>Reverse the first <code>d</code> elements.</li>
<li>Reverse the remaining <code>n - d</code> elements.</li>
<li>Reverse the entire array.</li>
</ol>

<p>
For example:
</p>

<pre>
[1, 2, 3, 4, 5], d = 2

Reverse first 2:
[2, 1, 3, 4, 5]

Reverse remaining:
[2, 1, 5, 4, 3]

Reverse entire array:
[3, 4, 5, 1, 2]
</pre>

<h3>Why do we use d % n?</h3>

<p>
After every <code>n</code> rotations, the array returns to its original
position. Therefore, only <code>d % n</code> rotations are actually needed.
</p>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
// N = size of the array
</pre>

<h3>Key Point</h3>

<p>
The <b>reversal algorithm</b> allows us to rotate the array in-place using
constant extra space.
</p>
