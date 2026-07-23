<h2>1547. Minimum Cost to Cut a Stick</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given a wooden stick of length <code>n</code> and an array <code>cuts</code> where <code>cuts[i]</code> denotes a position at which you need to perform a cut, return the <strong>minimum total cost</strong> of cutting the stick.</p>

<p>You may perform the cuts in <strong>any order</strong>.</p>

<p>The cost of making a cut is equal to the <strong>current length of the stick</strong> being cut. After each cut, the stick is divided into two smaller sticks, which can be cut independently.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 7
cuts = [1,3,4,5]

<strong>Output:</strong>
16

<strong>Explanation:</strong>

One optimal order is:

Cut at 3 (cost = 7)
Stick becomes [0,3] and [3,7]

Cut at 5 (cost = 4)
Cut at 1 (cost = 3)
Cut at 4 (cost = 2)

Total cost = 7 + 4 + 3 + 2 = 16.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 9
cuts = [5,6,1,4,2]

<strong>Output:</strong>
22

<strong>Explanation:</strong>

Choosing the cuts in an optimal
order minimizes the total cost
to 22.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ n ≤ 10<sup>6</sup></code></li>
  <li><code>1 ≤ cuts.length ≤ min(n - 1, 100)</code></li>
  <li><code>1 ≤ cuts[i] ≤ n - 1</code></li>
  <li>All values in <code>cuts</code> are distinct.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Interval Dynamic Programming</strong> by first sorting the cut positions, adding boundary cuts at <code>0</code> and <code>n</code>, and defining <code>dp[i][j]</code> as the minimum cost to perform all cuts between the <code>i<sup>th</sup></code> and <code>j<sup>th</sup></code> cut positions, achieving <code>O(m³)</code> time and <code>O(m²)</code> space, where <code>m = cuts.length + 2</code>?</p>
