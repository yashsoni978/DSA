<h2>28. Find the Index of the First Occurrence in a String</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given two strings <code>haystack</code> and <code>needle</code>, return the index of the <strong>first occurrence</strong> of <code>needle</code> in <code>haystack</code>.</p>

<p>If <code>needle</code> is not part of <code>haystack</code>, return <code>-1</code>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
haystack = "sadbutsad"
needle = "sad"

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The substring "sad"
first appears at index 0.

Another occurrence exists at index 6,
but the first one is returned.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
haystack = "leetcode"
needle = "leeto"

<strong>Output:</strong>
-1

<strong>Explanation:</strong>

The substring "leeto"
does not occur in "leetcode".
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ haystack.length, needle.length ≤ 10<sup>4</sup></code></li>
  <li><code>haystack</code> and <code>needle</code> consist of only lowercase English characters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in <code>O(n + m)</code> time using the <strong>KMP (Knuth–Morris–Pratt)</strong> algorithm by preprocessing the pattern into an LPS (Longest Prefix Suffix) array and then performing a single pass through the text?</p>
