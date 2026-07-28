<h2>242. Valid Anagram</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given two strings <code>s</code> and <code>t</code>, return <code>true</code> if <code>t</code> is an <strong>anagram</strong> of <code>s</code>, and <code>false</code> otherwise.</p>

<p>An <strong>anagram</strong> is a word or phrase formed by rearranging the letters of another word, using all the original characters exactly once.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "anagram"
t = "nagaram"

<strong>Output:</strong>
true

<strong>Explanation:</strong>

Both strings contain the same
characters with the same frequencies,
only their order differs.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "rat"
t = "car"

<strong>Output:</strong>
false

<strong>Explanation:</strong>

The character frequencies differ,
so the strings are not anagrams.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length, t.length ≤ 5 × 10<sup>4</sup></code></li>
  <li><code>s</code> and <code>t</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> What if the inputs contain Unicode characters? Can you solve it using a <strong>Hash Map</strong> instead of a fixed-size frequency array while still achieving <code>O(n)</code> time complexity?</p>
