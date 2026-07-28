<h2>1614. Maximum Nesting Depth of the Parentheses</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given a valid parentheses string <code>s</code>, return the <strong>maximum nesting depth</strong> of the parentheses.</p>

<p>The <strong>nesting depth</strong> is the maximum number of nested parentheses at any point in the string.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "(1+(2*3)+((8)/4))+1"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The deepest nesting occurs in:

((8)/4)

At that point,
three opening parentheses
are nested together.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "(1)+((2))+(((3)))"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The maximum nesting depth is reached
in the substring:

(((3)))
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 100</code></li>
  <li><code>s</code> consists of digits <code>0-9</code>, characters <code>'+'</code>, <code>'-'</code>, <code>'*'</code>, <code>'/'</code>, <code>'('</code>, <code>')'</code>, and spaces.</li>
  <li><code>s</code> is a valid parentheses string.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in a single pass by maintaining a <strong>depth counter</strong>, incrementing it for every <code>'('</code>, decrementing it for every <code>')'</code>, and tracking the maximum value reached, achieving <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
