<h2>81. Search in Rotated Sorted Array II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>nums</code> that was originally sorted in ascending order but has been rotated at an unknown index, determine whether a given <code>target</code> exists in the array.</p>

<p>The array may contain <strong>duplicate elements</strong>.</p>

<p>Return <code>true</code> if <code>target</code> exists in <code>nums</code>, otherwise return <code>false</code>.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [2,5,6,0,0,1,2], target = 0

Output: true
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [2,5,6,0,0,1,2], target = 3

Output: false
</pre>

<h3>Example 3</h3>

<pre>
Input: nums = [1,0,1,1,1], target = 0

Output: true
</pre>

<h3>Approach</h3>

<ul>
<li>Use a modified <strong>Binary Search</strong>.</li>
<li>At every step, calculate <code>mid</code>.</li>
<li>If <code>nums[mid] == target</code>, return <code>true</code>.</li>
<li>Normally, at least one half of the rotated array is sorted.</li>
<li>If the left half is sorted, check whether the target lies inside that range.</li>
<li>If the left half is not sorted, the right half must be sorted.</li>
<li>However, duplicates can make it impossible to determine which half is sorted.</li>
<li>If <code>nums[low] == nums[mid] == nums[high]</code>, shrink both boundaries using <code>low++</code> and <code>high--</code>.</li>
<li>Continue until the target is found or the search range becomes empty.</li>
</ul>

<h3>Why Do We Handle Duplicates Separately?</h3>

<p>Consider:</p>

<pre>
nums = [1,1,1,1,2,1,1]
             ↑
            mid
</pre>

<p>Here:</p>

<pre>
nums[low] == nums[mid] == nums[high]
     1           1          1
</pre>

<p>We cannot determine which half is sorted because the duplicate values hide the rotation point.</p>

<p>Therefore, safely remove the duplicate boundary elements:</p>

<pre>
low++;
high--;
</pre>

<p>This does not lose the target because all three boundary values are equal.</p>

<h3>Case 1: Left Half Is Sorted</h3>

<pre>
if (nums[low] <= nums[mid])
</pre>

<p>Now check whether the target lies inside the sorted left half:</p>

<pre>
nums[low] <= target && target < nums[mid]
</pre>

<p>If true, search left:</p>

<pre>
high = mid - 1;
</pre>

<p>Otherwise, search right:</p>

<pre>
low = mid + 1;
</pre>

<h3>Case 2: Right Half Is Sorted</h3>

<p>If the left half is not sorted, the right half must be sorted.</p>

<p>Check whether the target lies inside the sorted right half:</p>

<pre>
nums[mid] < target && target <= nums[high]
</pre>

<p>If true, search right:</p>

<pre>
low = mid + 1;
</pre>

<p>Otherwise, search left:</p>

<pre>
high = mid - 1;
</pre>

<h3>Important Difference from Problem 33</h3>

<pre>
Problem 33:
Search in Rotated Sorted Array

→ All elements are unique.

Problem 81:
Search in Rotated Sorted Array II

→ Duplicate elements are allowed.
</pre>

<p>Because duplicates are allowed, we need the additional condition:</p>

<pre>
if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
    low++;
    high--;
}
</pre>

<h3>Example</h3>

<pre>
Input:
nums = [2,5,6,0,0,1,2]
target = 0

low = 0
high = 6
mid = 3

nums[mid] = 0

nums[mid] == target

Therefore:

Output = true
</pre>

<h3>Complexity</h3>

<p><strong>Average Time:</strong> <code>O(log n)</code></p>
<p><strong>Worst-case Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<p>The worst case can become <code>O(n)</code> because duplicates may force us to repeatedly shrink both boundaries by one.</p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Modified Binary Search / Rotated Sorted Array / Duplicates</p>

<p><strong>Key Idea:</strong> Identify the sorted half and eliminate the other half. When <code>nums[low] == nums[mid] == nums[high]</code>, duplicates make the sorted half ambiguous, so shrink both boundaries.</p>
