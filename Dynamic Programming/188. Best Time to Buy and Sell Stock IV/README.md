<h2>188. Best Time to Buy and Sell Stock IV</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given an integer <code>k</code> and an array <code>prices</code>, where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the <strong>maximum profit</strong> you can achieve by completing <strong>at most <code>k</code> transactions</strong>.</p>

<p><strong>Note:</strong></p>

<ul>
  <li>You may not engage in multiple transactions simultaneously.</li>
  <li>You must sell the stock before buying again.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
k = 2
prices = [2,4,1]

<strong>Output:</strong>
2

<strong>Explanation:</strong>

Buy on day 1 at price = 2.
Sell on day 2 at price = 4.

Profit = 2

Only one transaction is needed.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
k = 2
prices = [3,2,6,5,0,3]

<strong>Output:</strong>
7

<strong>Explanation:</strong>

Buy on day 2 at price = 2.
Sell on day 3 at price = 6.
Profit = 4

Buy on day 5 at price = 0.
Sell on day 6 at price = 3.
Profit = 3

Total Profit = 7
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ k ≤ 100</code></li>
  <li><code>0 ≤ prices.length ≤ 1000</code></li>
  <li><code>0 ≤ prices[i] ≤ 1000</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with the states <code>(index, buy, transactionsLeft)</code> in <code>O(n × 2 × k)</code> time and optimize the space complexity to <code>O(2 × k)</code> using rolling arrays?</p>
