<h2>100. Same Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the roots of two binary trees <code>p</code> and <code>q</code>, determine whether the two trees are <strong>identical</strong>.</p>

<p>Two trees are the same if they have the same structure and every corresponding node has the same value.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS with recursion</strong>.</li>
<li>If both nodes are <code>null</code>, they are equal.</li>
<li>If only one node is <code>null</code>, the trees are different.</li>
<li>If the values of the current nodes are different, return <code>false</code>.</li>
<li>Recursively compare the left subtrees and right subtrees.</li>
<li>The trees are the same only if both subtrees are also the same.</li>
</ul>

<h3>Why This Works</h3>

<p>For every pair of corresponding nodes, we check both:</p>

<pre>
Same value
+
Same left and right subtree structure
</pre>

<p>If any corresponding nodes differ, the trees cannot be the same.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every corresponding node is visited at most once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion / Tree Comparison</p>

<p><strong>Key Idea:</strong> Compare corresponding nodes recursively. Both must have the same value and identical left and right subtree structures.</p>
