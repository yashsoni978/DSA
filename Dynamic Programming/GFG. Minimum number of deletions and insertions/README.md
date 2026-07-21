<h2>Minimum Number of Deletions and Insertions</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two strings <code>s1</code> and <code>s2</code>, determine the <strong>minimum number of deletions and insertions</strong> required to transform <code>s1</code> into <code>s2</code>.</p>

<p>You may perform the following operations:</p>

<ul>
  <li>Delete any character from <code>s1</code>.</li>
  <li>Insert any character at any position in <code>s1</code>.</li>
</ul>

<p><strong>Note:</strong> The same character may need to be deleted from one position and inserted at another.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s1 = "heap"
s2 = "pea"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

Delete 'h' and 'p' from "heap".

Remaining string = "ea"

Insert 'p' at the beginning.

Result = "pea"

Total operations = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s1 = "geeksforgeeks"
s2 = "geeks"

<strong>Output:</strong>
8

<strong>Explanation:</strong>

Delete the substring:

"forgeeks"

Total deletions = 8

No insertions are required.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s1.size(), s2.size() ≤ 1000</code></li>
  <li>Both strings consist only of lowercase English letters.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × m)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(m)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using the <strong>Longest Common Subsequence (LCS)</strong>, where the answer is <code>(|s1| − LCS) + (|s2| − LCS)</code>, while optimizing the space complexity to <code>O(m)</code>?</p>
