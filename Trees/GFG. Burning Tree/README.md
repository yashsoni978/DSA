<h2>Burning Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given a target node, find the <strong>minimum time required to burn the entire binary tree</strong>.</p>

<p>Fire spreads in one second to:</p>

<pre>
1. Left child
2. Right child
3. Parent
</pre>

<h3>Approach</h3>

<ul>
<li>First create a <strong>parent map</strong> using BFS.</li>
<li>Find the target node using its unique value.</li>
<li>Now treat the tree like an <strong>undirected graph</strong>.</li>
<li>Start BFS from the target node.</li>
<li>At every second, fire can spread to the left child, right child, or parent.</li>
<li>Use a <code>visited</code> map/set to prevent burning the same node again.</li>
<li>Whenever at least one new node catches fire, increase the time by <code>1</code>.</li>
<li>When BFS finishes, the accumulated time is the answer.</li>
</ul>

<h3>Key Idea</h3>

<pre>
Binary Tree
     ↓
Create Parent Map
     ↓
Tree becomes an Undirected Graph
     ↓
BFS from Target
     ↓
Each BFS level = 1 second
     ↓
Last level = Burning Time
</pre>

<h3>Example</h3>

<pre>
        1
       / \
      2   3
     / \ / \
    4  5 6  7

Target = 2

0 sec → 2
1 sec → 4, 5, 1
2 sec → 3
3 sec → 6, 7

Answer = 3
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Every node is visited at most once.

SC: O(n)

Parent map + visited map + queue can store O(n) nodes.
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Parent Mapping / Graph</p>

<p><strong>Key Idea:</strong> Create parent pointers to allow upward movement, then perform BFS from the target. Each BFS level represents one second of burning.</p>
