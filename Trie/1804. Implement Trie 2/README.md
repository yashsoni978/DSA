<h2>1804. Implement Trie II (Prefix Tree)</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Implement a Trie that supports inserting words, counting how many times a word has been inserted, counting how many inserted words start with a given prefix, and erasing a word.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
Trie trie = new Trie();

trie.insert("apple");
trie.insert("apple");

trie.countWordsEqualTo("apple");

trie.countWordsStartingWith("app");

trie.erase("apple");

trie.countWordsEqualTo("apple");

<strong>Output:</strong>
2
2
1 </pre>

<p><strong>Approach:</strong></p>
<p>Use a <strong>Trie</strong> where each node stores two counters: <code>cntEndWith</code>, which stores how many times a complete word ends at that node, and <code>cntPrefix</code>, which stores how many inserted words pass through that node.</p>

<p>For <strong>insert</strong>, traverse the Trie character by character and increment <code>cntPrefix</code> for every node visited. After reaching the last character, increment <code>cntEndWith</code>.</p>

<p>For <strong>countWordsEqualTo</strong>, traverse the Trie. If the complete word exists, return the <code>cntEndWith</code> value of the final node.</p>

<p>For <strong>countWordsStartingWith</strong>, traverse the Trie using the prefix. The <code>cntPrefix</code> of the final node gives the number of inserted words having that prefix.</p>

<p>For <strong>erase</strong>, traverse the word and decrement <code>cntPrefix</code> for every node. At the final node, decrement <code>cntEndWith</code>.</p>

<p><strong>Key Observation:</strong></p>
<p>Unlike a normal Trie, we need <strong>frequency counters</strong> because the same word can be inserted multiple times. <code>cntEndWith</code> handles complete-word frequency, while <code>cntPrefix</code> handles prefix frequency.</p>

<p><strong>Time Complexity:</strong> <code>O(L)</code> for each operation, where <code>L</code> is the length of the word or prefix.</p>

<p><strong>Space Complexity:</strong> <code>O(N × L)</code> in the worst case, where <code>N</code> is the number of inserted words and <code>L</code> is their maximum length.</p>
