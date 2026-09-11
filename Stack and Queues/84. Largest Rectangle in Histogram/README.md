<h2>84. Largest Rectangle in Histogram</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Given an array of bar heights, find the area of the <strong>largest rectangle</strong> that can be formed in the histogram.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
heights = [2,1,5,6,2,3]

<strong>Output:</strong>
10 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use a <strong>Monotonic Increasing Stack</strong> to find the range in which each bar can be the minimum height.</p>

<ul>
<li>When the current height is smaller than the stack top, the top bar can no longer extend to the right.</li>
<li>Pop the bar and calculate its rectangle.</li>
<li>The new stack top gives the nearest smaller element on the left.</li>
<li>The current index gives the nearest smaller element on the right.</li>
</ul>

<pre>
width = rightSmaller - leftSmaller - 1
area = height × width
</pre>

<p><strong>Key Observation:</strong></p>
<p>For every bar, find the <strong>nearest smaller element on both sides</strong>. This tells us the maximum width for which that bar can be the smallest height.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
