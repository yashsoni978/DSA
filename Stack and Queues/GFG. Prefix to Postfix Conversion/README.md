<h2>Prefix to Postfix Conversion</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a valid <strong>prefix expression</strong>, convert it into its equivalent <strong>postfix expression</strong>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "*+ABC"

<strong>Output:</strong>
AB+C*
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Stack of strings</strong> and traverse the prefix expression from <strong>right to left</strong>.</p>

<ul>
<li>If the character is an operand, push it into the stack.</li>
<li>If it is an operator, pop the top two operands.</li>
<li>Form <code>operand1 + operand2 + operator</code>.</li>
<li>Push the resulting postfix expression back into the stack.</li>
<li>The final stack element is the answer.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Prefix is processed from <strong>right to left</strong>. For an operator, the first popped element is the <strong>left operand</strong> and the second is the <strong>right operand</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
