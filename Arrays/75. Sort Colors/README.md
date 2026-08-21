<h2>75. Sort Colors</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p>We use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the colors red, white, and blue, respectively.</p>

<p>You must solve this problem without using the library's sort function.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [2,0,2,1,1,0]

Output: [0,0,1,1,2,2]
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [2,0,1]

Output: [0,1,2]
</pre>

<h3>Approach</h3>

<ul>
<li>Use the <strong>Dutch National Flag</strong> algorithm with three pointers: <code>low</code>, <code>mid</code>, and <code>high</code>.</li>
<li><code>low</code> represents the position where the next <code>0</code> should be placed.</li>
<li><code>mid</code> is the current element being examined.</li>
<li><code>high</code> represents the position where the next <code>2</code> should be placed.</li>
<li>If <code>nums[mid] == 0</code>, swap <code>nums[low]</code> and <code>nums[mid]</code>, then increment both <code>low</code> and <code>mid</code>.</li>
<li>If <code>nums[mid] == 1</code>, it is already in the correct region, so simply increment <code>mid</code>.</li>
<li>If <code>nums[mid] == 2</code>, swap <code>nums[mid]</code> and <code>nums[high]</code>, then decrement <code>high</code>. Do not increment <code>mid</code> because the swapped element still needs to be examined.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Array / Two Pointers / Dutch National Flag</p>

<p><strong>Key Idea:</strong> Maintain three regions for <code>0</code>, <code>1</code>, and <code>2</code> using <code>low</code>, <code>mid</code>, and <code>high</code>, allowing the array to be sorted in one pass.</p>
