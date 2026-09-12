<h2>460. LFU Cache</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Design a cache that supports <code>get()</code> and <code>put()</code> in <strong>O(1)</strong> average time. When the cache is full, remove the <strong>Least Frequently Used (LFU)</strong> key. If multiple keys have the same frequency, remove the <strong>Least Recently Used (LRU)</strong> key among them.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
cache = LFUCache(2)
put(1,1)
put(2,2)
get(1)
put(3,3)

<strong>Output:</strong>
get(2) = -1 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use <strong>Hash Maps + Doubly Linked Lists</strong>.</p>

<ul>
<li><code>key → node</code> map gives direct access to each key.</li>
<li><code>frequency → DLL</code> stores all keys having the same frequency.</li>
<li>Each node stores <code>key, value, frequency</code>.</li>
<li>On <code>get()</code> or updating with <code>put()</code>, increase its frequency and move it to the corresponding list.</li>
<li>Maintain <code>minFreq</code> to know the lowest frequency currently present.</li>
<li>If frequencies are equal, remove the <strong>least recently used</strong> node from that frequency's list.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>LFU needs two levels of ordering: <strong>frequency first</strong>, then <strong>recency</strong> for ties.</p>

<pre>
keyMap → key → node
freqMap → frequency → DLL
minFreq → minimum frequency
</pre>

<p><strong>Time Complexity:</strong> <code>O(1)</code> average for <code>get()</code> and <code>put()</code></p>
<p><strong>Space Complexity:</strong> <code>O(capacity)</code></p>
