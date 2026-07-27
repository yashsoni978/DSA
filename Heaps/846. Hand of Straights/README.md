<h2>846. Hand of Straights</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Alice has a hand of cards represented by an integer array <code>hand</code>, where each card has a value written on it, and an integer <code>groupSize</code>.</p>

<p>Return <code>true</code> if the cards can be rearranged into groups such that:</p>

<ul>
  <li>Each group contains exactly <code>groupSize</code> cards.</li>
  <li>Each group consists of <strong>consecutive</strong> card values.</li>
</ul>

<p>Otherwise, return <code>false</code>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
hand = [1,2,3,6,2,3,4,7,8]
groupSize = 3

<strong>Output:</strong>
true

<strong>Explanation:</strong>

The cards can be rearranged into:

[1,2,3]
[2,3,4]
[6,7,8]

Each group contains 3 consecutive cards.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
hand = [1,2,3,4,5]
groupSize = 4

<strong>Output:</strong>
false

<strong>Explanation:</strong>

The hand contains 5 cards,
which cannot be divided into groups
of exactly 4 cards.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ hand.length ≤ 10<sup>4</sup></code></li>
  <li><code>0 ≤ hand[i] ≤ 10<sup>9</sup></code></li>
  <li><code>1 ≤ groupSize ≤ hand.length</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this efficiently using a <strong>Hash Map</strong> to count frequencies and a <strong>Min Heap</strong> or an ordered map to always start forming groups from the smallest available card, achieving <code>O(n log n)</code> time complexity?</p>
