<h2>Infix To Prefix</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <strong>infix expression</strong>, convert it into its corresponding <strong>prefix expression</strong>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "a*(b+c)/d"

<strong>Output:</strong>
/*a+bcd
</pre>

<p><strong>Approach:</strong></p>

<p>Use the standard <strong>Infix → Prefix</strong> technique:</p>

<ol>
<li>Reverse the infix expression.</li>
<li>Swap <code>(</code> with <code>)</code>.</li>
<li>Convert the modified expression to <strong>postfix</strong>.</li>
<li>Reverse the postfix expression to get the <strong>prefix</strong> expression.</li>
</ol>

<p>While converting to postfix, handle operator precedence and associativity correctly, especially <code>^</code> which is right-associative.</p>

<p><strong>Key Observation:</strong></p>

<p><strong>Reverse → Swap Brackets → Infix to Postfix → Reverse</strong> gives the required prefix expression.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
