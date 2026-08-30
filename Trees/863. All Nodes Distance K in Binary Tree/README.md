<h2>863. All Nodes Distance K in Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a binary tree, a <strong>target node</strong>, and an integer <code>k</code>, return all nodes whose distance from the target is exactly <code>k</code>.</p>

<h3>Approach</h3>

<p>The main problem is that a binary tree only gives us links from <strong>parent → child</strong>. From the target, we also need to move <strong>up to the parent</strong>.</p>

<p>So use two steps:</p>

<ul>
<li><strong>Step 1:</strong> Create a <code>parent</code> map using DFS/BFS.</li>
<li><strong>Step 2:</strong> Start BFS from <code>target</code>.</li>
</ul>

<p>From every node, we can now move in <strong>3 directions</strong>:</p>

<pre>
1. left child
2. right child
3. parent
</pre>

<p>Use a <code>visited</code> set so we don't move back and forth between a node and its parent.</p>

<h3>Key Idea</h3>

<pre>
              3
             / \
            5   1
           / \
          6   2

Target = 5

Tree → Graph

5 can move to:
    left  → 6
    right → 2
    parent → 3

Then BFS level-by-level.

Distance 0 → 5
Distance 1 → 6, 2, 3
Distance 2 → ...
</pre>

<p><strong>Important:</strong> Once we reach BFS level <code>k</code>, all nodes currently in the queue are exactly the answer.</p>

<h3>Pattern</h3>

<pre>
Binary Tree
     ↓
Create Parent Map
     ↓
Treat Tree as Undirected Graph
     ↓
BFS from Target
     ↓
Stop at Distance K
</pre>

<p><strong>Key Idea:</strong> Create parent pointers so that from any node we can move left, right, or up to the parent, then use BFS to find nodes exactly K edges away.</p>
