<h2>796. Rotate String</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given two strings <code>s</code> and <code>goal</code>, return <code>true</code> if and only if <code>s</code> can become <code>goal</code> after some number of <strong>left rotations</strong>.</p>

<p>A <strong>left rotation</strong> moves the leftmost character of the string to its rightmost position.</p>

<p>For example, if <code>s = "abcde"</code>, then after one left rotation it becomes <code>"bcdea"</code>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "abcde"
goal = "cdeab"

<strong>Output:</strong>
true

<strong>Explanation:</strong>

Perform two left rotations:

abcde → bcdea → cdeab

The resulting string equals goal.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "abcde"
goal = "abced"

<strong>Output:</strong>
false

<strong>Explanation:</strong>

No sequence of left rotations
can transform "abcde" into "abced".
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length, goal.length ≤ 100</code></li>
  <li><code>s</code> and <code>goal</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this by checking whether <code>goal</code> is a substring of <code>s + s</code> (after verifying both strings have equal length), achieving <code>O(n)</code> average time?</p>
