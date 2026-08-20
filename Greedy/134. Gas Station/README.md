<h2>134. Gas Station</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are <code>n</code> gas stations along a circular route, where <code>gas[i]</code> is the amount of gas available at station <code>i</code> and <code>cost[i]</code> is the gas required to travel from station <code>i</code> to the next station.</p>

<p>Return the starting gas station's index if you can travel around the circuit once in the clockwise direction. Otherwise, return <code>-1</code>.</p>

<h3>Example 1</h3>

<pre>
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3
</pre>

<h3>Example 2</h3>

<pre>
gas  = [2,3,4]
cost = [3,4,3]

Output: -1
</pre>

<h3>Approach</h3>

<ul>
<li>First check whether the total amount of gas is less than the total cost. If it is, completing the circuit is impossible.</li>
<li>Keep a running <code>total</code> representing the current surplus of gas.</li>
<li>If <code>total</code> becomes negative at station <code>i</code>, the current starting point and every station between the current start and <code>i</code> cannot be a valid starting point.</li>
<li>Greedily set the next station <code>i + 1</code> as the new starting point and reset <code>total</code> to <code>0</code>.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Greedy</p>

<p><strong>Key Idea:</strong> If the running gas becomes negative, discard the entire failed segment and start from the next station.</p>
