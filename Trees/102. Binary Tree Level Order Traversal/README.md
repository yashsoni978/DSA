<h2>102. Binary Tree Level Order Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the <strong>root</strong> of a binary tree, return the <strong>level order traversal</strong> of its nodes' values.</p>

<p>Level order traversal means visiting the nodes of the tree <strong>level by level</strong>, from left to right.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
root = [3,9,20,null,null,15,7]

<strong>Output:</strong>
[[3],[9,20],[15,7]]

<strong>Explanation:</strong>

        3
       / \
      9   20
         /  \
        15   7

Level 0: 3
Level 1: 9, 20
Level 2: 15, 7
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
root = [1]

<strong>Output:</strong>
[[1]]
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
root = []

<strong>Output:</strong>
[]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
  <li><code>-1000 ≤ Node.val ≤ 1000</code>.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>Use <strong>Breadth-First Search (BFS)</strong> with a queue.</p>

<p>The queue stores nodes that need to be processed. At every step, process all nodes currently present in the queue. These nodes belong to the <strong>same level</strong>.</p>

<ol>
  <li>If the root is <code>null</code>, return an empty result.</li>
  <li>Push the root into the queue.</li>
  <li>While the queue is not empty, store the current queue size.</li>
  <li>The current queue size represents the number of nodes in the current level.</li>
  <li>Process exactly that many nodes.</li>
  <li>Add each node's value to the current level.</li>
  <li>Push its left and right children into the queue for the next level.</li>
  <li>Add the completed level to the answer.</li>
</ol>

<p><strong>Example:</strong></p>

<pre>
        3
       / \
      9   20
         /  \
        15   7

Queue initially:
[3]

Process level 0:
current level = [3]

Queue:
[9, 20]

Process level 1:
current level = [9, 20]

Queue:
[15, 7]

Process level 2:
current level = [15, 7]
</pre>

<p><strong>Important:</strong></p>

<p>The key idea is to save the queue size before processing a level:</p>

<pre>
int size = q.size();

for(int i = 0; i &lt; size; i++) {
    // process current level
}
</pre>

<p>This ensures that nodes added during the current level are processed only in the <strong>next level</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code> for the queue and result.</p>
