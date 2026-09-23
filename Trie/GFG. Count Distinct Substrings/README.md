<h2>Count Distinct Substrings</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given a string <code>s</code> consisting of lowercase English letters, find the total number of distinct non-empty <strong>substrings</strong> of <code>s</code>.</p>

<p>A substring is a contiguous sequence of characters within a string. Two substrings are considered distinct if their character sequences are different, regardless of their positions.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong>
s = "ababa"

<strong>Output:</strong>
9

<strong>Explanation:</strong>
The distinct substrings are:

"a", "b", "ab", "ba", "aba",
"bab", "abab", "baba", "ababa" </pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong>
s = "aaa"

<strong>Output:</strong>
3

<strong>Explanation:</strong>
The distinct substrings are:

"a", "aa", "aaa" </pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Trie</strong> to store all suffixes of the string. Every distinct substring is a prefix of at least one suffix.</p>

<p>Start from every index of the string and insert the suffix starting at that index into the Trie. While inserting a suffix, whenever a new Trie node is created, it represents a <strong>new distinct substring</strong>. Therefore, increment the answer whenever a new node is created.</p>

<p>For example, for <code>"aaa"</code>:</p>

<pre>
Suffixes:

"aaa"
"aa"
"a"
</pre>

<p>Only three new nodes are created, corresponding to:</p>

<pre>
"a"
"aa"
"aaa"
</pre>

<p>Therefore, the answer is <code>3</code>.</p>

<p><strong>Key Observation:</strong></p>

<p>Every substring can be represented as a prefix of a suffix. By inserting all suffixes into a Trie, each newly created node corresponds to exactly one previously unseen substring.</p>

<p>So the answer is simply the <strong>number of Trie nodes created, excluding the root</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(n²)</code>, where <code>n</code> is the length of the string.</p>

<p><strong>Space Complexity:</strong> <code>O(n² × 26)</code> in the worst case for the Trie.</p>
