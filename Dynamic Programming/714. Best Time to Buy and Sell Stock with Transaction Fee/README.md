<h2>714. Best Time to Buy and Sell Stock with Transaction Fee</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an array <code>prices</code>, where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day, and an integer <code>fee</code> representing a transaction fee.</p>

<p>Find the <strong>maximum profit</strong> you can achieve. You may complete as many transactions as you like, subject to the following restrictions:</p>

<ul>
  <li>You may not engage in multiple transactions simultaneously (you must sell before buying again).</li>
  <li>Each completed transaction incurs the given <code>fee</code>.</li>
</ul>

<p>Return the maximum profit.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
prices = [1,3,2,8,4,9]
fee = 2

<strong>Output:</strong>
8

<strong>Explanation:</strong>

Buy on day 1 at price = 1.
Sell on day 4 at price = 8.

Profit = 8 − 1 − 2 = 5

Buy on day 5 at price = 4.
Sell on day 6 at price = 9.

Profit = 9 − 4 − 2 = 3

Total Profit = 8
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
prices = [1,3,7,5,10,3]
fee = 3

<strong>Output:</strong>
6

<strong>Explanation:</strong>

Buy on day 1 at price = 1.
Sell on day 5 at price = 10.

Profit = 10 − 1 − 3 = 6

This yields the maximum possible profit.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ prices.length ≤ 5 × 10<sup>4</sup></code></li>
  <li><code>1 ≤ prices[i] &lt; 5 × 10<sup>4</sup></code></li>
  <li><code>0 ≤ fee &lt; 5 × 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with the states <code>(index, buy)</code> in <code>O(n)</code> time and <code>O(1)</code> extra space, by accounting for the transaction fee during each sell operation?</p>
