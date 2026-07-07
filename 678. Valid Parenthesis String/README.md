<h2>678. Valid Parenthesis String</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code> containing only three types of characters: <code>'('</code>, <code>')'</code>, and <code>'*'</code>, return <code>true</code> if <code>s</code> is valid.</p>

<p>The following rules define a valid string:</p>

<ul>
  <li>Every <code>'('</code> must have a corresponding <code>')'</code>.</li>
  <li>Every <code>')'</code> must have a corresponding <code>'('</code>.</li>
  <li><code>'('</code> must appear before its matching <code>')'</code>.</li>
  <li><code>'*'</code> can be treated as:
    <ul>
      <li><code>'('</code></li>
      <li><code>')'</code></li>
      <li>an empty string <code>""</code></li>
    </ul>
  </li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = "()"
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = "(*)"
<strong>Output:</strong> true
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = "(*))"
<strong>Output:</strong> true
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 100</code></li>
  <li><code>s[i]</code> is <code>'('</code>, <code>')'</code>, or <code>'*'</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve it in <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
