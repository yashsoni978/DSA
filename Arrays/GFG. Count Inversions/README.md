<h2>Count Inversions</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array of integers <code>arr[]</code>, find the <strong>Inversion Count</strong> of the array.</p>

<p>An inversion is a pair of indices <code>(i, j)</code> such that:</p>

<pre>
i &lt; j
and
arr[i] &gt; arr[j]
</pre>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong>
arr = [2, 4, 1, 3, 5]

<strong>Output:</strong>
3

<strong>Explanation:</strong>
The inversions are:

(2, 1)
(4, 1)
(4, 3)

Therefore, the inversion count is 3. </pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong>
arr = [2, 3, 4, 5, 6]

<strong>Output:</strong>
0

<strong>Explanation:</strong>
The array is already sorted, so there are no inversions. </pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong>
arr = [10, 10, 10]

<strong>Output:</strong>
0

<strong>Explanation:</strong>
Equal elements do not form an inversion because the condition is <code>arr[i] > arr[j]</code>. </pre>

<p><strong>Approach:</strong></p>

<p>Use <strong>Merge Sort</strong> to count inversions efficiently.</p>

<p>During the merge step, both the left and right halves are already sorted. If an element from the right half is smaller than an element from the left half, then it forms an inversion with <strong>all remaining elements in the left half</strong>.</p>

<p>Suppose:</p>

<pre>
Left  = [2, 4]
Right = [1, 3]
</pre>

<p>When comparing <code>2</code> and <code>1</code>, since:</p>

<pre>
2 &gt; 1
</pre>

<p><code>1</code> forms inversions with <code>2</code> and <code>4</code>. Therefore, we add the number of remaining elements in the left half to the answer.</p>

<pre>
Number of inversions = mid - i + 1
</pre>

<p>After counting the inversions, merge both halves into a sorted array.</p>

<p><strong>Key Observation:</strong></p>

<p>During merging, if <code>arr[i] &gt; arr[j]</code>, then every element from <code>i</code> to <code>mid</code> is also greater than <code>arr[j]</code>, because the left half is sorted.</p>

<p>Therefore, instead of checking every pair individually, we can count multiple inversions at once.</p>

<p><strong>Important:</strong></p>

<p>Use <code>long long</code> for the inversion count because the number of inversions can be as large as <code>n × (n - 1) / 2</code>.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
