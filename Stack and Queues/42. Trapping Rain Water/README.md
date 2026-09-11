<h2>42. Trapping Rain Water</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given an array representing elevation heights, calculate how much <strong>rain water</strong> can be trapped between the bars.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
height = [0,1,0,2,1,0,1,3,2,1,2,1]

<strong>Output:</strong>
6
</pre>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Two Pointer</strong> technique with <code>leftMax</code> and <code>rightMax</code>.</p>

<ul>
<li>Keep pointers <code>l</code> and <code>r</code> at both ends.</li>
<li>If <code>height[l] &lt;= height[r]</code>, process the left side.</li>
<li>Otherwise, process the right side.</li>
<li>Water at a position = <strong>maximum boundary − current height</strong>.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Water is limited by the <strong>shorter boundary</strong>. The smaller side can therefore be processed safely using its maximum height.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
