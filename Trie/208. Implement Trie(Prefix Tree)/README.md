<h2>208. Implement Trie (Prefix Tree)</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>A <strong>Trie</strong> (Prefix Tree) is a tree-like data structure used to efficiently store and search strings. Implement a Trie with support for inserting words, searching for complete words, and checking whether any word starts with a given prefix.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");
trie.search("app");
trie.startsWith("app");
trie.insert("app");
trie.search("app");

<strong>Output:</strong>
true
false
true
true </pre>

<p><strong>Approach:</strong></p>
<p>Use a <strong>Trie</strong> where each node contains references to its child characters and a boolean indicating whether a complete word ends at that node.</p>

<p>For <strong>insert</strong>, start from the root and create a new node whenever the required character does not exist.</p>

<p>For <strong>search</strong>, traverse the Trie character by character. The word exists only if every character is found and the final node is marked as the end of a word.</p>

<p>For <strong>startsWith</strong>, traverse the Trie using the characters of the prefix. If the traversal succeeds, at least one inserted word starts with that prefix.</p>

<p><strong>Key Observation:</strong></p>
<p>The Trie stores characters along shared prefixes. Therefore, words such as <code>"apple"</code> and <code>"app"</code> share the same path for <code>"app"</code>. The <code>isEnd</code> flag distinguishes whether a prefix is also a complete word.</p>

<p><strong>Time Complexity:</strong> <code>O(L)</code> for <code>insert</code>, <code>search</code>, and <code>startsWith</code>, where <code>L</code> is the length of the word or prefix.</p>

<p><strong>Space Complexity:</strong> <code>O(N × L)</code> in the worst case, where <code>N</code> is the number of inserted words and <code>L</code> is their maximum length.</p>
