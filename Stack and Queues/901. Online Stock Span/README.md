<h2>901. Online Stock Span</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Design a stock span calculator. For each day's price, return the number of consecutive days up to today for which the stock price was <strong>less than or equal to today's price</strong>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
[100, 80, 60, 70, 60, 75, 85]

<strong>Output:</strong>
[1, 1, 1, 2, 1, 4, 6] </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use a <strong>Monotonic Decreasing Stack</strong> storing <code>{price, span}</code>.</p>

<ul>
<li>While the stack top has <code>price &lt;= currentPrice</code>, pop it.</li>
<li>Add its stored <code>span</code> to the current span.</li>
<li>Push <code>{currentPrice, span}</code>.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>Instead of checking every previous day, the stored <strong>span</strong> lets us skip multiple smaller/equal prices at once.</p>

<pre>
current span = 1 + spans of all popped prices
</pre>

<p><strong>Time Complexity:</strong> <code>O(n)</code> amortized</p>
<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
