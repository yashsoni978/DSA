<h2>126. Word Ladder II</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>A <strong>transformation sequence</strong> from word <code>beginWord</code> to word <code>endWord</code> using a dictionary <code>wordList</code> is a sequence of words such that:</p>

<ul>
  <li>The first word in the sequence is <code>beginWord</code>.</li>
  <li>The last word in the sequence is <code>endWord</code>.</li>
  <li>Only one letter can be changed at a time.</li>
  <li>Each transformed word must exist in <code>wordList</code>. The <code>beginWord</code> does not need to be in <code>wordList</code>.</li>
</ul>

<p>Given two words, <code>beginWord</code> and <code>endWord</code>, and a dictionary <code>wordList</code>, return <strong>all the shortest transformation sequences</strong> from <code>beginWord</code> to <code>endWord</code>. If no such sequence exists, return an empty list. You may return the sequences in any order.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

<strong>Output:</strong>
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

<strong>Output:</strong>
[]

<strong>Explanation:</strong>
The endWord "cog" is not present in the wordList, so no valid transformation sequence exists.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= beginWord.length &lt;= 5</code></li>
  <li><code>endWord.length == beginWord.length</code></li>
  <li><code>1 &lt;= wordList.length &lt;= 500</code></li>
  <li><code>wordList[i].length == beginWord.length</code></li>
  <li><code>beginWord</code>, <code>endWord</code>, and <code>wordList[i]</code> consist of lowercase English letters.</li>
  <li><code>beginWord != endWord</code></li>
  <li>All the words in <code>wordList</code> are unique.</li>
  <li>The sum of all shortest transformation sequences does not exceed <code>10<sup>5</sup></code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>BFS</strong> to find the shortest levels and <strong>DFS/Backtracking</strong> to reconstruct all shortest transformation sequences?</p>
