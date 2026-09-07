<h2>Maximum Meetings in One Room</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the start and finish times of meetings, schedule the <strong>maximum number of non-overlapping meetings</strong> in a single room.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = [1,3,0,5,8,5]
f = [2,4,6,7,9,9]

<strong>Output:</strong>
[1,2,4,5]
</pre>

<p><strong>Greedy Approach:</strong></p>

<p>Sort meetings by their <strong>finish time</strong>. Select a meeting if its start time is strictly greater than the finish time of the previously selected meeting.</p>

<p><strong>Key Observation:</strong></p>

<p>Always choose the meeting that <strong>finishes earliest</strong>. This leaves the maximum possible time for future meetings.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
