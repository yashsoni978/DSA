<h2>18. 4Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an integer array <code>nums</code> and an integer <code>target</code>,
return all unique quadruplets
<code>[nums[a], nums[b], nums[c], nums[d]]</code> such that:
</p>

<pre>
a, b, c, d are distinct indices

nums[a] + nums[b] + nums[c] + nums[d] == target
</pre>

<p>
The solution must not contain duplicate quadruplets.
</p>

<h3>Example</h3>

<pre>
Input:
nums = [1,0,-1,0,-2,2]
target = 0

Output:
[
    [-2,-1,1,2],
    [-2,0,0,2],
    [-1,0,0,1]
]
</pre>

<h3>Approach</h3>

<p>
We use <b>Sorting + Two Pointers</b>, similar to the 3Sum problem.
</p>

<ol>
<li>Sort the array.</li>
<li>Fix the first element using index <code>i</code>.</li>
<li>Fix the second element using index <code>j</code>.</li>
<li>Use two pointers:
    <ul>
        <li><code>left = j + 1</code></li>
        <li><code>right = n - 1</code></li>
    </ul>
</li>
<li>Calculate the sum of the four elements.</li>
<li>If the sum equals <code>target</code>, store the quadruplet.</li>
<li>If the sum is smaller than <code>target</code>, move <code>left</code> forward.</li>
<li>If the sum is greater than <code>target</code>, move <code>right</code> backward.</li>
<li>Skip duplicate values for <code>i</code>, <code>j</code>, <code>left</code>, and <code>right</code>.</li>
</ol>

<h3>Why Sorting Helps</h3>

<p>
Sorting allows us to use the two-pointer technique efficiently.
</p>

<p>
If the current sum is too small, increasing <code>left</code> increases the sum.
If the current sum is too large, decreasing <code>right</code> decreases the sum.
</p>

<h3>Example</h3>

<pre>
Sorted array:
[-2,-1,0,0,1,2]

target = 0

Fix -2 and -1:

-2 + (-1) + 0 + 2 = -1
→ Sum is smaller, move left

-2 + (-1) + 0 + 2 = -1
→ Continue moving pointers

Eventually:

-2 + (-1) + 1 + 2 = 0
→ Found [-2,-1,1,2]
</pre>

<h3>Handling Duplicates</h3>

<p>
To avoid duplicate quadruplets, skip equal values when choosing
the first and second elements:
</p>

<pre>
if (i > 0 && nums[i] == nums[i - 1])
    continue;

if (j > i + 1 && nums[j] == nums[j - 1])
    continue;
</pre>

<p>
After finding a valid quadruplet, skip duplicate values from both
<code>left</code> and <code>right</code>.
</p>

<h3>Overflow Handling</h3>

<p>
The values can be large, so the sum should be calculated using
<code>long long</code> to prevent integer overflow.
</p>

<pre>
long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N³)
Space Complexity: O(1) excluding the output
</pre>

<p>
Sorting takes <code>O(N log N)</code>. We use two nested loops and
a two-pointer traversal, resulting in <code>O(N³)</code> time.
</p>
