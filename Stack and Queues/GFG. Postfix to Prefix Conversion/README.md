<h2>Postfix to Prefix Conversion</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a valid <strong>postfix expression</strong>, convert it into its equivalent <strong>prefix expression</strong>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "ab+c*"

<strong>Output:</strong>
*+abc
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Stack of strings</strong> and traverse the postfix expression from <strong>left to right</strong>.</p>

<ul>
<li>If the character is an operand, push it into the stack.</li>
<li>If it is an operator, pop the top two operands.</li>
<li>Form <code>operator + operand1 + operand2</code>.</li>
<li>Push the resulting prefix expression back into the stack.</li>
<li>The final stack element is the answer.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Postfix is processed from <strong>left to right</strong>. The <strong>second popped element</strong> is the left operand, while the <strong>first popped element</strong> is the right operand.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
