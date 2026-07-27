<h2>502. IPO</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given <code>n</code> projects, where the <code>i<sup>th</sup></code> project has a required minimum capital <code>capital[i]</code> and yields a profit <code>profits[i]</code>.</p>

<p>Initially, you have <code>w</code> capital.</p>

<p>You may complete <strong>at most</strong> <code>k</code> distinct projects.</p>

<p>After completing a project, its profit is added to your current capital.</p>

<p>Return the <strong>maximum capital</strong> you can accumulate after completing at most <code>k</code> projects.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
k = 2
w = 0
profits = [1,2,3]
capital = [0,1,1]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

Initially, capital = 0.

Choose project 0:
Required capital = 0
Profit = 1

Capital becomes 1.

Now projects 1 and 2 are available.

Choose project 2:
Required capital = 1
Profit = 3

Final capital = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
k = 3
w = 0
profits = [1,2,3]
capital = [0,1,2]

<strong>Output:</strong>
6

<strong>Explanation:</strong>

Choose projects in the order:

Project 0 → Capital = 1
Project 1 → Capital = 3
Project 2 → Capital = 6

All three projects can be completed.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ k ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ w ≤ 10<sup>9</sup></code></li>
  <li><code>n == profits.length == capital.length</code></li>
  <li><code>1 ≤ n ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ profits[i] ≤ 10<sup>4</sup></code></li>
  <li><code>0 ≤ capital[i] ≤ 10<sup>9</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this efficiently by sorting projects according to their required capital, then using a <strong>Max Heap</strong> to repeatedly choose the most profitable project among all currently affordable ones, achieving <code>O(n log n + k log n)</code> time complexity?</p>
