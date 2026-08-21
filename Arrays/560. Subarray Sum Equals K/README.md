<h2>560. Subarray Sum Equals K</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return the total number of subarrays whose sum equals <code>k</code>.</p>

<p>A subarray is a contiguous non-empty sequence of elements within an array.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,1,1], k = 2

Output: 2
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [1,2,3], k = 3

Output: 2

Explanation: The subarrays [1,2] and [3] have sum equal to 3.
</pre>

<h3>Approach</h3>

<ul>
<li>Use a <strong>Prefix Sum</strong> along with a <strong>Hash Map</strong>.</li>
<li>Maintain <code>prefixSum</code>, representing the sum of elements from the beginning of the array up to the current index.</li>
<li>Suppose the current prefix sum is <code>prefixSum</code>. We need to find an earlier prefix sum equal to <code>prefixSum - k</code>.</li>
<li>If <code>prefixSum - k</code> exists in the Hash Map, its frequency represents the number of subarrays ending at the current index whose sum is <code>k</code>.</li>
<li>Add that frequency to the answer.</li>
<li>Store the current <code>prefixSum</code> in the Hash Map for future subarrays.</li>
<li>Initialize the Hash Map with <code>mp[0] = 1</code> to handle subarrays whose sum is exactly <code>k</code> from the beginning of the array.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code> average</p>
<p><strong>Space:</strong> <code>O(n)</code></p>

<hr>

<p><strong>Pattern:</strong> Array / Prefix Sum / Hash Map</p>

<p><strong>Key Idea:</strong> If the current prefix sum is <code>prefixSum</code>, then an earlier prefix sum of <code>prefixSum - k</code> means the elements between those two positions form a subarray with sum <code>k</code>.</p>
