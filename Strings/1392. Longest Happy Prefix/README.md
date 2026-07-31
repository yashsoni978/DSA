<h2>1392. Longest Happy Prefix</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>A <strong>happy prefix</strong> is a non-empty prefix of a string that is also a suffix, excluding the entire string itself.</p>

<p>Given a string <code>s</code>, return the <strong>longest happy prefix</strong> of <code>s</code>. If no such prefix exists, return an empty string.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "level"

<strong>Output:</strong>
"l"

<strong>Explanation:</strong>

The prefix "l"
is also the suffix "l".

No longer proper prefix
satisfies the condition.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "ababab"

<strong>Output:</strong>
"abab"

<strong>Explanation:</strong>

The prefix "abab"
is also the suffix "abab".

It is the longest proper prefix
that is also a suffix.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "leetcodeleet"

<strong>Output:</strong>
"leet"

<strong>Explanation:</strong>

The prefix "leet"
matches the suffix "leet",
making it the longest happy prefix.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 10<sup>5</sup></code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n)</code> time by computing the <strong>LPS (Longest Prefix Suffix)</strong> array of the string using the <strong>KMP preprocessing</strong> algorithm? The answer is the prefix of length <code>LPS[n - 1]</code>.</p>
