<h2>Job Sequencing Problem</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given jobs with a <code>deadline</code> and <code>profit</code>, each job takes <strong>1 unit of time</strong>. Schedule jobs to maximize the total profit, while completing each job before its deadline.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
deadline = [4,1,1,1]
profit = [20,10,40,30]

<strong>Output:</strong>
[2,60]
</pre>

<p><strong>Greedy Approach:</strong></p>

<p>Sort jobs in <strong>decreasing order of profit</strong>. For each job, place it in the <strong>latest available slot</strong> before its deadline.</p>

<p><strong>Key Observation:</strong></p>

<p>Take the highest-profit job first, and place it as late as possible. This keeps earlier slots available for other jobs.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n + n × d)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
