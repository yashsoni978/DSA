<h2>31. Next Permutation</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Implement <code>nextPermutation</code>, which rearranges the numbers into the lexicographically next greater permutation of numbers.</p>

<p>If such an arrangement is not possible, rearrange it into the lowest possible order (sorted in ascending order).</p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,2,3]

Output: [1,3,2]
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [3,2,1]

Output: [1,2,3]
</pre>

<h3>Example 3</h3>

<pre>
Input: nums = [1,1,5]

Output: [1,5,1]
</pre>

<h3>Approach</h3>

<ul>
<li>Find the first index <code>i</code> from the right where <code>nums[i] &lt; nums[i + 1]</code>.</li>
<li>If such an index exists, find the smallest number greater than <code>nums[i]</code> from the right and swap them.</li>
<li>Reverse the subarray after index <code>i</code> to make it the smallest possible suffix.</li>
<li>If no such index exists, the array is in descending order, so reverse the entire array.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Array / Greedy</p>

<p><strong>Key Idea:</strong> Find the first decreasing element from the right, swap it with the next larger element, then reverse the suffix.</p>
