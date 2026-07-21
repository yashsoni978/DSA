<h2>518. Coin Change II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an integer array <code>coins</code> representing coins of different denominations and an integer <code>amount</code> representing the total amount of money.</p>

<p>Return the <strong>number of combinations</strong> that make up the given <code>amount</code>.</p>

<p>You may use <strong>an unlimited number</strong> of each type of coin.</p>

<p><strong>Note:</strong> Two combinations are considered the same if they contain the same coins, regardless of their order.</p>

<p>If no combination can make up the amount, return <code>0</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
amount = 5
coins = [1,2,5]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

There are four possible combinations:

5
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
amount = 3
coins = [2]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

No combination of coin 2 can form
an amount of 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
amount = 10
coins = [10]

<strong>Output:</strong>
1

<strong>Explanation:</strong>

The only possible combination is:

10
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ coins.length ≤ 300</code></li>
  <li><code>1 ≤ coins[i] ≤ 5000</code></li>
  <li>All values in <code>coins</code> are unique.</li>
  <li><code>0 ≤ amount ≤ 5000</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(coins.length × amount)</code> time while optimizing the space complexity to <code>O(amount)</code> and ensuring combinations are counted without considering different orders?</p>
