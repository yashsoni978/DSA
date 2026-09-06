<h2>860. Lemonade Change</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>At a lemonade stand, each lemonade costs <code>$5</code>. Customers pay using <code>$5</code>, <code>$10</code>, or <code>$20</code> bills.</p>

<p>Return <code>true</code> if you can provide the correct change to every customer in order, otherwise return <code>false</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
bills = [5,5,5,10,20]

<strong>Output:</strong>
true
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Try different combinations of available bills to provide change for each customer.</p>

<p>This is unnecessary because a greedy strategy is sufficient.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use a <strong>Greedy</strong> approach and keep track of the number of <code>$5</code> and <code>$10</code> bills.</p>

<ol>
  <li>For a <code>$5</code> bill, simply store it.</li>
  <li>For a <code>$10</code> bill, give one <code>$5</code> as change.</li>
  <li>For a <code>$20</code> bill, prefer giving <code>$10 + $5</code> as change.</li>
  <li>If that is not possible, give three <code>$5</code> bills.</li>
  <li>If the required change cannot be given, return <code>false</code>.</li>
</ol>

<p><strong>Key Observation:</strong></p>

<p>For a <code>$20</code> bill, always prefer <code>$10 + $5</code> over three <code>$5</code> bills because <code>$5</code> bills are more useful for future customers.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
