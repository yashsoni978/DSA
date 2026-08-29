<h2>103. Binary Tree Zigzag Level Order Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the root of a binary tree, return its <strong>zigzag level order traversal</strong>.</p>

<p>In zigzag traversal, the direction alternates for every level:</p>

<pre>
Level 1 → Left → Right
Level 2 → Right → Left
Level 3 → Left → Right
...
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>BFS</strong> with a <code>queue</code>.</li>
<li>Process the tree level by level using <code>queue.size()</code>.</li>
<li>Maintain a boolean variable to track the current direction.</li>
<li>If the direction is left-to-right, store values normally.</li>
<li>If the direction is right-to-left, reverse the current level before adding it to the answer.</li>
<li>Toggle the direction after processing every level.</li>
</ul>

<h3>Why This Works</h3>

<p>BFS naturally processes the tree one level at a time. By alternating the direction after each level, we get the required zigzag order.</p>

<pre>
        3
       / \
      9  20
         / \
        15  7

Output:
[3]
[20,9]
[15,7]
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited once.</p>

<p><strong>Space:</strong> <code>O(n)</code></p>

<p>The queue and current level can contain up to <code>O(n)</code> nodes.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Queue / Zigzag Traversal</p>

<p><strong>Key Idea:</strong> Perform normal level order BFS and alternate the traversal direction after every level.</p>
