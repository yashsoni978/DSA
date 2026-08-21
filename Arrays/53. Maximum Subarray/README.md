<h2>53. Maximum Subarray</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code>, find the subarray with the largest sum, and return its sum.</p>

<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

Output: 6

Explanation: The subarray [4,-1,2,1] has the largest sum 6.
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [1]

Output: 1
</pre>

<h3>Example 3</h3>

<pre>
Input: nums = [5,4,-1,7,8]

Output: 23

Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Kadane's Algorithm</strong> to find the maximum subarray sum in one pass.</li>
<li>Maintain <code>currentSum</code> as the maximum sum of a subarray ending at the current position.</li>
<li>For every element, decide whether to start a new subarray from the current element or extend the existing subarray.</li>
<li>Update <code>currentSum</code> using <code>max(nums[i], currentSum + nums[i])</code>.</li>
<li>Maintain <code>maxSum</code> to store the maximum subarray sum found so far.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Array / Dynamic Programming / Kadane's Algorithm</p>

<p><strong>Key Idea:</strong> At each element, decide whether to extend the current subarray or start a new one, while keeping track of the maximum sum found so far.</p>
