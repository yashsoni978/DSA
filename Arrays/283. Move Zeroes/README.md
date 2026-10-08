<h2>283. Move Zeroes</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given an integer array <code>nums</code>, move all <code>0</code>s to the end of the array while maintaining the relative order of the non-zero elements.
</p>

<p>
The operation must be performed <b>in-place</b>.
</p>

<h3>Example</h3>

<pre>
Input:  nums = [0,1,0,3,12]

Output: [1,3,12,0,0]
</pre>

<h3>Approach</h3>

<p>
Use a <b>two-pointer approach</b>.
</p>

<ul>
<li>Maintain a pointer <code>j</code> that represents the position where the next non-zero element should be placed.</li>
<li>Traverse the array using another pointer <code>i</code>.</li>
<li>Whenever <code>nums[i]</code> is non-zero, swap it with <code>nums[j]</code> and increment <code>j</code>.</li>
<li>All non-zero elements are placed at the beginning while zeros automatically move towards the end.</li>
</ul>

<h3>Example</h3>

<pre>
[0,1,0,3,12]

After processing:
[1,0,0,3,12]
[1,3,0,0,12]
[1,3,12,0,0]
</pre>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
// N = size of nums
</pre>

<h3>Key Point</h3>

<p>
The two-pointer technique allows us to move all non-zero elements forward while
preserving their relative order, using constant extra space.
</p>
