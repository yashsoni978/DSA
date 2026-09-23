<h2>Longest Valid Word with All Prefixes</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array of strings <code>words[]</code>, find the <strong>longest string</strong> such that every prefix of it is also present in <code>words[]</code>. If multiple strings have the same maximum length, return the <strong>lexicographically smallest</strong> one.</p>

<p>If no valid string exists, return an empty string.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong>
words = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]

<strong>Output:</strong>
"pros"

<strong>Explanation:</strong>
The prefixes of "pros" are:
"p", "pr", "pro", "pros"

All of them are present in the array, so "pros" is valid. </pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong>
words = ["geeks", "gfg", "geeksforgeeks"]

<strong>Output:</strong>
""

<strong>Explanation:</strong>
"geeks" does not have all its prefixes present, such as "g", "ge", etc.
Therefore, no valid string exists. </pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Trie</strong> to store all the words. Each Trie node contains the child pointers and a boolean <code>isEnd</code> indicating whether a complete word ends at that node.</p>

<p>After inserting all words, check every word character by character in the Trie. At every character, the current node must have <code>isEnd = true</code>. This ensures that every prefix of the word exists in the array.</p>

<p>For every valid word:</p>

<ul>
<li>If its length is greater than the current answer, update the answer.</li>
<li>If its length is equal to the current answer, choose the lexicographically smaller word.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>A word is valid only when <strong>every node on its Trie path represents the end of a word</strong>.</p>

<p>For example, for <code>"pros"</code>:</p>

<pre>
p → pr → pro → pros
✓    ✓     ✓      ✓
</pre>

<p>Since every prefix is present, <code>"pros"</code> is a valid candidate.</p>

<p><strong>Time Complexity:</strong> <code>O(N × L)</code>, where <code>N</code> is the number of words and <code>L</code> is the maximum word length.</p>

<p><strong>Space Complexity:</strong> <code>O(N × L)</code> in the worst case for the Trie.</p>
