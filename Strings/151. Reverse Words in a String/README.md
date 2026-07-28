<h2>151. Reverse Words in a String</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an input string <code>s</code>, reverse the order of the <strong>words</strong>.</p>

<p>A <strong>word</strong> is defined as a sequence of non-space characters.</p>

<p>The returned string should contain the words in <strong>reverse order</strong>, separated by a <strong>single space</strong>.</p>

<p>Note that <code>s</code> may contain leading, trailing, or multiple spaces between words. The returned string should not contain any leading or trailing spaces, and multiple spaces between words should be reduced to a single space.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "the sky is blue"

<strong>Output:</strong>
"blue is sky the"

<strong>Explanation:</strong>

Reverse the order of the words
while preserving each word.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "  hello world  "

<strong>Output:</strong>
"world hello"

<strong>Explanation:</strong>

Leading and trailing spaces
are removed.

The words are separated by
a single space.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "a good   example"

<strong>Output:</strong>
"example good a"

<strong>Explanation:</strong>

Multiple spaces between words
are reduced to a single space.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 10<sup>4</sup></code></li>
  <li><code>s</code> contains English letters, digits, and spaces <code>' '</code>.</li>
  <li>There is at least one word in <code>s</code>.</li>
</ul>

<p><strong>Follow-up:</strong> If the string type is mutable, can you solve this <strong>in-place</strong> with <code>O(1)</code> extra space by reversing the entire string first and then reversing each individual word?</p>
