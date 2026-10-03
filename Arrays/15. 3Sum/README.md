<h2>15. 3Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an integer array <code>nums</code>, return all the triplets
<code>[nums[i], nums[j], nums[k]]</code> such that:
</p>

<pre>
i != j
i != k
j != k

nums[i] + nums[j] + nums[k] == 0
</pre>

<p>
The solution must not contain duplicate triplets.
</p>

<h3>Example</h3>

<pre>
Input:
nums = [-1,0,1,2,-1,-4]

Output:
[[-1,-1,2],[-1,0,1]]
</pre>

<h3>Approach</h3>

<p>
We use <b>Sorting + Two Pointers</b>.
</p>

<ol>
<li>Sort the array.</li>
<li>Fix one element using index <code>i</code>.</li>
<li>Use two pointers:
    <ul>
        <li><code>left = i + 1</code></li>
        <li><code>right = n - 1</code></li>
    </ul>
</li>
<li>Calculate the sum of the three elements.</li>
<li>If the sum is <code>0</code>, store the triplet.</li>
<li>If the sum is less than <code>0</code>, move <code>left</code> forward.</li>
<li>If the sum is greater than <code>0</code>, move <code>right</code> backward.</li>
<li>Skip duplicate values to avoid duplicate triplets.</li>
</ol>

<h3>Why Sorting Helps</h3>

<p>
After sorting, we can use the two-pointer technique.
If the current sum is too small, increasing <code>left</code> increases the sum.
If the current sum is too large, decreasing <code>right</code> decreases the sum.
</p>

<h3>Example</h3>

<pre>
Sorted array:
[-4,-1,-1,0,1,2]

Fix -1:

left = -1
right = 2

-1 + (-1) + 2 = 0
→ Found [-1,-1,2]

Move pointers and skip duplicates.

-1 + 0 + 1 = 0
→ Found [-1,0,1]
</pre>

<h3>Handling Duplicates</h3>

<p>
To avoid duplicate triplets:
</p>

<pre>
if (i > 0 && nums[i] == nums[i-1])
    continue;
</pre>

<p>
After finding a valid triplet, skip duplicate values from both sides.
</p>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N²)
Space Complexity: O(1) 
</pre>

<p>
The sorting takes <code>O(N log N)</code>, and the two-pointer search for
each fixed element takes <code>O(N)</code>, resulting in
<code>O(N²)</code> overall time.
</p>
