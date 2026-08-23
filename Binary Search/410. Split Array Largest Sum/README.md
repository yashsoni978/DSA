<h2>410. Split Array Largest Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, split the array into <strong>k non-empty contiguous subarrays</strong> such that the <strong>largest sum</strong> among all subarrays is minimized. </p>

<h3>Example 1</h3>

<pre>
Input: nums = [7,2,5,10,8], k = 2

Output: 18
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [1,2,3,4,5], k = 2

Output: 9
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible answer is <code>max(nums)</code>, because every element must belong to some subarray.</li>
<li>The maximum possible answer is <code>sum(nums)</code>, when the entire array is one subarray.</li>
<li>For a candidate maximum sum, greedily split the array from left to right.</li>
<li>Keep adding elements to the current subarray while the sum does not exceed the candidate limit.</li>
<li>If adding an element exceeds the limit, start a new subarray.</li>
<li>Count how many subarrays are required.</li>
<li>If at most <code>k</code> subarrays are required, the candidate is valid, so search for a smaller answer.</li>
<li>If more than <code>k</code> subarrays are required, the candidate is too small, so search for a larger answer.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The problem has a <strong>monotonic property</strong>.</p>

<pre>
Maximum allowed sum increases
            ↓
More elements can fit in each subarray
            ↓
Fewer subarrays are required
</pre>

<p>Therefore, the possible answers follow this pattern:</p>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
             Minimum valid sum
</pre>

<p>Once a maximum sum is sufficient, every larger maximum sum is also sufficient. This allows us to use <strong>Binary Search on Answer</strong>. </p>

<h3>Checking a Candidate Sum</h3>

<p>For a given maximum allowed sum:</p>

<ul>
<li>Start with one subarray.</li>
<li>Add elements to the current subarray while the sum stays within the limit.</li>
<li>If adding the next element exceeds the limit, start a new subarray.</li>
<li>Continue until all elements are processed.</li>
<li>If the number of required subarrays is at most <code>k</code>, the candidate is valid.</li>
</ul>

<p>This greedy approach works because using the current subarray as much as possible minimizes the number of subarrays required for a fixed maximum sum. </p>

<h3>Binary Search Logic</h3>

<pre>
if (requiredSubarrays &lt;= k):
    high = mid - 1
else:
    low = mid + 1
</pre>

<p>If the candidate works, search left because we want to minimize the largest sum.</p>

<p>If the candidate does not work, search right because we need a larger maximum sum.</p>

<h3>Why Does <code>low</code> Become the Answer?</h3>

<p>At the end of the binary search:</p>

<pre>
low &gt; high
</pre>

<p><code>low</code> points to the first valid maximum sum.</p>

<pre>
Invalid sums | Valid sums
-------------|--------------------&gt;
             ↑
            low

       Answer = low
</pre>

<h3>Important Concept</h3>

<p>We are not binary searching through the array.</p>

<p>We are searching over the <strong>answer space</strong>:</p>

<pre>
max(nums) ---------------- sum(nums)
    ↑                         ↑
Minimum                    Maximum
possible                   possible
answer                      answer
</pre>

<p>For every candidate value, we ask:</p>

<pre>
"Can I split the array into at most k
contiguous subarrays where every
subarray has sum <= this value?"
</pre>

<p>The answer is either <strong>YES</strong> or <strong>NO</strong>, creating the monotonic property required for binary search. </p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log S)</code></p>

<p>where <code>n</code> is the size of the array and <code>S = sum(nums)</code>.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Greedy / Monotonic Search</p>

<p><strong>Key Idea:</strong> Binary search for the minimum possible largest subarray sum. For every candidate limit, greedily create contiguous subarrays and count how many are required. If at most <code>k</code> subarrays are needed, search left; otherwise, search right.</p>
