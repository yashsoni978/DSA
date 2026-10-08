<h2>189. Rotate Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given an integer array <code>nums</code>, rotate the array to the right by
<code>k</code> steps, where <code>k</code> is non-negative.
</p>

<p>
The rotation should be performed <b>in-place</b> with <b>O(1)</b> extra space.
</p>

<h3>Example</h3>

<pre>
Input:  nums = [1,2,3,4,5,6,7], k = 3

Output: [5,6,7,1,2,3,4]
</pre>

<h3>Approach</h3>

<p>
We use the <b>Reversal Algorithm</b>.
</p>

<ol>
<li>First, calculate <code>k = k % n</code> because rotating <code>n</code> times gives the original array.</li>
<li>Reverse the entire array.</li>
<li>Reverse the first <code>k</code> elements.</li>
<li>Reverse the remaining <code>n-k</code> elements.</li>
</ol>

<h3>Example Dry Run</h3>

<pre>
nums = [1,2,3,4,5,6,7]
k = 3

Reverse entire array:
[7,6,5,4,3,2,1]

Reverse first 3:
[5,6,7,4,3,2,1]

Reverse remaining:
[5,6,7,1,2,3,4]
</pre>

<h3>Why k % n?</h3>

<p>
If <code>k</code> is greater than the array size, the rotations repeat.
Therefore, we only need <code>k % n</code> rotations.
</p>

<pre>
For n = 7 and k = 10:

k = 10 % 7
k = 3
</pre>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
// N = size of nums
</pre>

<h3>Key Point</h3>

<p>
The reversal algorithm rotates the array to the right in <b>O(N)</b> time
and <b>O(1)</b> extra space, making it an optimal in-place approach.
</p>
