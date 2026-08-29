<h2>101. Symmetric Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, check whether the tree is <strong>symmetric around its center</strong>. :contentReference[oaicite:0]{index=0}</p>

<h3>Approach</h3>

<ul>
<li>Compare the <strong>left subtree</strong> and <strong>right subtree</strong> as mirror images.</li>
<li>For two nodes <code>left</code> and <code>right</code>:</li>
<li>If both are <code>NULL</code>, they are symmetric.</li>
<li>If only one is <code>NULL</code>, they are not symmetric.</li>
<li>If their values are different, return <code>false</code>.</li>
<li>Compare <code>left->left</code> with <code>right->right</code>.</li>
<li>Compare <code>left->right</code> with <code>right->left</code>.</li>
</ul>

<h3>Key Idea</h3>

<pre>
        1
       / \
      2   2
     / \ / \
    3  4 4  3

Compare:

left->left   ↔ right->right
left->right  ↔ right->left
</pre>

<p>The important part is that we compare <strong>opposite/mirror children</strong>, not children on the same side. :contentReference[oaicite:1]{index=1}</p>

<h3>Complexity</h3>

<p><strong>TC: O(n)</strong></p>

<p>Each node is visited at most once.</p>

<p><strong>SC: O(h)</strong></p>

<p>Recursion stack uses O(h), where <code>h</code> is the height of the tree. In the worst case, <code>h = n</code>.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion / Mirror Comparison</p>

<p><strong>Key Idea:</strong> A tree is symmetric if its left and right subtrees are mirror images of each other.</p>
