<h2>Minimum Multiplications to Reach End</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two integers <code>start</code> and <code>end</code>, along with an array of integers <code>arr[]</code>. In one operation, you can multiply the current value by any element from <code>arr[]</code>, and then take the result modulo <code>1000</code> to obtain a new value.</p>

<p>Find the <strong>minimum number of steps</strong> required to reach <code>end</code> starting from <code>start</code>. If it is not possible to reach <code>end</code>, return <code>-1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [2, 5, 7]
start = 3
end = 30

<strong>Output:</strong>
2

<strong>Explanation:</strong>

Step 1:
3 × 2 = 6 % 1000 = 6

Step 2:
6 × 5 = 30 % 1000 = 30
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [3, 4, 65]
start = 7
end = 175

<strong>Output:</strong>
4

<strong>Explanation:</strong>

Step 1:
7 × 3 = 21 % 1000 = 21

Step 2:
21 × 3 = 63 % 1000 = 63

Step 3:
63 × 65 = 4095 % 1000 = 95

Step 4:
95 × 65 = 6175 % 1000 = 175
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [2, 4]
start = 3
end = 5

<strong>Output:</strong>
-1

<strong>Explanation:</strong>
Starting from 3 and multiplying by either 2 or 4 always produces even numbers after the first step. Hence, 5 can never be reached.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 10<sup>3</sup></code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>3</sup></code></li>
  <li><code>0 ≤ start, end &lt; 10<sup>3</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(1000 × arr.size())</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(1000)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>Breadth-First Search (BFS)</strong> by treating each modulo value as a graph node?</p>
