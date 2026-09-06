<h2>Shortest Job First</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>bt[]</code> containing the burst time of each process, calculate the average waiting time using the <strong>Shortest Job First (SJF)</strong> scheduling policy.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
bt = [4,3,7,1,2]

<strong>Output:</strong>
4
</pre>

<p><strong>Greedy Approach:</strong></p>

<p>Sort all processes by their <strong>burst time</strong> and execute the shortest job first.</p>

<p>For each process, its waiting time is the sum of burst times of all previous processes.</p>

<p><strong>Key Observation:</strong></p>

<p>Choosing the shortest available job first minimizes the total waiting time of all processes.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code> (excluding sorting space)</p>
