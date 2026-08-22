<h2>153. Find Minimum in Rotated Sorted Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>nums</code> that was originally sorted in ascending order and then rotated between <code>1</code> and <code>n</code> times, find the <strong>minimum element</strong> in the array.</p>

<p>All elements in the array are <strong>unique</strong>.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [3,4,5,1,2]

Output: 1

Explanation:
The original sorted array was [1,2,3,4,5].
After rotation, it became [3,4,5,1,2].
The minimum element is 1.
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [4,5,6,7,0,1,2]

Output: 0
</pre>

<h3>Example 3</h3>

<pre>
Input: nums = [11,13,15,17]

Output: 11

Explanation:
The array was not effectively rotated, so the first element
is the minimum.
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search</strong> because the array is a rotated sorted array.</li>
<li>Maintain <code>low = 0</code> and <code>high = n - 1</code>.</li>
<li>Calculate <code>mid</code>.</li>
<li>Compare <code>nums[mid]</code> with <code>nums[high]</code>.</li>
<li>If <code>nums[mid] &gt; nums[high]</code>, the minimum must be on the <strong>right side</strong> of <code>mid</code>.</li>
<li>Otherwise, the minimum is at <code>mid</code> or somewhere on its <strong>left side</strong>.</li>
<li>Continue until <code>low == high</code>.</li>
<li>The element at <code>low</code> is the minimum.</li>
</ul>

<h3>Key Condition</h3>

<pre>
if (nums[mid] > nums[high])
    low = mid + 1;
else
    high = mid;
</pre>

<h3>Why Compare With <code>nums[high]</code>?</h3>

<p>Consider:</p>

<pre>
nums = [4,5,6,7,0,1,2]

              mid
               ↓
[4,5,6,7,0,1,2]
          ↑       ↑
        nums[mid] nums[high]
           7          2
</pre>

<p>Since:</p>

<pre>
nums[mid] > nums[high]
7 > 2
</pre>

<p>the minimum cannot be on the left side of <code>mid</code>. The rotation point must be to the right.</p>

<pre>
low = mid + 1
</pre>

<p>Now consider:</p>

<pre>
[5,6,7,0,1,2,4]
       ↑       ↑
     nums[mid] nums[high]
        0          4
</pre>

<p>Since:</p>

<pre>
nums[mid] < nums[high]
0 < 4
</pre>

<p>the right portion is sorted, so the minimum is at <code>mid</code> or somewhere to its left.</p>

<pre>
high = mid
</pre>

<h3>Full Dry Run</h3>

<pre>
nums = [4,5,6,7,0,1,2]

low = 0
high = 6

mid = 3
nums[mid] = 7
nums[high] = 2

7 > 2
→ minimum is on the right

low = 4
</pre>

<pre>
low = 4
high = 6

mid = 5
nums[mid] = 1
nums[high] = 2

1 < 2
→ minimum is at mid or on the left

high = 5
</pre>

<pre>
low = 4
high = 5

mid = 4
nums[mid] = 0
nums[high] = 1

0 < 1
→ minimum is at mid or on the left

high = 4
</pre>

<p>Now:</p>

<pre>
low = 4
high = 4

nums[4] = 0
</pre>

<p>Therefore:</p>

<pre>
Output = 0
</pre>

<h3>Why Do We Use <code>high = mid</code> Instead of <code>high = mid - 1</code>?</h3>

<p>Because <code>mid</code> itself can be the minimum.</p>

<p>For example:</p>

<pre>
nums = [3,4,5,1,2]

mid = 3
nums[mid] = 1
</pre>

<p>Here <code>1</code> is the minimum, so we cannot discard <code>mid</code>.</p>

<pre>
high = mid;
</pre>

<p>On the other hand, when:</p>

<pre>
nums[mid] > nums[high]
</pre>

<p>we know <code>mid</code> cannot be the minimum, so we can safely discard it:</p>

<pre>
low = mid + 1;
</pre>

<h3>Already Sorted Array</h3>

<p>Consider:</p>

<pre>
nums = [1,2,3,4,5]
</pre>

<p>There is no rotation point. The same logic still works because:</p>

<pre>
nums[mid] < nums[high]
</pre>

<p>Therefore, we keep moving <code>high</code> toward the minimum, eventually reaching index <code>0</code>.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Rotated Sorted Array</p>

<p><strong>Key Idea:</strong> Compare <code>nums[mid]</code> with <code>nums[high]</code>. If <code>nums[mid] &gt; nums[high]</code>, the minimum is to the right; otherwise, <code>mid</code> can still be the minimum, so search the left half including <code>mid</code>.</p>
