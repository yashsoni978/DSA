/*Children Sum Property – Concept

For every non-leaf node:
root->data == left child value + right child value

- NULL child is considered 0.
- Leaf nodes are automatically valid.
- For each node:
  1. Get left and right child values (0 if NULL).
  2. Check root->data == left + right.
  3. Recursively check the left and right subtrees.
- If any node fails the condition → false.
- If all nodes satisfy it → true.

Key Idea:
Check the condition at the current node + recursively validate both subtrees.*/

/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(!root) return true;
        if(!root -> left && !root -> right) return true;
        int left = 0, right = 0;
        if(root -> left) left = root -> left -> data;
        if(root -> right) right = root -> right -> data;
        if((root -> data == left + right) && isSumProperty(root -> left) && isSumProperty(root -> right)) return true;
        return false;
    }
};


/*TC: O(n)

Every node is visited exactly once.

SC: O(h)

The recursion stack stores at most h nodes,
where h is the height of the tree.

Worst case: O(n) for a skewed tree.*/