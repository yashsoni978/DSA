<h2>Prefix to Infix Conversion</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a valid <strong>prefix expression</strong>, convert it into a fully parenthesized <strong>infix expression</strong>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "*-A/BC-/AKL"

<strong>Output:</strong>
((A-(B/C))*((A/K)-L))
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Stack of strings</strong> and traverse the prefix expression from <strong>right to left</strong>.</p>

<ul>
<li>If the character is an operand, push it into the stack.</li>
<li>If it is an operator, pop the top two operands.</li>
<li>Create <code>(operand1 operator operand2)</code> and push it back.</li>
<li>The final stack element is the infix expression.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Prefix is processed from <strong>right to left</strong>. The first popped element becomes the <strong>left operand</strong>, while the second becomes the <strong>right operand</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
