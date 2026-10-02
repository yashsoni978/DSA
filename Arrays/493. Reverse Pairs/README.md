<h2>493. Reverse Pairs</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Given an integer array <code>nums</code>, return the number of <strong>reverse pairs</strong> in the array.</p>

<p>A reverse pair is a pair of indices <code>(i, j)</code> such that:</p>

<pre>
i &lt; j
and
nums[i] &gt; 2 × nums[j]
</pre>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong>
nums = [1,3,2,3,1]

<strong>Output:</strong>
2

<strong>Explanation:</strong>

(3, 1) → 3 > 2 × 1
(3, 1) → 3 > 2 × 1

Therefore, there are 2 reverse pairs. </pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong>
nums = [2,4,3,5,1]

<strong>Output:</strong>
3 </pre>

<p><strong>Approach:</strong></p>

<p>Use <strong>Merge Sort</strong> to efficiently count reverse pairs.</p>

<p>During merge sort, the array is divided into two sorted halves. Before merging them, count the reverse pairs where the first element belongs to the left half and the second element belongs to the right half.</p>

<p>Since both halves are already sorted, use a pointer <code>j</code> to find how many elements in the right half satisfy:</p>

<pre>
nums[i] &gt; 2 × nums[j]
</pre>

<p>For every element in the left half, move <code>j</code> forward while the condition is satisfied. All elements before <code>j</code> form valid reverse pairs with the current left element.</p>

<p>After counting the reverse pairs, merge the two sorted halves.</p>

<p><strong>Key Observation:</strong></p>

<p>Merge sort allows us to count cross-half reverse pairs in linear time at every level because both halves are already sorted.</p>

<p>Instead of checking every pair in <code>O(n²)</code>, we count them while performing merge sort.</p>

<p><strong>Important:</strong></p>

<p>Use <code>long long</code> while calculating <code>2 × nums[j]</code> to avoid integer overflow.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
