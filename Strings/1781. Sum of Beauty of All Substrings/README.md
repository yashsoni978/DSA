<h2>1781. Sum of Beauty of All Substrings</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>The <strong>beauty</strong> of a string is defined as the difference between the highest and the lowest frequency of characters that appear in the string.</p>

<p>For example, the beauty of <code>"abaacc"</code> is <code>3 - 1 = 2</code>.</p>

<p>Given a string <code>s</code>, return the <strong>sum of beauty</strong> of all of its substrings.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "aabcb"

<strong>Output:</strong>
5

<strong>Explanation:</strong>

The substrings with non-zero beauty are:

"aab"   → beauty = 1
"aabc"  → beauty = 1
"aabcb" → beauty = 1
"abcb"  → beauty = 1
"bcb"   → beauty = 1

Total beauty = 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "aabcbaa"

<strong>Output:</strong>
17
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 500</code></li>
  <li><code>s</code> consists of only lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this by fixing the starting index, expanding the ending index while maintaining a <strong>frequency array of size 26</strong>, recomputing the maximum and minimum non-zero frequencies for each substring, achieving <code>O(26 × n²)</code> time (effectively <code>O(n²)</code>) and <code>O(26)</code> extra space?</p>
