<h2>146. LRU Cache</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Design a data structure that supports <code>get()</code> and <code>put()</code> in <strong>O(1)</strong> time. When the cache reaches its capacity, remove the <strong>Least Recently Used (LRU)</strong> item.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
LRUCache cache = new LRUCache(2);
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);
cache.put(3, 3);

<strong>Output:</strong>
cache.get(2) = -1 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use a <strong>Doubly Linked List + Hash Map</strong>.</p>

<ul>
<li>The <strong>Hash Map</strong> stores <code>key → node</code> for <code>O(1)</code> lookup.</li>
<li>The <strong>DLL</strong> maintains the usage order.</li>
<li>Front = <strong>Most Recently Used (MRU)</strong>.</li>
<li>Back = <strong>Least Recently Used (LRU)</strong>.</li>
<li>On <code>get()</code> → move the node to the front.</li>
<li>On <code>put()</code> → add/update and move to front.</li>
<li>If capacity is exceeded → remove the node from the back.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>The Hash Map gives <strong>O(1) access</strong>, while the Doubly Linked List gives <strong>O(1) insertion, deletion, and moving</strong> of nodes.</p>

<pre>
Hash Map → find node in O(1)
DLL      → update usage order in O(1)
</pre>

<p><strong>Time Complexity:</strong> <code>O(1)</code> for <code>get()</code> and <code>put()</code></p>
<p><strong>Space Complexity:</strong> <code>O(capacity)</code></p>
