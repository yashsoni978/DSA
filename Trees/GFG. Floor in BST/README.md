<h2>Floor in BST</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Floor(k) = greatest value in BST
           that is <= k
</pre>

<p>Use the <strong>BST property</strong> to search efficiently.</p>

<pre>
If root->data == k
        ↓
    Floor = k

If root->data > k
        ↓
Go LEFT
(current node is too large)

If root->data < k
        ↓
Possible floor = root->data
Go RIGHT
(to find a larger valid value)
</pre>

<h3>Approach</h3>

<ul>
<li>Start from the root.</li>
<li>Maintain <code>floor = -1</code>.</li>
<li>If the current value equals <code>k</code>, return <code>k</code> immediately.</li>
<li>If the current value is greater than <code>k</code>, move left.</li>
<li>If the current value is smaller than <code>k</code>, store it as a possible floor and move right.</li>
<li>If we reach NULL, return the stored floor.</li>
</ul>

<h3>Example</h3>

<pre>
        10
       /  \
      7    15
     / \   / \
    2   8 11 16

k = 14

10 < 14
floor = 10
go RIGHT

15 > 14
go LEFT

11 < 14
floor = 11
go RIGHT

NULL

Answer = 11
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    int floor(Node* root, int k) {
        int floor = -1;

        while(root) {
            if(root-&gt;data == k) {
                return k;
            }
            else if(root-&gt;data &gt; k) {
                root = root-&gt;left;
            }
            else {
                floor = root-&gt;data;
                root = root-&gt;right;
            }
        }

        return floor;
    }
};
</pre>

<h3>Key Idea</h3>

<pre>
root &gt; k
   ↓
GO LEFT

root &lt; k
   ↓
Possible FLOOR
   ↓
GO RIGHT to find a larger valid value

root == k
   ↓
Return k
</pre>

<h3>Complexity</h3>

<pre>
TC: O(h)

Balanced BST → O(log n)
Skewed BST   → O(n)

SC: O(1)

Only a few variables are used.
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Binary Search / Floor & Ceil</p>

<p><strong>Key Idea:</strong> When root &lt; k, store root as a possible floor and move right to search for a larger valid value.</p>
