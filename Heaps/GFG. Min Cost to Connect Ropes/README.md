<h2>Min Cost to Connect Ropes</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>arr[]</code> representing the lengths of ropes, connect all the ropes into a single rope with the <strong>minimum total cost</strong>.</p>

<p>The cost of connecting any two ropes is equal to the <strong>sum of their lengths</strong>.</p>

<p>Return the minimum total cost required to connect all the ropes.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr = [4,3,2,6]

<strong>Output:</strong>
29

<strong>Explanation:</strong>

Connect 2 and 3 → Cost = 5
Remaining ropes: [4,5,6]

Connect 4 and 5 → Cost = 9
Remaining ropes: [6,9]

Connect 6 and 9 → Cost = 15

Total cost = 5 + 9 + 15 = 29

Any other order results in a higher total cost.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr = [4,2,7,6,9]

<strong>Output:</strong>
62

<strong>Explanation:</strong>

Connect 4 and 2 → Cost = 6
Remaining ropes: [6,6,7,9]

Connect 6 and 6 → Cost = 12
Remaining ropes: [7,9,12]

Connect 7 and 9 → Cost = 16
Remaining ropes: [12,16]

Connect 12 and 16 → Cost = 28

Total cost = 6 + 12 + 16 + 28 = 62
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr = [10]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

Only one rope exists,
so no connections are needed.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this optimally using a <strong>Min Heap (Priority Queue)</strong> by repeatedly connecting the two shortest ropes first, achieving <code>O(n log n)</code> time complexity?</p>
