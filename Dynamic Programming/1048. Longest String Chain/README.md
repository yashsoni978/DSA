<h2>1048. Longest String Chain</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an array of strings <code>words</code>, where each string consists of lowercase English letters.</p>

<p>A string <code>wordA</code> is a <strong>predecessor</strong> of <code>wordB</code> if and only if:</p>

<ul>
  <li><code>wordB.length == wordA.length + 1</code>, and</li>
  <li>You can insert exactly one letter anywhere in <code>wordA</code> to obtain <code>wordB</code> without changing the order of the other characters.</li>
</ul>

<p>A <strong>word chain</strong> is a sequence of words <code>[word<sub>1</sub>, word<sub>2</sub>, ..., word<sub>k</sub>]</code> where <code>word<sub>i</sub></code> is a predecessor of <code>word<sub>i+1</sub></code> for every valid <code>i</code>.</p>

<p>Return the <strong>length of the longest possible word chain</strong>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
words = ["a","b","ba","bca","bda","bdca"]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

One longest chain is

"a" → "ba" → "bda" → "bdca"

whose length is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]

<strong>Output:</strong>
5

<strong>Explanation:</strong>

One longest chain is

"xb" → "xbc" → "cxbc"
→ "pcxbc" → "pcxbcf"

whose length is 5.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
words = ["abcd","dbqca"]

<strong>Output:</strong>
1

<strong>Explanation:</strong>

No word can be formed by adding
exactly one character to another.

Hence the longest chain
contains only one word.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ words.length ≤ 1000</code></li>
  <li><code>1 ≤ words[i].length ≤ 16</code></li>
  <li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by sorting the words based on their lengths and checking predecessor relationships, achieving <code>O(n² × L)</code> time, where <code>L</code> is the maximum word length?</p>
