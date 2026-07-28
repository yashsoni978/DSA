<h2>1021. Remove Outermost Parentheses</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>A valid parentheses string is either:</p>

<ul>
  <li>An empty string <code>""</code>.</li>
  <li><code>"(" + A + ")"</code>, where <code>A</code> is a valid parentheses string.</li>
  <li><code>A + B</code>, where <code>A</code> and <code>B</code> are valid parentheses strings.</li>
</ul>

<p>A <strong>primitive</strong> valid parentheses string is a non-empty valid parentheses string that cannot be split into two non-empty valid parentheses strings.</p>

<p>Given a valid parentheses string <code>s</code>, remove the <strong>outermost parentheses</strong> from every primitive string and return the resulting string.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "(()())(())"

<strong>Output:</strong>
"()()()"

<strong>Explanation:</strong>

The primitive strings are:

(()())
(())

Removing the outermost parentheses:

()()
()

Result:

()()()
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "(()())(())(()(()))"

<strong>Output:</strong>
"()()()()(())"

<strong>Explanation:</strong>

The primitive strings are:

(()())
(())
(()(()))

After removing the outermost parentheses:

()()
()
()(())

Result:

()()()()(())
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "()()"

<strong>Output:</strong>
""

<strong>Explanation:</strong>

The primitive strings are:

()
()

Removing the outermost parentheses from each
produces an empty string.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 10<sup>5</sup></code></li>
  <li><code>s[i]</code> is either <code>'('</code> or <code>')'</code>.</li>
  <li><code>s</code> is a valid parentheses string.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in a single pass using a <strong>depth counter</strong>, appending characters only when they are not the outermost parentheses, achieving <code>O(n)</code> time and <code>O(n)</code> extra space?</p>
