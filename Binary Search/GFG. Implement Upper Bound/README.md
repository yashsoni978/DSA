<h2>Implement Upper Bound</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given a sorted array <code>arr[]</code> and a number <code>target</code>, find the <strong>upper bound</strong> of the target.</p>

<p>The upper bound is the <strong>smallest index</strong> where the element is <strong>strictly greater than</strong> the target.</p>

<p>If no element is greater than the target, return the length of the array.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [2,3,7,10,11,11,25], target = 9

Output: 3

Explanation:
arr[3] = 10, which is the first element greater than 9.
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [2,3,7,10,11,11,25], target = 11

Output: 6

Explanation:
arr[4] = 11 and arr[5] = 11 are not greater than 11.
arr[6] = 25 is the first element greater than 11.
</pre>

<h3>Example 3</h3>

<pre>
Input: arr = [2,3,7,10,11,11,25], target = 100

Output: 7

Explanation:
No element is greater than 100,
so we return the length of the array.
</pre>

<h3>Approach</h3>

<ul>
<li>Since the array is sorted, use <strong>Binary Search</strong>.</li>
<li>Maintain two pointers: <code>low = 0</code> and <code>high = n - 1</code>.</li>
<li>Initialize <code>ans = n</code>. This handles the case where no element is greater than the target.</li>
<li>Calculate the middle index using <code>mid = low + (high - low) / 2</code>.</li>
<li>If <code>arr[mid] &gt; target</code>, <code>mid</code> is a possible upper bound.</li>
<li>Store <code>mid</code> in <code>ans</code> and search further left for a smaller valid index.</li>
<li>If <code>arr[mid] &lt;= target</code>, this element cannot be the answer, so search to the right.</li>
<li>When the binary search finishes, <code>ans</code> contains the smallest index whose value is strictly greater than the target.</li>
</ul>

<h3>Important Idea</h3>

<pre>
If arr[mid] > target:
    Possible answer → go LEFT

If arr[mid] <= target:
    Not possible → go RIGHT
</pre>

<h3>Lower Bound vs Upper Bound</h3>

<pre>
Lower Bound:
First index where arr[i] >= target

Upper Bound:
First index where arr[i] > target
</pre>

<p>The only condition that changes is:</p>

<pre>
Lower Bound → arr[mid] >= target
Upper Bound → arr[mid] > target
</pre>

<h3>Why Do We Initialize <code>ans = n</code>?</h3>

<p>If every element is smaller than or equal to the target, there is no valid index.</p>

<p>The problem requires returning the length of the array in this case.</p>

<pre>
arr = [2,3,7,10]
target = 10

answer = 4
</pre>

<p>Therefore:</p>

<pre>
ans = n
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Upper Bound</p>

<p><strong>Key Idea:</strong> Whenever <code>arr[mid] &gt; target</code>, store <code>mid</code> as a possible answer and continue searching left because we need the <strong>smallest valid index</strong>.</p>
