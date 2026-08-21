<h2>1. Two Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given an array of integers <code>nums</code> and an integer <code>target</code>, return the indices of the two numbers such that they add up to <code>target</code>.</p>

<p>You may assume that each input has exactly one solution, and you may not use the same element twice.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [2,7,11,15], target = 9

Output: [0,1]

Explanation: nums[0] + nums[1] = 2 + 7 = 9.
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [3,2,4], target = 6

Output: [1,2]
</pre>

<h3>Example 3</h3>

<pre>
Input: nums = [3,3], target = 6

Output: [0,1]
</pre>

<h3>Approach</h3>

<ul>
<li>Use a <strong>Hash Map</strong> to store each number and its index.</li>
<li>For every element <code>nums[i]</code>, calculate the required complement using <code>target - nums[i]</code>.</li>
<li>Check whether the complement already exists in the Hash Map.</li>
<li>If it exists, return the stored index of the complement and the current index.</li>
<li>Otherwise, store the current number and its index in the Hash Map.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(n)</code></p>

<hr>

<p><strong>Pattern:</strong> Array / Hash Map</p>

<p><strong>Key Idea:</strong> For every number, look for its required complement in a Hash Map so that the pair can be found in one pass.</p>
