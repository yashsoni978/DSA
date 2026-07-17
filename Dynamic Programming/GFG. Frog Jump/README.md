<h2>Frog Jump</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>height[]</code> where <code>height[i]</code> represents the height of the <code>i<sup>th</sup></code> stair, a frog starts from the first stair and wants to reach the last stair.</p>

<p>From any stair <code>i</code>, the frog can either:</p>

<ul>
  <li>Jump to the <code>(i + 1)<sup>th</sup></code> stair.</li>
  <li>Jump to the <code>(i + 2)<sup>th</sup></code> stair.</li>
</ul>

<p>The cost of each jump is the absolute difference between the heights of the starting and destination stairs.</p>

<p>Return the <strong>minimum total cost</strong> required for the frog to reach the last stair.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
height[] = [20,30,40,20]

<strong>Output:</strong>
20

<strong>Explanation:</strong>

Jump from stair 0 → 1:
Cost = |30 - 20| = 10

Jump from stair 1 → 3:
Cost = |20 - 30| = 10

Total Cost = 20
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
height[] = [30,20,50,10,40]

<strong>Output:</strong>
30

<strong>Explanation:</strong>

Jump from stair 0 → 2:
Cost = |50 - 30| = 20

Jump from stair 2 → 4:
Cost = |40 - 50| = 10

Total Cost = 30
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ height.size() ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ height[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> while optimizing the space complexity to <code>O(1)</code>?</p>
