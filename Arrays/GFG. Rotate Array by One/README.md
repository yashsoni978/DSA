<h2>Rotate Array by One</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-blue" alt="Difficulty: Basic"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given an array <code>arr[]</code>, rotate the array by one position in
<b>clockwise direction</b>.
</p>

<p>
In a clockwise rotation, the <b>last element</b> moves to the first position
and all remaining elements are shifted one position to the right.
</p>

<h3>Example</h3>

<pre>
Input:  [1, 2, 3, 4, 5]

Output: [5, 1, 2, 3, 4]
</pre>

<h3>Approach</h3>

<ol>
<li>Store the last element of the array.</li>
<li>Shift all elements one position to the right.</li>
<li>Place the stored last element at the first position.</li>
</ol>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
// N = size of the array
</pre>

<h3>Key Point</h3>

<p>
For a clockwise rotation by one position, save the <b>last element</b> and
shift the remaining elements from <b>right to left</b>.
</p>
