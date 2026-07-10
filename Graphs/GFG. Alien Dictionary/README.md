<h2>Alien Dictionary</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words <code>words[]</code> from the alien language's dictionary, where the words are claimed to be sorted lexicographically according to the language's rules.</p>

<p>Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.</p>

<p>If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string <code>("")</code>.</p>

<p>A string <code>a</code> is lexicographically smaller than a string <code>b</code> if, at the first position where they differ, the character in <code>a</code> appears earlier in the alien language than the corresponding character in <code>b</code>. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.</p>

<p><strong>Note:</strong> Your implementation will be tested using a driver code. It will print <code>true</code> if your returned order correctly follows the alien language's lexicographic rules; otherwise, it will print <code>false</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
words[] = ["baa", "abcd", "abca", "cab", "cad"]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
One valid order is "bdac".

"baa"  → "abcd"  ⇒ b comes before a
"abcd" → "abca"  ⇒ d comes before a
"abca" → "cab"   ⇒ a comes before c
"cab"  → "cad"   ⇒ b comes before d

Hence, one possible ordering is:
b → d → a → c
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
words[] = ["caa", "aaa", "aab"]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
One valid order is "cab".

"caa" → "aaa" ⇒ c comes before a
"aaa" → "aab" ⇒ a comes before b

Hence, one possible ordering is:
c → a → b
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
words[] = ["ab", "cd", "ef", "ad"]

<strong>Output:</strong>
""

<strong>Explanation:</strong>
No valid ordering exists because the inferred character ordering
contains a contradiction.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ words.length ≤ 500</code></li>
  <li><code>1 ≤ words[i].length ≤ 100</code></li>
  <li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(N × L + K)</code>, where <code>N</code> is the number of words, <code>L</code> is the average word length, and <code>K</code> is the number of unique characters.</p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(K + E)</code>, where <code>E</code> is the number of precedence relations between characters.</p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Topological Sort (Kahn's Algorithm)</strong> or <strong>DFS</strong> on the graph formed by character precedence constraints?</p>
