<h2>735. Asteroid Collision</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array of asteroids moving in a line, positive values move right and negative values move left. When two asteroids collide, the smaller one explodes. If they are equal, both explode. Return the state after all collisions.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
asteroids = [5,10,-5]

<strong>Output:</strong>
[5,10] </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use a <strong>Stack</strong>. A collision is possible only when the stack top is moving right and the current asteroid is moving left.</p>

<ul>
<li>If <code>abs(stack.top()) &lt; abs(current)</code> → pop the stack.</li>
<li>If both are equal → pop the stack and destroy current.</li>
<li>If <code>abs(stack.top()) &gt; abs(current)</code> → destroy current.</li>
<li>If no collision occurs → push current.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>Only <code>positive → negative</code> pairs can collide. The stack keeps the surviving asteroids in their final order.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
