<h2>435. Non-overlapping Intervals</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array of intervals, return the <strong>minimum number of intervals to remove</strong> so that the remaining intervals do not overlap.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
intervals = [[1,2],[2,3],[3,4],[1,3]]

<strong>Output:</strong>
1
</pre>

<p><strong>Greedy Approach:</strong></p>

<p>Sort the intervals by their <strong>ending time</strong>. Keep the interval that finishes earliest and remove an interval whenever it overlaps with the previously selected interval.</p>

<p><strong>Key Observation:</strong></p>

<p>When two intervals overlap, keep the one with the <strong>smaller end time</strong>. It leaves more space for future intervals.</p>

<p>Intervals that touch, such as <code>[1,2]</code> and <code>[2,3]</code>, are considered non-overlapping.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code> (excluding sorting space)</p>
