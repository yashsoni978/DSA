<h2>1423. Maximum Points You Can Obtain from Cards</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are cards arranged in a row. You can take exactly <code>k</code> cards from either the beginning or the end. Return the maximum score you can obtain.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
cardPoints = [1,2,3,4,5,6,1]
k = 3

<strong>Output:</strong>
12
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Try every possible combination of taking cards from the left and right.</p>

<p>This can take <code>O(k)</code> combinations, but repeatedly calculating the sums can be inefficient.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique.</p>

<p>If we take exactly <code>k</code> cards, then <code>n-k</code> consecutive cards will be left in the middle.</p>

<p>To maximize our score, find the minimum sum of a window of size <code>n-k</code>.</p>

<pre>
Answer = Total Sum - Minimum Window Sum
</pre>

<p><strong>Key Observation:</strong></p>

<p>Instead of maximizing the cards taken from the ends, minimize the cards left in the middle.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
