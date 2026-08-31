<h2>653. Two Sum IV - Input is a BST</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<p>We need to find whether there exist <strong>two different nodes</strong> whose values add up to <code>k</code>.</p>

<pre>
node1 + node2 = k
</pre>

<p>Since this is a BST, its inorder traversal is sorted.</p>

<pre>
BST
 ↓
Inorder
 ↓
Sorted Array
 ↓
Two Pointer
</pre>

<h3>Approach</h3>

<ul>
<li>Perform inorder traversal and store all node values in a vector.</li>
<li>The vector is automatically sorted because it comes from a BST.</li>
<li>Use two pointers: <code>left</code> at the beginning and <code>right</code> at the end.</li>
<li>If <code>arr[left] + arr[right] == k</code>, return <code>true</code>.</li>
<li>If the sum is smaller than <code>k</code>, move <code>left</code> forward.</li>
<li>If the sum is greater than <code>k</code>, move <code>right</code> backward.</li>
</ul>

<h3>Code</h3>

<pre>
class Solution {
private:
    void inorder(TreeNode* root, vector&lt;int&gt;&amp; arr) {
        if(!root) return;

        inorder(root-&gt;left, arr);
        arr.push_back(root-&gt;val);
        inorder(root-&gt;right, arr);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        vector&lt;int&gt; arr;

        // BST inorder = sorted order
        inorder(root, arr);

        int left = 0;
        int right = arr.size() - 1;

        while(left &lt; right) {
            int sum = arr[left] + arr[right];

            if(sum == k)
                return true;

            if(sum &lt; k)
                left++;
            else
                right--;
        }

        return false;
    }
};
</pre>

<h3>Example</h3>

<pre>
        5
       / \
      3   6
     / \   \
    2   4   7

k = 9
</pre>

<p>Inorder traversal:</p>

<pre>
[2, 3, 4, 5, 6, 7]
</pre>

<p>Two pointers:</p>

<pre>
2 + 7 = 9
↑       ↑
L       R

Found!
</pre>

<p>Therefore:</p>

<pre>
return true
</pre>

<h3>Why Two Pointers Work?</h3>

<pre>
Array is sorted:

[2, 3, 4, 5, 6, 7]
 ↑                 ↑
left              right

If sum &lt; k:
    Need a bigger sum
    → move LEFT forward

If sum &gt; k:
    Need a smaller sum
    → move RIGHT backward
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Inorder traversal → O(n)
Two pointer       → O(n)

Total → O(n)

SC: O(n)

Vector stores all n nodes.
Recursion stack → O(h)
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Inorder Traversal / Sorted Array / Two Pointers</p>

<p><strong>Key Idea:</strong> Convert the BST into its sorted inorder array, then apply the standard Two Sum two-pointer technique.</p>
