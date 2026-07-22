<h2>123. Best Time to Buy and Sell Stock III</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given an array <code>prices</code>, where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the <strong>maximum profit</strong> you can achieve by completing <strong>at most two transactions</strong>.</p>

<p><strong>Note:</strong></p>

<ul>
  <li>You may not engage in multiple transactions simultaneously.</li>
  <li>You must sell the stock before buying again.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
prices = [3,3,5,0,0,3,1,4]

<strong>Output:</strong>
6

<strong>Explanation:</strong>

Buy on day 4 at price = 0.
Sell on day 6 at price = 3.
Profit = 3

Buy on day 7 at price = 1.
Sell on day 8 at price = 4.
Profit = 3

Total Profit = 6
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
prices = [1,2,3,4,5]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

Buy on day 1 at price = 1.
Sell on day 5 at price = 5.

Profit = 4

Using only one transaction
already gives the maximum profit.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
prices = [7,6,4,3,1]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The stock prices keep decreasing.

No profitable transaction
can be made.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ prices.length ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ prices[i] ≤ 10<sup>5</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with the states <code>(index, buy, transactionsLeft)</code> in <code>O(n × 2 × 2)</code> time and optimize the space complexity to <code>O(2 × 2)</code>?</p>
