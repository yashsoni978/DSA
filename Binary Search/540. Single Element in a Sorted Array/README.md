<h2>540. Single Element in a Sorted Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a sorted array <code>nums</code> where every element appears exactly twice except for one element that appears only once, find the single element.</p>

<p>The solution must run in <strong>O(log n)</strong> time and use <strong>O(1)</strong> space.</p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,1,2,3,3,4,4,8,8]

Output: 2

Explanation:
Every element appears twice except 2.
</pre>

<h3>Example 2</h3>

<pre>
Input: nums = [3,3,7,7,10,11,11]

Output: 10

Explanation:
Every element appears twice except 10.
</pre>

<h3>Key Observation</h3>

<p>Before the single element, pairs start at <strong>even indices</strong>:</p>

<pre>
Index:  0  1  2  3  4  5  6  7
        1  1  2  2  3  3  4  4
        ↑     ↑     ↑     ↑
      pairs start at even indices
</pre>

<p>After the single element, this pattern breaks:</p>

<pre>
Index:  0  1  2  3  4  5  6
        1  1  2  3  3  4  4
              ↑
           single
</pre>

<p>Before <code>2</code>:</p>

<pre>
(0,1) → 1,1
(2,3) → 2,3   ← pattern breaks here
</pre>

<p>After the single element, pairs start at <strong>odd indices</strong>.</p>

<h3>Approach</h3>

<ul>
<li>Use Binary Search.</li>
<li>Maintain <code>low = 0</code> and <code>high = n - 1</code>.</li>
<li>Calculate <code>mid</code>.</li>
<li>Make <code>mid</code> even so that we can compare it with its next element.</li>
<li>If <code>nums[mid] == nums[mid + 1]</code>, the pair is valid and the single element must be to the <strong>right</strong>.</li>
<li>Otherwise, the single element is at <code>mid</code> or somewhere to the <strong>left</strong>.</li>
<li>Continue until <code>low == high</code>.</li>
<li>Return <code>nums[low]</code>.</li>
</ul>

<h3>Why Make <code>mid</code> Even?</h3>

<p>We want to check pairs in this form:</p>

<pre>
nums[mid] and nums[mid + 1]
</pre>

<p>Before the single element, valid pairs are:</p>

<pre>
(0,1)
(2,3)
(4,5)
...
</pre>

<p>Therefore, we force <code>mid</code> to be even:</p>

<pre>
if (mid % 2 == 1)
    mid--;
</pre>

<p>Now <code>mid</code> always represents the first index of a potential pair.</p>

<h3>Binary Search Logic</h3>

<pre>
if (nums[mid] == nums[mid + 1])
{
    // Pair is correct.
    // Single element is on the right.
    low = mid + 2;
}
else
{
    // Pair is broken.
    // Single element is at mid or on the left.
    high = mid;
}
</pre>

<h3>Full Dry Run</h3>

<pre>
nums = [1,1,2,3,3,4,4,8,8]

Index:
         0 1 2 3 4 5 6 7 8
nums =  [1,1,2,3,3,4,4,8,8]
</pre>

<p>Initial:</p>

<pre>
low = 0
high = 8

mid = 4
</pre>

<p><code>mid = 4</code> is already even.</p>

<pre>
nums[4] = 3
nums[5] = 4

3 != 4
</pre>

<p>The pair is broken, so the single element is at <code>mid</code> or to its left.</p>

<pre>
high = mid
high = 4
</pre>

<p>Next:</p>

<pre>
low = 0
high = 4

mid = 2
