<h2>205. Isomorphic Strings</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given two strings <code>s</code> and <code>t</code>, determine if they are <strong>isomorphic</strong>.</p>

<p>Two strings are isomorphic if the characters in <code>s</code> can be replaced to obtain <code>t</code>, while preserving the order of characters.</p>

<p>Each character must map to <strong>exactly one</strong> other character, and no two different characters may map to the same character. A character may map to itself.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "egg"
t = "add"

<strong>Output:</strong>
true

<strong>Explanation:</strong>

Character mappings are:

e → a
g → d

The mapping is consistent,
so the strings are isomorphic.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "foo"
t = "bar"

<strong>Output:</strong>
false

<strong>Explanation:</strong>

The character 'o' would need to map to
both 'a' and 'r', which is not allowed.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "paper"
t = "title"

<strong>Output:</strong>
true

<strong>Explanation:</strong>

Character mappings are:

p → t
a → i
e → l
r → e

The mapping is one-to-one
and consistent throughout.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 5 × 10<sup>4</sup></code></li>
  <li><code>t.length == s.length</code></li>
  <li><code>s</code> and <code>t</code> consist of any valid ASCII character.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in a single pass using two <strong>Hash Maps</strong> (or two arrays for ASCII characters) to maintain a one-to-one mapping between characters, achieving <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
