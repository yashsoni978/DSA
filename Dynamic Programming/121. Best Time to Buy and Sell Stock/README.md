<h2>121. Best Time to Buy and Sell Stock</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the <code>i<sup>th</sup></code> day.</p>

<p>You want to maximize your profit by choosing <strong>a single day to buy</strong> one stock and <strong>a different future day to sell</strong> that stock.</p>

<p>Return the <strong>maximum profit</strong> you can achieve from this transaction. If no profit can be made, return <code>0</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
prices = [7,1,5,3,6,4]

<strong>Output:</strong>
5

<strong>Explanation:</strong>

Buy on day 2 at price = 1.

Sell on day 5 at price = 6.

Profit = 6 − 1 = 5.

Buying after selling is not allowed.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
prices = [7,6,4,3,1]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The prices continuously decrease.

No profitable transaction is possible,
so the answer is 0.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ prices.length ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ prices[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem in <strong>O(n)</strong> time and <strong>O(1)</strong> extra space by tracking the minimum stock price seen so far and updating the maximum profit while traversing the array only once?</p>
