<h2>33. Search in Rotated Sorted Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>nums</code> that was originally sorted in ascending order but has been rotated at an unknown index, search for a given <code>target</code>.</p>

<p>Return the index of <code>target</code> if it exists in the array. Otherwise, return <code>-1</code>.</p>

<p>All elements in the array are <strong>unique</strong>.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [4,5,6,7,0,1,2], target = 0

Output: 4
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [4,5,6,7,0,1,2], target = 3

Output: -1
</pre>

<h3>Example 3</h3>

<pre>
Input: nums = [1], target = 0

Output: -1
</pre>

<h3>Approach</h3>

<ul>
<li>Use a modified version of <strong>Binary Search</strong>.</li>
<li>At every step, calculate <code>mid</code>.</li>
<li>If <code>nums[mid] == target</code>, return <code>mid</code>.</li>
<li>Even though the entire array is rotated, <strong>at least one half of the current search range is always sorted</strong>.</li>
<li>Check whether the left half is sorted using <code>nums[low] &lt;= nums[mid]</code>.</li>
<li>If the left half is sorted, check whether the target lies inside that sorted range.</li>
<li>If the target lies in the left sorted half, search left; otherwise search right.</li>
<li>If the left half is not sorted, the right half must be sorted.</li>
<li>Check whether the target lies inside the sorted right half.</li>
<li>If it does, search right; otherwise search left.</li>
</ul>

<h3>Important Idea</h3>

<pre>
At every iteration:

        [ left half ] [ right half ]
              ↓              ↓
        One of them MUST be sorted
</pre>

<p>For example:</p>

<pre>
nums = [4,5,6,7,0,1,2]

             mid
              ↓
[4,5,6,7] [0,1,2]
    sorted    sorted
</pre>

<p>We identify which half is sorted and then determine whether the target can exist inside that half.</p>

<h3>Case 1: Left Half Is Sorted</h3>

<pre>
if (nums[low] <= nums[mid])
</pre>

<p>The left portion from <code>low</code> to <code>mid</code> is sorted.</p>

<p>Now check:</p>

<pre>
nums[low] <= target && target < nums[mid]
</pre>

<p>If true, the target lies inside the sorted left half, so:</p>

<pre>
high = mid - 1
</pre>

<p>Otherwise:</p>

<pre>
low = mid + 1
</pre>

<h3>Case 2: Right Half Is Sorted</h3>

<p>If the left half is not sorted, the right half must be sorted.</p>

<pre>
else
</pre>

<p>Check whether the target lies inside the sorted right half:</p>

<pre>
nums[mid] < target && target <= nums[high]
</pre>

<p>If true:</p>

<pre>
low = mid + 1
</pre>

<p>Otherwise:</p>

<pre>
high = mid - 1
</pre>

<h3>Example</h3>

<pre>
nums = [4,5,6,7,0,1,2]
target = 0

low = 0
high = 6
mid = 3

nums[mid] = 7

Left half:
[4,5,6,7]

This half is sorted.

Is 0 between 4 and 7?
No.

Therefore search the right half.

low = 4
</pre>

<p>Now:</p>

<pre>
[0,1,2]

mid = 5

nums[mid] = 1

Target = 0

Left half is sorted:
[0,1]

0 lies in this range.

Search left.

high = 4
</pre>

<p>Now:</p>

<pre>
low = 4
high = 4
mid = 4

nums[4] = 0

Target found!

Answer = 4
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Modified Binary Search / Rotated Sorted Array</p>

<p><strong>Key Idea:</strong> At every step, one half of the rotated array is guaranteed to be sorted. Identify the sorted half, check whether the target lies inside it, and eliminate the other half.</p>
