<h2>162. Find Peak Element</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code>, find a <strong>peak element</strong> and return its index.</p>

<p>A peak element is an element that is <strong>strictly greater than its neighbors</strong>.</p>

<p>You may assume that <code>nums[-1] = nums[n] = -∞</code>.</p>

<p>The solution must run in <strong>O(log n)</strong> time.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,2,3,1]

Output: 2

Explanation:
nums[2] = 3 is greater than both its neighbors 2 and 1.
Therefore, index 2 is a peak.
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [1,2,1,3,5,6,4]

Output: 5

Explanation:
nums[5] = 6 is greater than nums[4] = 5
and nums[6] = 4.

Therefore, index 5 is a peak.
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search</strong>.</li>
<li>Maintain <code>low = 0</code> and <code>high = n - 1</code>.</li>
<li>Calculate <code>mid</code>.</li>
<li>Compare <code>nums[mid]</code> with <code>nums[mid + 1]</code>.</li>
<li>If <code>nums[mid] &gt; nums[mid + 1]</code>, we are on a <strong>descending slope</strong>.</li>
<li>Therefore, a peak exists at <code>mid</code> or somewhere to its <strong>left</strong>.</li>
<li>Set <code>high = mid</code>.</li>
<li>If <code>nums[mid] &lt; nums[mid + 1]</code>, we are on an <strong>ascending slope</strong>.</li>
<li>Therefore, a peak must exist to the <strong>right</strong> of <code>mid</code>.</li>
<li>Set <code>low = mid + 1</code>.</li>
<li>When <code>low == high</code>, that index is guaranteed to be a peak.</li>
</ul>

<h3>Important Idea</h3>

<pre>
If nums[mid] < nums[mid + 1]:

        / 
       /
      / ↑
     mid

We are climbing upward.

A peak must exist on the RIGHT.

low = mid + 1
</pre>

<pre>
If nums[mid] > nums[mid + 1]:

      ↓
     \ 
      \ 
       \

We are going downward.

A peak exists at mid or on the LEFT.

high = mid
</pre>

<h3>Why Does an Ascending Slope Guarantee a Peak on the Right?</h3>

<p>Suppose:</p>

<pre>
nums = [1,2,3,4,5,6,4]
