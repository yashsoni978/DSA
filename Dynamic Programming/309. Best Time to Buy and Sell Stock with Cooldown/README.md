<h2>309. Best Time to Buy and Sell Stock with Cooldown</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an array <code>prices</code>, where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>Find the <strong>maximum profit</strong> you can achieve. You may complete as many transactions as you like, subject to the following restrictions:</p>

<ul>
  <li>You may not engage in multiple transactions simultaneously (you must sell before buying again).</li>
  <li>After you sell your stock, you <strong>cannot buy stock on the next day</strong> (i.e., there is a one-day cooldown).</li>
</ul>

<p>Return the maximum profit.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
prices = [1,2,3,0,2]

<strong>Output:</strong>
3

<strong>Explanation:</strong>

Buy on day 1 at price = 1.
Sell on day 3 at price = 3.
Profit = 2

Cooldown on day 4.

Buy on day 5 at price = 2 is not possible,
so instead:

Buy on day 4 at price = 0.
Sell on day 5 at price = 2.
Profit = 2

The optimal sequence gives a total profit of 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
prices = [1]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

Only one day is available.

No transaction can be completed,
so the maximum profit is 0.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ prices.length ≤ 5000</code></li>
  <li><code>0 ≤ prices[i] ≤ 1000</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with the states <code>(index, buy)</code>, where after selling you transition to <code>index + 2</code> to account for the cooldown, achieving <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
