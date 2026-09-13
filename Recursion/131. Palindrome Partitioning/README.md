<h2>131. Palindrome Partitioning</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given a string <code>s</code>, partition it so that every substring in the partition is a <strong>palindrome</strong>. Return all possible palindrome partitions.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
s = "aab"

<strong>Output:</strong>
[["a","a","b"],["aa","b"]] </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. Starting from each index, try every possible substring. If the substring is a palindrome, add it to the current partition and recursively process the remaining string. After returning, remove it and try the next substring.</p>

<p><strong>Key Observation:</strong></p>
<p>Only <strong>palindromic substrings</strong> can be added to the current partition. When we reach the end of the string, the current partition is a valid answer.</p>

<p><strong>Time Complexity:</strong> <code>O(n × 2<sup>n</sup>)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code> recursion stack, excluding the output.</p>
