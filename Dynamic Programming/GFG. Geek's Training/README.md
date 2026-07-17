<h2>Geek's Training</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Geek is going for a training program for <code>n</code> days. Each day, he can perform <strong>one</strong> of the following three activities:</p>

<ul>
  <li>Running</li>
  <li>Fighting</li>
  <li>Learning Practice</li>
</ul>

<p>Each activity awards a certain number of merit points for that day, represented by the matrix <code>mat[][]</code>, where:</p>

<ul>
  <li><code>mat[i][0]</code> → Points for Running on the <code>i<sup>th</sup></code> day.</li>
  <li><code>mat[i][1]</code> → Points for Fighting on the <code>i<sup>th</sup></code> day.</li>
  <li><code>mat[i][2]</code> → Points for Learning Practice on the <code>i<sup>th</sup></code> day.</li>
</ul>

<p>Geek wants to improve all his skills, so he <strong>cannot perform the same activity on two consecutive days</strong>.</p>

<p>Return the <strong>maximum total merit points</strong> Geek can achieve after completing the training program.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
mat[][] = [
  [1, 2, 5],
  [3, 1, 1],
  [3, 3, 3]
]

<strong>Output:</strong>
11

<strong>Explanation:</strong>

Day 1 → Learning Practice = 5
Day 2 → Running = 3
Day 3 → Fighting = 3

Total Merit Points = 11
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
mat[][] = [
  [1, 1, 1],
  [2, 2, 2],
  [3, 3, 3]
]

<strong>Output:</strong>
6

<strong>Explanation:</strong>

Geek can choose any valid sequence of activities while
avoiding consecutive repetitions to obtain 6 points.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
mat[][] = [
  [4, 2, 6]
]

<strong>Output:</strong>
6

<strong>Explanation:</strong>

Geek performs Learning Practice on the only day
and earns 6 merit points.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ mat[i][j] ≤ 100</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(1)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by tracking the last activity performed and further optimize the solution from memoization to constant space?</p>
