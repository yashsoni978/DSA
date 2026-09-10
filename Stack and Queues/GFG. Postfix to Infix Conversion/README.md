<h2>Postfix to Infix Conversion</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a valid <strong>postfix expression</strong>, convert it into its equivalent <strong>infix expression</strong>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "ab*c+"

<strong>Output:</strong>
((a*b)+c)
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Stack of strings</strong>.</p>

<ul>
<li>If the character is an operand, push it into the stack.</li>
<li>If it is an operator, pop the top two operands.</li>
<li>Create <code>(operand1 operator operand2)</code> and push it back.</li>
<li>The final stack element is the infix expression.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>For every operator, the <strong>second popped element is the left operand</strong> and the <strong>first popped element is the right operand</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
