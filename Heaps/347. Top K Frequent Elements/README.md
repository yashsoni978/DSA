<h2>347. Top K Frequent Elements</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return the <strong>k</strong> most frequent elements.</p>

<p>You may return the answer in <strong>any order</strong>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,1,1,2,2,3]
k = 2

<strong>Output:</strong>
[1,2]

<strong>Explanation:</strong>

Frequency of each element:

1 → 3 times
2 → 2 times
3 → 1 time

The two most frequent elements are
1 and 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1]
k = 1

<strong>Output:</strong>
[1]

<strong>Explanation:</strong>

Only one element exists,
so it is the most frequent element.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 10<sup>5</sup></code></li>
  <li><code>-10<sup>4</sup> ≤ nums[i] ≤ 10<sup>4</sup></code></li>
  <li><code>k</code> is in the range <code>[1, number of unique elements]</code>.</li>
  <li>It is guaranteed that the answer is unique.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem in better than <code>O(n log n)</code> time by using a <strong>Hash Map</strong> with a <strong>Min Heap</strong> of size <code>k</code> or <strong>Bucket Sort</strong>, achieving <code>O(n log k)</code> or even <code>O(n)</code> time?</p>
