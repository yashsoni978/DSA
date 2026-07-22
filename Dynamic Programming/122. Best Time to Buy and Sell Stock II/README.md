<h2>122. Best Time to Buy and Sell Stock II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an integer array <code>prices</code>, where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>You may complete <strong>as many transactions as you like</strong> (i.e., buy one and sell one share of the stock multiple times).</p>

<p><strong>Note:</strong></p>

<ul>
  <li>You may not hold more than one share of the stock at a time.</li>
  <li>You must sell the stock before buying again.</li>
</ul>

<p>Return the <strong>maximum profit</strong> you can achieve.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
prices = [7,1,5,3,6,4]

<strong>Output:</strong>
7

<strong>Explanation:</strong>

Buy on day 2 at price = 1.
Sell on day 3 at price = 5.
Profit = 4

Buy on day 4 at price = 3.
Sell on day 5 at price = 6.
Profit = 3

Total Profit = 7
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

Buying and selling every day
also results in the same profit.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
prices = [7,6,4,3,1]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The stock price continuously decreases.

No profitable transaction
can be made.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ prices.length ≤ 3 × 10<sup>4</sup></code></li>
  <li><code>0 ≤ prices[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with two states (<code>buy</code> and <code>sell</code>) in <code>O(n)</code> time and <code>O(1)</code> space, and also derive the equivalent greedy solution?</p>
