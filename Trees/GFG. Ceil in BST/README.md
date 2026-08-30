<h2>Ceil in BST</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Ceil(x) = smallest value in BST
         that is >= x
</pre>

<p>Use the <strong>BST property</strong> to search efficiently.</p>

<pre>
If root->data == x
        ↓
      Ceil = x

If root->data < x
        ↓
Go RIGHT
(current node is too small)

If root->data > x
        ↓
Possible ceil = root->data
Go LEFT
(to find a smaller valid value)
</pre>

<h3>Approach</h3>

<ul>
<li>Start from the root.</li>
<li>Maintain <code>ceil = -1</code>.</li>
<li>If the current value equals <code>x</code>, return <code>x</code> immediately.</li>
<li>If the current value is smaller than <code>x</code>, move right.</li>
<li>If the current value is greater than <code>x</code>, store it as a possible ceil and move left.</li>
<li>If we reach NULL, return the stored ceil.</li>
</ul>

<h3>Example</h3>

<pre>
        10
       /  \
      5    11
          /
         7
          \
           8

x = 6

10 > 6
ceil = 10
go LEFT

5 < 6
go RIGHT

7 > 6
ceil = 7
go LEFT

NULL

Answer = 7
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    int findCeil(Node* root, int x) {
        int ceil = -1;

        while(root) {
            if(root-&gt;data == x) {
                return x;
            }
            else if(root-&gt;data &lt; x) {
                root = root-&gt;right;
            }
            else {
                ceil = root-&gt;data;
                root = root-&gt;left;
            }
        }

        return ceil;
    }
};
</pre>

<h3>Key Idea</h3>

<pre>
root &lt; x
   ↓
GO RIGHT

root &gt; x
   ↓
Possible CEIL
   ↓
GO LEFT to find a smaller valid value

root == x
   ↓
Return x
</pre>

<h3>Complexity</h3>

<pre>
TC: O(h)

We follow only one path from root to leaf.

Balanced BST → O(log n)
Skewed BST   → O(n)

SC: O(1)

Only a few variables are used.
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Binary Search / Floor & Ceil</p>

<p><strong>Key Idea:</strong> When root &gt; x, store root as a possible ceil and move left to search for a smaller valid value.</p>
