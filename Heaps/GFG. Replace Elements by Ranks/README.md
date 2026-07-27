<h2>Replace Elements by Ranks</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given an integer array <code>arr[]</code> of size <code>n</code>, convert it into its <strong>reduced form</strong>.</p>

<p>In the reduced form:</p>

<ul>
  <li>The smallest element is replaced with rank <code>0</code>.</li>
  <li>The second smallest element is replaced with rank <code>1</code>.</li>
  <li>Ranks continue in increasing order up to <code>n - 1</code>.</li>
</ul>

<p>The <strong>relative positions</strong> of elements in the array must remain unchanged.</p>

<p>For <strong>duplicate elements</strong>, the one appearing earlier in the original array must receive the smaller rank.</p>

<p>Modify the array <strong>in place</strong>. Do not return anything.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr = [10,40,20]

<strong>Output:</strong>
[0,2,1]

<strong>Explanation:</strong>

Sorted order:

10 → rank 0
20 → rank 1
40 → rank 2

Replacing each element by its rank gives:

[0,2,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr = [0,2,1]

<strong>Output:</strong>
[0,2,1]

<strong>Explanation:</strong>

The array is already in reduced form.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr = [1,5,3,4,3]

<strong>Output:</strong>
[0,4,1,3,2]

<strong>Explanation:</strong>

Ranks are assigned as:

1 → 0
first 3 → 1
second 3 → 2
4 → 3
5 → 4

So the reduced array becomes:

[0,4,1,3,2]
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>6</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this by sorting <strong>(value, original index)</strong> pairs, assigning ranks in sorted order (while handling duplicates by original position), and updating the original array in <code>O(n log n)</code> time?</p>
