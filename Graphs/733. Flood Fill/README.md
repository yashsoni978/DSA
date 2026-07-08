<h2>733. Flood Fill</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>You are given an image represented by an <code>m x n</code> integer grid <code>image</code>, where <code>image[i][j]</code> represents the pixel value of the image.</p>

<p>You are also given three integers <code>sr</code>, <code>sc</code>, and <code>color</code>. Your task is to perform a <strong>flood fill</strong> starting from the pixel <code>(sr, sc)</code>.</p>

<p>To perform a flood fill:</p>

<ul>
  <li>Begin with the starting pixel and change its color to <code>color</code>.</li>
  <li>Perform the same process for all neighboring pixels that have the <strong>same original color</strong>.</li>
  <li>Neighbors are pixels that share a side (up, down, left, or right).</li>
  <li>Continue the process until no more connected pixels of the original color remain.</li>
</ul>

<p>Return the modified image after performing the flood fill.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

<strong>Output:</strong>
[[2,2,2],[2,2,0],[2,0,1]]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

<strong>Output:</strong>
[[0,0,0],[0,0,0]]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == image.length</code></li>
  <li><code>n == image[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 50</code></li>
  <li><code>0 &lt;= image[i][j], color &lt; 2<sup>16</sup></code></li>
  <li><code>0 &lt;= sr &lt; m</code></li>
  <li><code>0 &lt;= sc &lt; n</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using either <strong>DFS</strong> or <strong>BFS</strong> traversal?</p>
