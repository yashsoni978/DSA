<h2>120. Triangle</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>triangle</strong> array, return the <strong>minimum path sum</strong> from top to bottom.</p>

<p>For each step, you may move to <strong>either of the two adjacent numbers</strong> in the row directly below.</p>

<p>More formally, if you are on index <code>i</code> in the current row, you may move to either index <code>i</code> or <code>i + 1</code> in the next row.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
triangle =
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

<strong>Output:</strong>
11

<strong>Explanation:</strong>

The minimum path is:

2 → 3 → 5 → 1

Total sum = 11.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
triangle =
[
  [-10]
]

<strong>Output:</strong>
-10
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ triangle.length ≤ 200</code></li>
  <li><code>triangle[0].length == 1</code></li>
  <li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
  <li><code>-10<sup>4</sup> ≤ triangle[i][j] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with <code>O(n²)</code> time and optimize the extra space complexity to <code>O(n)</code>?</p>
