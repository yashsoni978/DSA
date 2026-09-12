<h2>402. Remove K Digits</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given a non-negative integer represented as a string, remove exactly <code>k</code> digits so that the resulting number is the <strong>smallest possible</strong>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
num = "1432219", k = 3

<strong>Output:</strong>
"1219" </pre>

<p><strong>Greedy Approach:</strong></p>
<p>Use a <strong>Monotonic Increasing Stack</strong>. While the current digit is smaller than the stack top, remove the larger digit because keeping the smaller digit earlier produces a smaller number.</p>

<ul>
<li>While <code>k &gt; 0</code> and <code>st.top() &gt; current</code>, pop the stack.</li>
<li>Push the current digit.</li>
<li>If <code>k</code> is still greater than <code>0</code>, remove digits from the end.</li>
<li>Remove leading zeros from the result.</li>
<li>If nothing remains, return <code>"0"</code>.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>When <code>previous digit &gt; current digit</code>, deleting the previous digit makes the number smaller. Always remove the larger digit before the smaller digit.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
