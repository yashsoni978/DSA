<h2>322. Coin Change</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>amount</code> representing the total amount of money.</p>

<p>Return the <strong>fewest number of coins</strong> needed to make up the given <code>amount</code>. If it is impossible to make up that amount using the given coins, return <code>-1</code>.</p>

<p>You may use <strong>an unlimited number of each type of coin</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
coins = [1,2,5]
amount = 11

<strong>Output:</strong>
3

<strong>Explanation:</strong>

11 = 5 + 5 + 1

Minimum coins required = 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
coins = [2]
amount = 3

<strong>Output:</strong>
-1

<strong>Explanation:</strong>

It is impossible to form an amount of 3
using only coins of denomination 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
coins = [1]
amount = 0

<strong>Output:</strong>
0

<strong>Explanation:</strong>

No coins are needed to make an amount of 0.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ coins.length ≤ 12</code></li>
  <li><code>1 ≤ coins[i] ≤ 2<sup>31</sup> - 1</code></li>
  <li><code>0 ≤ amount ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(coins.length × amount)</code> time while optimizing the space complexity to <code>O(amount)</code>?</p>
