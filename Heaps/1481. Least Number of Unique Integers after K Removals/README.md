<h2>1481. Least Number of Unique Integers after K Removals</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>arr</code> and an integer <code>k</code>, remove exactly <code>k</code> elements from the array.</p>

<p>Return the <strong>least number of unique integers</strong> remaining after the removals.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr = [5,5,4]
k = 1

<strong>Output:</strong>
1

<strong>Explanation:</strong>

Remove the element 4.

The remaining array is:

[5,5]

Only one unique integer remains.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr = [4,3,1,1,3,3,2]
k = 3

<strong>Output:</strong>
2

<strong>Explanation:</strong>

Frequencies are:

1 → 2
2 → 1
3 → 3
4 → 1

Remove 2 and 4 (2 removals),
then remove one occurrence of 1.

The remaining array is:

[1,3,3,3]

Only the integers 1 and 3 remain.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.length ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>9</sup></code></li>
  <li><code>0 ≤ k ≤ arr.length</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this efficiently by counting element frequencies with a <strong>Hash Map</strong>, storing the frequencies in a <strong>Min Heap</strong> (or sorting them), and greedily removing the least frequent elements first, achieving <code>O(n log n)</code> time?</p>
