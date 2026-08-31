<h2>Predecessor and Successor</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<p>In a BST:</p>

<pre>
Inorder Traversal = Sorted Order
</pre>

<p>Therefore:</p>

<pre>
Predecessor = Largest value &lt; key
Successor   = Smallest value &gt; key
</pre>

<h3>Approach</h3>

<ul>
<li>Start from the root.</li>
<li>If <code>curr-&gt;data &lt; key</code>, then <code>curr</code> can be a predecessor.</li>
<li>Move to the <strong>right</strong> to find a larger value that is still smaller than the key.</li>
<li>If <code>curr-&gt;data &gt; key</code>, then <code>curr</code> can be a successor.</li>
<li>Move to the <strong>left</strong> to find a smaller value that is still greater than the key.</li>
<li>If <code>curr-&gt;data == key</code>, find the predecessor from the rightmost node of the left subtree and the successor from the leftmost node of the right subtree.</li>
</ul>

<h3>Example</h3>

<pre>
        50
       /  \
     30    70
    / \    / \
   20 40  60 80

key = 65
</pre>

<pre>
50 &lt; 65
→ predecessor candidate = 50
→ go RIGHT

70 &gt; 65
→ successor candidate = 70
→ go LEFT

60 &lt; 65
→ predecessor candidate = 60
→ go RIGHT

NULL
</pre>

<p>Therefore:</p>

<pre>
Predecessor = 60
Successor   = 70
</pre>

<h3>When Key Exists</h3>

<pre>
        50
       /  \
     30    70
    / \    / \
   20 40  60 80

key = 50
</pre>

<p>For the predecessor:</p>

<pre>
Go to LEFT subtree
        ↓
Find RIGHTMOST node
        ↓
40
</pre>

<p>For the successor:</p>

<pre>
Go to RIGHT subtree
        ↓
Find LEFTMOST node
        ↓
60
</pre>

<h3>Important BST Rules</h3>

<pre>
curr &lt; key
    ↓
Possible predecessor
    ↓
Go RIGHT


curr &gt; key
    ↓
Possible successor
    ↓
Go LEFT


curr == key
    ↓
Pred = rightmost of LEFT subtree
Succ = leftmost of RIGHT subtree
</pre>

<h3>Complexity</h3>

<pre>
TC: O(h)

SC: O(1)

where h = height of the BST.

Balanced BST → O(log n)
Skewed BST   → O(n)
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Inorder Property / Predecessor / Successor</p>

<p><strong>Key Idea:</strong> For predecessor, keep moving right whenever the current value is smaller than the key. For successor, keep moving left whenever the current value is greater than the key.</p>
