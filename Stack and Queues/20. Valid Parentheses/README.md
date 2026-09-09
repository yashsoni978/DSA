<h2>20. Valid Parentheses</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given a string containing <code>()</code>, <code>{}</code>, and <code>[]</code>, determine whether the brackets are <strong>valid</strong>. Every opening bracket must be closed by the same type of bracket in the correct order.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "({[]})"

<strong>Output:</strong>
true
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Stack</strong>. Push every opening bracket. For a closing bracket, check whether it matches the stack's top. If it does not match, return <code>false</code>.</p>

<ul>
<li>Opening bracket → <code>push()</code></li>
<li>Closing bracket → check and <code>pop()</code></li>
<li>At the end, the stack must be empty.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>The most recently opened bracket must be closed first, which follows the <strong>LIFO</strong> property of a stack.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
