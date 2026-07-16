<h2>509. Fibonacci Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>The <strong>Fibonacci numbers</strong>, commonly denoted <code>F(n)</code>, form a sequence such that each number is the sum of the two preceding ones, starting from <code>0</code> and <code>1</code>.</p>

<p>The Fibonacci sequence is defined as:</p>

<ul>
  <li><code>F(0) = 0</code></li>
  <li><code>F(1) = 1</code></li>
  <li><code>F(n) = F(n - 1) + F(n - 2)</code>, for <code>n &gt; 1</code>.</li>
</ul>

<p>Given an integer <code>n</code>, return the value of <code>F(n)</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 2

<strong>Output:</strong>
1

<strong>Explanation:</strong>
F(2) = F(1) + F(0) = 1 + 0 = 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 3

<strong>Output:</strong>
2

<strong>Explanation:</strong>
F(3) = F(2) + F(1) = 1 + 1 = 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
n = 4

<strong>Output:</strong>
3

<strong>Explanation:</strong>
F(4) = F(3) + F(2) = 2 + 1 = 3.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ n ≤ 30</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with <code>O(n)</code> time and optimize the space complexity to <code>O(1)</code>?</p>
