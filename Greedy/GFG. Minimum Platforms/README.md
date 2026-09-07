<h2>Minimum Platforms</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the arrival and departure times of trains, find the <strong>minimum number of platforms</strong> required so that no train has to wait.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
arr = [900,940,950,1100,1500,1800]
dep = [910,1200,1120,1130,1900,2000]

<strong>Output:</strong>
3
</pre>

<p><strong>Greedy Approach:</strong></p>

<p>Sort both arrival and departure times. Use two pointers to process events in chronological order.</p>

<p>If a train arrives before the earliest departure, we need a new platform. Otherwise, a platform becomes free and can be reused.</p>

<p><strong>Key Observation:</strong></p>

<p>Track the <strong>maximum number of trains present at the same time</strong>. That is the minimum number of platforms required.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code> (excluding sorting space)</p>
